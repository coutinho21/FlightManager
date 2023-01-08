#include <iostream>
#include "Graph.h"
#include "Airline.h"

using namespace std;

Graph flightManager;

void showMenu() {
    cout << "\n";
    cout << "---------------------- Menu -----------------------" << endl;
    cout << "| 1- Best flight possible                         |" << endl;
    cout << "| 2- Airport info                                 |" << endl;
    cout << "| 3- Book a flight                                |" << endl;
    cout << "| 0- Quit                                         |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pick an option: ";
}

void showBestFlightMenu() {
    cout << "\n";
    cout << "---------------------------------------------------" << endl;
    cout << "| 1- Search by airport                            |" << endl;
    cout << "| 2- Search by city                               |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pick an option: ";
}

void showAirportInfoMenu() {
    cout << "\n";
    cout << "---------------------- Menu -----------------------" << endl;
    cout << "| 1- List of Flights                              |" << endl;
    cout << "| 2- Number of Flights                            |" << endl;
    cout << "| 3- List of Airlines                             |" << endl;
    cout << "| 4- Number of Airlines                           |" << endl;
    cout << "| 5- Number of Reachable countries                |" << endl;
    cout << "| 6- Number of Reachable cities                   |" << endl;
    cout << "| 0- Go back to menu                              |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pick an option: ";
}

void pickAirline() {
    cout << "\n";
    cout << "---------------------------------------------------" << endl;
    cout << "| 1- Fly using one airline                        |" << endl;
    cout << "| 2- Fly using several airlines                   |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pick an option: ";
}

void pickNumFlights() {
    cout << "\n";
    cout << "---------------------------------------------------" << endl;
    cout << "| 1- Find Reachable cities within one flight      |" << endl;
    cout << "| 2- Find Reachable cities within multiple flight |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pick an option: ";
}

void test() {

    auto airports = flightManager.getAirports();
    auto airlines = flightManager.getAirlines();
    auto it = airports.begin();
    auto itAirlines = airlines.begin();
    auto it2 = airports.begin();
    auto it3 = airports.begin();
    it3++;

    cout << it2->second->getName() << " (" << it2->second->getCode() << ") to " << it3->second->getName() << " ("
         << it3->second->getCode() << ')' << endl;
    double d = Graph::calculateDistance(it2->second, it3->second);
    cout << d << " kilometers" << endl;

    while (it != airports.end()) {
        for (Flight flight: it->second->getFlights()) {
            cout << "Flight from " << it->second->getCode() << " - " << it->second->getName() << " to "
                 << flight.getDestination()->getCode() << " - " << flight.getDestination()->getName()
                 << " with airline " << flight.getAirline()->getCode() << " - " << flight.getAirline()->getName()
                 << endl;
        }
        it++;
    }

    while (it != airports.end()) {
        cout << it->second->getCode() << " " << it->second->getName() << " " << it->second->getCity() << " "
             << it->second->getCountry() << " "
             << it->second->getLatitude() << " " << it->second->getLongitude() << endl;
        it++;
    }

    while (itAirlines != airlines.end()) {
        cout << itAirlines->second->getCode() << " " << itAirlines->second->getName() << " "
             << itAirlines->second->getCallSign()
             << " " << itAirlines->second->getCountry() << endl;
        itAirlines++;
    }
}


int main() {
    flightManager.readFiles("airports.csv", "airlines.csv", "flights.csv");
    short entry = 0, type = 0;
    string src, dest, code, city;
    int numberOfFlights, numberOfAirlines, numberOfCities, numberOfCountries, response;
    vector<string> airlineCodes;

    while (entry != -1) {
        showMenu();
        cin >> entry;
        cout << "\n";

        switch (entry) {
            case 1:
                showBestFlightMenu();
                cin >> type;
                cout << "Flight from: ";
                getline(cin >> ws, src);
                for (int i = 0; i < src.size(); i++) src[i] = toupper(src[i]);
                cout << "Flight to: ";
                getline(cin >> ws, dest);
                for (int i = 0; i < dest.size(); i++) dest[i] = toupper(dest[i]);
                if (type == 1)
                    flightManager.bestTravelAirport(flightManager.getAirports()[src],
                                                    flightManager.getAirports()[dest]);
                if (type == 2)
                    flightManager.bestTravelCity(src, dest);
                break;
            case 2:
                type = 0;
                cout << "Airport Code: ";
                getline(cin >> ws, code);
                for (auto &ch: code) ch = toupper(ch);
                city = flightManager.getAirports()[code]->getCity();
                while (type != -1) {
                    showAirportInfoMenu();
                    cin >> type;
                    switch (type) {
                        case 1:
                            cout << "List of Flights from " << code << " (" << city << "):" << endl;
                            cout << "\n";
                            flightManager.listFlights(code);
                            break;
                        case 2:
                            numberOfFlights = flightManager.getNumberOfFlightsForAirport(code);
                            cout << endl;
                            if (numberOfFlights == -1)
                                cout << "Airport not found!" << endl;
                            else
                                cout << "Number of flights: " << numberOfFlights << endl;
                            break;
                        case 3:
                            cout << "Airlines with flights from " << code << ":" << endl;
                            cout << "\n";
                            flightManager.listAirlines(code);
                            break;
                        case 4:
                            numberOfAirlines = flightManager.getNumberOfAirlinesAirport(code);
                            cout << endl;
                            if (numberOfAirlines == -1)
                                cout << "Airport not found!" << endl;
                            else
                                cout << "Number of airlines: " << numberOfAirlines << endl;
                            break;
                        case 5:
                            numberOfCountries = flightManager.getNumberOfReachableCountries(code);
                            if (numberOfCountries == -1)
                                cout << "Airport not found!" << endl;
                            else
                                cout << "Number of reachable countries: " << numberOfCountries << endl;
                            break;
                        case 6:
                            pickNumFlights();
                            cin >> response;
                            if(response == 1){
                                numberOfCities = flightManager.getNumberOfReachableCities(code);
                                if (numberOfCities == -1)
                                    cout << "Airport not found!" << endl;
                                else
                                    cout << "Number of reachable cities: " << numberOfCities << endl;
                            }
                            else if(response == 2){
                                cout << "Number of flights: ";
                                cin >> numberOfFlights;
                                numberOfCities = flightManager.multipleFlightsReachableCities(code, numberOfFlights);
                                if (numberOfCities == -1)
                                    cout << "Airport not found!" << endl;
                                else
                                    cout << "Number of reachable cities: " << numberOfCities << endl;
                            }
                            break;
                        case 0:
                            type = -1;
                            break;
                        default:
                            cout << "\nChoose a valid option." << endl;
                            break;
                    }
                }
                break;
            case 3:
                cout << "=========================" << endl;
                cout << "||                     ||" << endl;
                cout << "||  Book your flight!  ||" << endl;
                cout << "||                     ||" << endl;
                cout << "=========================" << endl;
                cout << "\n";
                cout << "Select Origin Airport: ";
                getline(cin >> ws, src);
                for (int i = 0; i < src.size(); i++) src[i] = toupper(src[i]);
                cout << "Select Destination Airport: ";
                getline(cin >> ws, dest);
                for (int i = 0; i < dest.size(); i++) dest[i] = toupper(dest[i]);
                pickAirline();
                cin >> type;
                cout << "\n";
                switch(type){
                    case 1:
                        cout << "Select Airline: ";
                        getline(cin >> ws, code);
                        for (int i = 0; i < code.size(); i++) code[i] = toupper(code[i]);
                        flightManager.oneAirlineBestTravel(flightManager.getAirports()[src], flightManager.getAirports()[dest], code);
                        break;
                    case 2:
                        cout << "How many airlines would you like to use? ";
                        cin >> response;
                        cout << "\n";
                        cout << "Select First Airline: ";
                        getline(cin >> ws, code);
                        for (int i = 0; i < code.size(); i++) code[i] = toupper(code[i]);
                        airlineCodes.push_back(code);
                        for(int i = 1; i < response; i++){
                            cout << "Select Another Airline: ";
                            getline(cin >> ws, code);
                            for (int i = 0; i < code.size(); i++) code[i] = toupper(code[i]);
                            airlineCodes.push_back(code);
                        }
                        flightManager.multipleAirlinesPrint(flightManager.getAirports()[src], flightManager.getAirports()[dest], airlineCodes);
                }
                break;
            case 0:
                entry = -1;
                break;
            default:
                cout << "\nChoose a valid option." << endl;
                break;
        }
    }

    return 0;
}