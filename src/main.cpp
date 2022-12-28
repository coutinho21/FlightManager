#include <iostream>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "AirlineManager.h"

using namespace std;

AirlineManager obj;

void test() {
    typedef unordered_set<Airport, hAF, eAF>::iterator iteratorH;

    auto airports = obj.getAirports();
    auto it = airports.begin();

    while (it != airports.end()) {
        std::cout << it->getCode() << " " << it->getName() << " " << it->getCity() << " " << it->getCountry() << " "
                  << it->getLatitude() << " " << it->getLongitude() << "\n";
        it++;
    }
}

int main() {

    obj.readFiles("airlines.csv", "airports.csv", "flights.csv");

    test();


    return 0;
}
