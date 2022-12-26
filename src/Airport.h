#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

using namespace std;

class Airport {
private:
    string code, name, city, country;
    double latitude, longitude;
public:
    Airport();
};

#endif
