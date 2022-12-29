#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;

class Graph {
    struct Edge {
        string dest;
        double weight;
        string airline;
    };

    struct Node {
        string src;
        list<Edge> adj;
    };

    int n{};                  // size of graph
    vector<Node> nodes;

public:
    Graph();


    void addEdge(string src, string dest, string airline);

    void print();
};


#endif
