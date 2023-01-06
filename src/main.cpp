#include <iostream>
#include "Graph.h"
#include "Airline.h"

using namespace std;

Graph flightManager;

void showMenu() {
    cout << "\n";
    cout << "---------------------- Menu ----------------------" << endl;
    cout << "| 1- Best flight possible                        |" << endl;
    cout << "| 2- Airport info                                |" << endl;
    cout << "| 3- Book a flight                               |" << endl;
    cout << "| 0- Quit                                        |" << endl;
    cout << "--------------------------------------------------" << endl;
}


void showBestFlightMenu() {
    cout << "\n--------------------------------------------------" << endl;
    cout << "| 1- Pesquisar por aeroporto                     |" << endl;
    cout << "| 2- Pesquisar por cidade                        |" << endl;
    cout << "--------------------------------------------------" << endl;
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

/*
    while (it != airports.end()) {
        cout << it->second->getCode() << " " << it->second->getName() << " " << it->second->getCity() << " "
             << it->second->getCountry() << " "
             << it->second->getLatitude() << " " << it->second->getLongitude() << endl;
        it++;
    }
*/
/*
    while (itAirlines != airlines.end()) {
        cout << itAirlines->second->getCode() << " " << itAirlines->second->getName() << " "
             << itAirlines->second->getCallSign()
             << " " << itAirlines->second->getCountry() << endl;
        itAirlines++;
    }
*/

}


int main() {
    flightManager.readFiles("airports.csv", "airlines.csv", "flights.csv");
    //test();
    short entry = 0;
    short type = 0;
    string src, dest;

    while (entry != -1) {
        showMenu();
        cin >> entry;
        cout << "\n";

        switch (entry) {
            case 1:
                showBestFlightMenu();
                cin >> type;
                cout << "\n";
                cout << "Flight from: ";
                cin >> src;
                cout << "Flight to: ";
                cin >> dest;
                cout << "\n";
                if(type==1) {
                    flightManager.bestTravel(flightManager.getAirports()[src], flightManager.getAirports()[dest]);
                }
                if(type==2) {
                    flightManager.bestTravelCity(src, dest);
                }

                break;
            case 2:
                break;
            case 3:
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