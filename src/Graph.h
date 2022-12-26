#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Graph {
    struct Edge {
        int dest, weight;
    };

    struct Node {
        list<Edge> adj;
    };

    int n;                  // size of graph
    bool hasDir;            // has direction?
    vector<Node> nodes;

public:
    Graph();
    Graph(int num, bool dir = false);
    void addEdge(int src, int dest, int weight = 1);
};


#endif
