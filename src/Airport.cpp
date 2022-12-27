
#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

void Airport::setCode(const string &code) {
    Airport::code = code;
}

void Airport::setName(const string &name) {
    Airport::name = name;
}

void Airport::setCity(const string &city) {
    Airport::city = city;
}

void Airport::setCountry(const string &country) {
    Airport::country = country;
}

void Airport::setLatitude(double latitude) {
    Airport::latitude = latitude;
}

void Airport::setLongitude(double longitude) {
    Airport::longitude = longitude;
}

const string &Airport::getCode() const {
    return code;
}

const string &Airport::getName() const {
    return name;
}

const string &Airport::getCity() const {
    return city;
}

const string &Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}

