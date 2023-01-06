#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>
#include "Airline.h"
#include "Airport.h"

using namespace std;

class Graph {

    int n{};       // size of graph
    unordered_map<string,Airport*> airports;
    unordered_map<string,Airline*> airlines;
public:
    void readFiles(const std::string& file1, const std::string& file2, const std::string& file3);
    static double calculateDistance(Airport* a1, Airport* a2);
    void bestTravel(Airport* origin, Airport* destination);
    void bestTravelCity(string origin, string destination);
    unordered_map<string,Airport*> getAirports();
    unordered_map<string,Airline*> getAirlines();
};



#endif