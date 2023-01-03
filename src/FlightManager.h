#ifndef AIRLINEMANAGER_H
#define AIRLINEMANAGER_H

#include <unordered_set>
#include <set>
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include "hashFunctions.cpp"

class FlightManager {
private:
    typedef unordered_set<Airport,hAF,eAF> airportH;
    Graph flights = Graph();
    airportH airports;
    set<Airline> airlines;

public:
    const Graph &getFlights() const;
    const airportH &getAirports() const;
    const set<Airline> &getAirlines() const;
    FlightManager() = default;
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);
};


#endif
