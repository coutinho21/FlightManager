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

    auto airports = obj.getAirports();
    auto airlines = obj.getAirlines();
    auto flights = obj.getFlights();
    auto it = airports.begin();
    auto itAirlines = airlines.begin();
    auto it2 = airports.begin();
    auto it3 = airports.begin(); it3++;

    cout << it2->second.getName() << " (" << it2->second.getCode() << ") to " << it3->second.getName() << " (" << it3->second.getCode() << ')' << endl;
    double d = Graph::calculateDistance(it2->second, it3->second);
    cout << d << " kilometers" << endl;


    while (it != airports.end()) {
        cout << it->second.getGIndex() <<"-"<<it->second.getCode() << " " << it->second.getName() << " " << it->second.getCity() << " " << it->second.getCountry() << " "
                  << it->second.getLatitude() << " " << it->second.getLongitude() << endl;
        it++;
    }


    /**
    while (itAirlines != airlines.end()) {
        cout << itAirlines->getCode() << " " << itAirlines->getName() << " " << itAirlines->getCallSign()
        << " " << itAirlines->getCountry() << endl;
        itAirlines++;
    }
    */

    flights.print();
}
/*
void bestTravel(const string& origin, const string& destination) {
    auto airports = obj.getAirports();
    auto flights = obj.getFlights();
    auto it = airports.begin();
    Airport from, to;
    while (it != airports.end()) {
        if (it->getCode() == origin)
            from = *it;
        else if (it->getCode() == destination)
            to = *it;
        it++;
    }
    cout << "Flight from " << from.getCode() << " - " << from.getName() << " to " << to.getCode() << " - " << to.getName() << endl;

   // flights.bestTravel(from, to);
}
*/
int main() {
    obj.readFiles( "airports.csv","airlines.csv", "flights.csv");
    test();
    short entry = 0;
    string src, dest;

    while(entry != -1){
        showMenu(); cin >> entry;

        switch (entry) {
            case 1:
                cout << "Flight from: "; cin >> src;
                cout << "Flight to: "; cin >> dest;
                //bestTravel(src, dest);
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
