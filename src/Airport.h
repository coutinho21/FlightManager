#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include "Flight.h"
#include "Airline.h"

using namespace std;

class Flight;

class Airport {
    string code, name, city, country;
    double latitude{}, longitude{}, distance{};
    bool visited;
    vector<Flight> flights;
public:

    Airport() = default;
    Airport(string code, string name, string city, string country, double latitude, double longitude, bool visited);

    const string &getCode() const;

    const string &getName() const;

    const string &getCity() const;

    const string &getCountry() const;

    double getLatitude() const;

    double getLongitude() const;

    vector<Flight> getFlights() const;

    void setCode(const string &code);

    void setName(const string &name);

    void setCity(const string &city);

    void setCountry(const string &country);

    void setLatitude(double latitude);

    void setLongitude(double longitude);

    void addFlight(Airport* destination, Airline* airline);

};

#endif
