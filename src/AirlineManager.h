
#ifndef FLIGHTMANAGER_AIRLINEMANAGER_H
#define FLIGHTMANAGER_AIRLINEMANAGER_H


#include <unordered_set>
#include "Graph.h"
#include "Airport.h"
#include "helperFunctions.cpp"

class AirlineManager {
private:


    typedef unordered_set<Airport,hAF,eAF> airportH;

    Graph flights_;
    airportH airports_;

public:
    const Graph &getFlights() const;

    const airportH &getAirports() const;


public:
    AirlineManager() = default;

    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);




};




#endif
