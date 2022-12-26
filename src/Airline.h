#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

using namespace std;

class Airline {
private:
    string code, name, callSign, country;
public:
    Airline();
    Airline(string code, string name, string callSign, string country);
};

#endif
