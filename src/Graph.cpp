#include <queue>
#include "Graph.h"

void Graph::addEdge(const string& origin, const string& destination, const string& airline) {
    int srcI = -1;
    int i = 0;
    n++;

    //double weight = FlightManager::calculateDistance(src,dest);

    while(i < nodes.size()){
        if(nodes[i].origin == origin){
            srcI = i;
            break;
        }
        i++;
    }

    if(srcI == -1) {
        Node newNode;
        newNode.origin = origin;
        newNode.flights.push_back({destination, 1, airline});
        nodes.push_back(newNode);
    }
    else
        nodes[srcI].flights.push_back({destination, 1, airline});
}

void Graph::print() {
    cout << "Nodes:" << endl;
    cout << "src: ";
    for(const Node& node: nodes){
        cout << node.origin << ">";
        for(const Flight& edge: node.flights){
            cout << edge.destination << "," <<  edge.airline << "," << edge.distance << ">";
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

void Graph::bestTravel(const Airport& origin, const Airport& destination){

    for (int i=1; i<= nodes.size() - 1; i++) nodes[i].visited = false;
    queue<Airport> q; // queue of unvisited nodes
    q.push(origin);
    nodes[].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}