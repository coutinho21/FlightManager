#include <iostream>
#include "Airport.h"
#include "FlightManager.h"

using namespace std;

FlightManager obj;

void showMenu(){
    cout << "\n";
    cout << "---------------------- Menu ----------------------" << endl;
    cout << "| 1- Best flight possible                        |" << endl;
    cout << "| 2- Airport info                                |" << endl;
    cout << "| 3- Book a flight                               |" << endl;
    cout << "| 0- Quit                                        |" << endl;
    cout << "--------------------------------------------------" << endl;
}

void test() {
    typedef unordered_set<Airport, hAF, eAF>::iterator iteratorH;

    auto airports = obj.getAirports();
    auto airlines = obj.getAirlines();
    auto flights = obj.getFlights();
    auto it = airports.begin();
    auto itAirlines = airlines.begin();
    auto it2 = airports.begin();
    auto it3 = airports.begin(); it3++;

    cout << it2->getName() << " (" << it2->getCode() << ") to " << it3->getName() << " (" << it3->getCode() << ')' << endl;
    double d = Graph::calculateDistance(*it2, *it3);
    cout << d << " kilometers" << endl;


    /**
    while (it != airports.end()) {
        cout << it->getCode() << " " << it->getName() << " " << it->getCity() << " " << it->getCountry() << " "
                  << it->getLatitude() << " " << it->getLongitude() << endl;
        it++;
    }
    */

    /**
    while (itAirlines != airlines.end()) {
        cout << itAirlines->getCode() << " " << itAirlines->getName() << " " << itAirlines->getCallSign()
        << " " << itAirlines->getCountry() << endl;
        itAirlines++;
    }
    */

    flights.print();
}

void bestTravel(const string& origin, const string& destination){

}

int main() {
    obj.readFiles( "airports.csv","airlines.csv", "flights.csv");
    short entry = 0;
    string src, dest;
    test();

    while(entry != -1){
        showMenu(); cin >> entry;

        switch (entry) {
            case 1:
                cout << "Flight from: "; cin >> src;
                cout << "Flight to: "; cin >> dest;
                bestTravel(src, dest);
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
