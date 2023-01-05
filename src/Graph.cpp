#include <queue>
#include "Graph.h"

void Graph::addFlight(int origin, int destination, string airline) {

    n++;
    double distance = 1;
    Flight test;
    test.destination=destination;
    test.distance=1;
    test.airline = airline;

    nodes[1].flights.push_back(test);
    //double distance = FlightManager::calculateDistance(src,dest);

    //nodes[origin].flights.push_back({destination,distance,airline});

}

void Graph::print() {
    cout << "Nodes:" << endl;
    for(int i = 0; i< nodes.size();i++){
        cout << "src: "<< i;
        for(const Flight& edge: nodes[i].flights){
            cout << " " <<edge.destination << ",";// <<  edge.airline.getCode() << "," << edge.distance << ">";
        }

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
/*
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
*/