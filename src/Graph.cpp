#include "Graph.h"

void Graph::addEdge(const string& src, const string& dest, const string& airline) {
    int srcI = -1;
    int i = 0;
    n++;

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
        newNode.edges.push_back({dest, 1, airline});
        nodes.push_back(newNode);
    }
    else
        nodes[srcI].edges.push_back({dest, 1, airline});
}

void Graph::print() {
    cout << "Nodes:" << endl;
    cout << "src: ";
    for(const Node& node: nodes){
        cout << node.src << ">";
        for(const Edge& edge: node.edges){
            cout << edge.dest << "," <<  edge.airline << "," << edge.weight << ">";
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
