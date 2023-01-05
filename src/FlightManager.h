#ifndef AIRLINEMANAGER_H
#define AIRLINEMANAGER_H

#include <unordered_map>
#include <set>
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"


class FlightManager {
private:
    unordered_map<int,Airport> airports;
    Graph flights;
    set<Airline> airlines;

public:
    const Graph &getFlights() const;
    const unordered_map<int,Airport>&getAirports() const;
    const set<Airline> &getAirlines() const;
    FlightManager() = default;
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);
};


#endif
