#include <iostream>
#include "Airport.h"
#include "FlightManager.h"

using namespace std;

FlightManager obj;

void test() {
    typedef unordered_set<Airport, hAF, eAF>::iterator iteratorH;

    auto airports = obj.getAirports();
    auto airlines = obj.getAirlines();
    auto it = airports.begin();
    auto itAirlines = airlines.begin();
    auto it2 = airports.begin();
    auto it3 = airports.begin(); it3++;

    cout << it2->getName() << " (" << it2->getCode() << ") to " << it3->getName() << " (" << it3->getCode() << ')' << endl;
    double d = FlightManager::calculateDistance(*it2, *it3);
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
}

int main() {
    obj.readFiles( "airports.csv","airlines.csv", "flights.csv");

    test();

    return 0;
}
