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


void Graph::bestTravel( Airport* origin,  Airport* destination) {

    for (auto it: airports) it.second->setVisited(false);
    for(auto it : airports) it.second->setScales({});
    queue<Airport*> q; // queue of unvisited nodes
    q.push(origin);
    origin->setVisited(true);
    origin->setDistance(0);
    while (!q.empty()) { // while there are still unvisited nodes
        Airport* u = q.front();
        q.pop();
        for (auto e: u->getFlights()) {
            Airport* w = e.getDestination();
            vector<Airport*> current;

            if (!w->isVisited()) {
                q.push(w);
                w->setVisited(true);
                double dist = calculateDistance(w,u);
                w->setDistance(u->getDistance()+dist);
                for(auto scale : u->getScales()){
                    current.push_back(scale);
                }
                current.push_back(u);
                w->setScales(current);
            }
            if(w==destination){
                cout << "From " << origin->getName()  << " - " << origin->getCode() << " to " << destination->getName() << " - " << destination->getCode();
                cout << "\nNumber of flights: "<< w->getScales().size() <<endl;
                cout << "Path: ";
                for(auto scale : w->getScales()){
                    cout << scale->getName() << " - " << scale->getCode() << " ---> ";
                }
                cout << destination->getName()  << " - " <<destination->getCode()  << endl;

                return;
            }
        }
    }

}
