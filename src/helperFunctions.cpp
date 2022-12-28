#ifndef HELPERFUNCTIONS_CPP
#define HELPERFUNCTIONS_CPP

#include <cmath>

double calculateDistance(double lat1, double lat2, double lon1, double lon2){
    int earthRadius = 6371000; // metres
    double latitudeSource = lat1 *  M_PI/180; // φ, λ in radians
    double latitudeDestination = lat2 * M_PI/180;
    double latitudeDiff = (lat2 - lat1) * M_PI/180;
    double longitudeDiff = (lon2-lon1) * M_PI/180;

    double a = sin(latitudeDiff/2) * sin(latitudeDiff/2) +
               cos(latitudeSource) * cos(latitudeDestination) *
               sin(longitudeDiff/2) * sin(longitudeDiff/2);

    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return earthRadius * c; // in metres
}


#endif