#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

using namespace std;

class Airport {

private:
    int gIndex;
    string code, name, city, country;
    double latitude{}, longitude{};
public:

    Airport() = default;
    Airport(int i, string code, string name, string city, string country, double latitude, double longitude);

    int getGIndex() const;

    void setGIndex(int gIndex);

    const string &getCode() const;

    const string &getName() const;

    const string &getCity() const;

    const string &getCountry() const;

    double getLatitude() const;

    double getLongitude() const;


    void setCode(const string &code);

    void setName(const string &name);

    void setCity(const string &city);

    void setCountry(const string &country);

    void setLatitude(double latitude);

    void setLongitude(double longitude);
};

#endif
