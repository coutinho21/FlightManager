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
    Airport(string code, string name, string city, string country, double latitude, double longitude);

    void setCode(const string &code);

    void setName(const string &name);

    void setCity(const string &city);

    void setCountry(const string &country);

    void setLatitude(double latitude);

    void setLongitude(double longitude);
};

#endif
