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
    auto it3 = it2++;

    /**
    double d = FlightManager::calculateDistance(*it2, *it3);
    cout << d << "\n";
    */

    /**
    while (it != airports.end()) {
        cout << it->getCode() << " " << it->getName() << " " << it->getCity() << " " << it->getCountry() << " "
                  << it->getLatitude() << " " << it->getLongitude() << "\n";
        it++;
    }
    */

    while (itAirlines != airlines.end()) {
        cout << itAirlines->getCode() << " " << itAirlines->getName() << " " << itAirlines->getCallSign()
        << " " << itAirlines->getCountry() << "\n";
        itAirlines++;
    }
}

int main() {
    obj.readFiles( "airports.csv","airlines.csv", "flights.csv");

    test();

    return 0;
}
