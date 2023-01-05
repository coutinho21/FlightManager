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
        int destination{};
        double distance{};
        Airline airline;
    };

    struct Node { //airport
        list<Flight> flights;
        bool visited;
    };

    int n{};                     // size of graph
    vector<Node> nodes;

public:
    void addFlight(int origin, int destination, const Airline& airline);
    void print();
    static double calculateDistance(const Airport& a1, const Airport& a2);
    void bestTravel(const Airport& origin, const Airport& destination);
    };


#endif