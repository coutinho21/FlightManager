#include "Graph.h"


Graph::Graph() = default;

void Graph::addEdge(string src, string dest, string airline) {
    int srcI = -1;
    int i = 0;
    //double weight = FlightManager::calculateDistance(src,dest);

    while(i<nodes.size()){
        if(nodes[i].src == src){
            srcI = i;
            break;
        }
        i++;
    }

    if(srcI == -1 ) {
        Node newNode;
        newNode.src = src;
        newNode.adj.push_back({dest, 1, airline});
        nodes.push_back(newNode);
    }
    else {
        nodes[srcI].adj.push_back({dest, 1, airline});
    }


}

void Graph::print() {
    std::cout << "Nodes: \n";
    std::cout << "src: ";
    for(Node node: nodes){
        std::cout << node.src << " ->";
        for(Edge edge: node.adj){
            std::cout << edge.dest << "->";
        }
        std::cout << "\nsrc: ";
    }
}
