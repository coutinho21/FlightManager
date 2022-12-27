
#ifndef FLIGHTMANAGER_AIRLINEMANAGER_H
#define FLIGHTMANAGER_AIRLINEMANAGER_H


#include <unordered_set>
#include "Graph.h"
#include "Airport.h"

class AirlineManager {
private:


    Graph flights_;
    unordered_set<Airport> airports_;

public:
    AirlineManager();

    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);




};




#endif
