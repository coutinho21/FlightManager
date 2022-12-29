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
    struct Edge {
        string dest;
        double weight;
        Airline airline;
    };

    struct Node {
        string src;
        list<Edge> adj;
    };

    int n{};                  // size of graph
    vector<Node> nodes;

public:
    Graph();
    void addEdge(const Airport& src, const Airport& dest, const Airline& airline);
    void print();
    static double calculateDistance(const Airport& a1, const Airport& a2);
};


#endif