#include "Graph.h"

Graph::Graph() = default;

void Graph::addEdge(const Airport& src, const Airport& dest, const Airline& airline) {
    int srcI = -1;
    int i = 0;

    double weight = calculateDistance(src,dest);

    while(i < nodes.size()){
        if(nodes[i].src == src.getCode()){
            srcI = i;
            break;
        }
        i++;
    }

    if(srcI == -1 ) {
        Node newNode;
        newNode.src = src.getCode();
        newNode.adj.push_back({dest.getCode(), weight, airline});
        nodes.push_back(newNode);
    }
    else {
        nodes[srcI].adj.push_back({dest.getCode(), weight, airline});
    }
}

void Graph::print() {
    cout << "Nodes:" << endl;
    cout << "src: ";
    for(const Node& node: nodes){
        cout << node.src << " -> ";
        for(const Edge& edge: node.adj){
            cout << edge.dest << " -> ";
        }
        cout << "\nsrc: ";
    }
}

double Graph::calculateDistance(const Airport &a1, const Airport &a2) {
    double lat1 = a1.getLatitude();
    double lat2 = a2.getLatitude();
    double lon1 = a1.getLongitude();
    double lon2 = a2.getLongitude();
    int earthRadius = 6371000; // metres
    double latitudeSource = lat1 * M_PI / 180;
    double latitudeDestination = lat2 * M_PI / 180;
    double latitudeDiff = (lat2 - lat1) * M_PI / 180;
    double longitudeDiff = (lon2 - lon1) * M_PI / 180;

    double a = sin(latitudeDiff / 2) * sin(latitudeDiff / 2) +
               cos(latitudeSource) * cos(latitudeDestination) *
               sin(longitudeDiff / 2) * sin(longitudeDiff / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c / 1000; // in km
}
