#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <vector>
#include <set>
#include "Airline.h"
#include "Airport.h"

using namespace std;

class Graph {
    struct Flight {
        string destination;
        double distance;
        string airline;
    };

    struct Node { //airport
        string origin;
        vector<Flight> flights;
    };

    int n{};                     // size of graph
    bool hasDir{true};
    vector<Node> nodes;

public:
    void addEdge(const string& origin, const string& destination, const string& airline);
    void print();
    static double calculateDistance(const Airport& a1, const Airport& a2);
};


#endif