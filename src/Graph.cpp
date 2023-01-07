#include "Graph.h"
#include <queue>
#include <fstream>
#include <sstream>


void Graph::readFiles(const string &file1, const string &file2, const string &file3) {
    std::fstream in1, in2, in3;
    std::string token;
    Airport *currentAirport;
    Airline *currentAirline;


    in1.open(file1);
    in2.open(file2);
    in3.open(file3);

    std::getline(in1, token, '\n'); //step var names ahead
    std::getline(in2, token, '\n');  //step var names ahead
    std::getline(in3, token, '\n');  //step var names ahead


    //reads airports.csv
    while (std::getline(in1, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;
        currentAirport = new Airport();


        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);

        }

        currentAirport->setCode(temp[0]);
        currentAirport->setName(temp[1]);
        currentAirport->setCity(temp[2]);
        currentAirport->setCountry(temp[3]);
        currentAirport->setLatitude(stod(temp[4]));
        currentAirport->setLongitude(stod(temp[5]));

        airports[currentAirport->getCode()] = currentAirport;
        n++;
    }


    //read airlines.csv
    while (std::getline(in2, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;
        currentAirline = new Airline();

        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        currentAirline->setCode(temp[0]);
        currentAirline->setName(temp[1]);
        currentAirline->setCallSign(temp[2]);
        currentAirline->setCountry(temp[3]);

        airlines[currentAirline->getCode()] = currentAirline;
    }


    //reads flights.csv
    while (std::getline(in3, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;
        Airport *origin, *destination;
        Airline *airline;

        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        origin = airports[temp[0]];
        destination = airports[temp[1]];
        airline = airlines[temp[2]];
        origin->addFlight(destination, airline);
    }

}

unordered_map<string, Airport *> Graph::getAirports() {
    return airports;
}

unordered_map<string, Airline *> Graph::getAirlines() {
    return airlines;
}


double Graph::calculateDistance(Airport *a1, Airport *a2) {
    double lat1 = a1->getLatitude();
    double lat2 = a2->getLatitude();
    double lon1 = a1->getLongitude();
    double lon2 = a2->getLongitude();
    int earthRadius = 6371000; // metres
    double latitudeSource = lat1 * M_PI / 180;
    double latitudeDestination = lat2 * M_PI / 180;
    double latitudeDiff = (lat2 - lat1) * M_PI / 180;
    double longitudeDiff = (lon2 - lon1) * M_PI / 180;

    double a = sin(latitudeDiff / 2) * sin(latitudeDiff / 2) +
               cos(latitudeSource) * cos(latitudeDestination) *
               sin(longitudeDiff / 2) * sin(longitudeDiff / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c / 1000; // in km
}


Airport* Graph::bestTravel(Airport *origin, Airport *destination) {

    for (auto it: airports) it.second->setVisited(false);
    for (auto it: airports) it.second->setScales({});
    queue<Airport *> q; // queue of unvisited nodes
    q.push(origin);
    origin->setVisited(true);
    origin->setDistance(0);
    while (!q.empty()) { // while there are still unvisited nodes
        Airport *u = q.front();
        q.pop();
        for (auto e: u->getFlights()) {
            Airport *w = e.getDestination();
            vector<pair<Airport*, Airline*>> current;
            pair<Airport*, Airline*> curr;
            if (!w->isVisited()) {
                q.push(w);
                w->setVisited(true);
                double dist = calculateDistance(w, u);
                w->setDistance(u->getDistance() + dist);
                for (auto scale: u->getScales())
                    current.push_back(scale);
                curr.first = u;
                curr.second = e.getAirline();
                current.push_back(curr);
                w->setScales(current);
            }
            if (w == destination)
                return w;
        }
    }
    Airport *empty{};
    return empty;
}

void Graph::bestTravelCity(const string& origin, const string& destination) {
    vector<Airport *> originA;
    vector<Airport *> destinationA;
    int min = INT_MAX;

    vector<Airport *> resOrigin;
    vector<Airport *> resDestination;
    vector<Airport *> res;


    for (const auto& airport: airports) {
        if (airport.second->getCity() == origin)
            originA.push_back(airport.second);

        if (airport.second->getCity() == destination)
            destinationA.push_back(airport.second);
    }

    for (auto pOrigin: originA) {
        for (auto pDestination: destinationA) {
            Airport *check = bestTravel(pOrigin, pDestination);
            if (check->getScales().size() < min) {
                resOrigin.clear();
                resDestination.clear();
                resOrigin.push_back(pOrigin);
                resDestination.push_back(pDestination);
                min = check->getScales().size();
            }
            if (check->getScales().size() == min) {
                resOrigin.push_back(pOrigin);
                resDestination.push_back(pDestination);
            }
        }
    }

    cout << "\nBest flights options from " << origin << " to " << destination << ": " << endl << "\n";
    for (int i = 0; i < resOrigin.size(); i++) {
        res.push_back(bestTravel(resOrigin[i], resDestination[i]));
        cout << "From " << resOrigin[i]->getName() << " - " << resOrigin[i]->getCode() << " to "
             << resDestination[i]->getName() << " - " << resDestination[i]->getCode();
        cout << "\nNumber of flights: " << res.front()->getScales().size() << endl;
        cout << "Path: ";
        for (auto scale: res[i]->getScales())
            cout << scale.first->getName() << " - " << scale.first->getCode() << " ---> ";
        cout << resDestination[i]->getName() << " - " << resDestination[i]->getCode() << endl << "\n";
    }
}

void Graph::bestTravelAirport(Airport *origin, Airport *destination) {
    Airport *w = bestTravel(origin, destination);
    cout << "Flight from " << origin->getName() <<  " - " <<  origin->getCode() << " to "
    << destination->getName() << " - " <<  destination->getCode() << endl;
    cout << "Number of flights: " << w->getScales().size() << endl;
    cout << "Path: ";
    for(auto scale : w->getScales()){
        cout << scale.first->getName() << " - " << scale.first->getCode() <<
        " --(flying with " << scale.second->getName() << " - " << scale.second->getCode() << ")--> ";
    }
    cout << destination->getName() << " - " << destination->getCode() << endl;
}
