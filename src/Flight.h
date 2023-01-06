#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "Airline.h"

class Airport;

class Flight {
    Airport *destination;
    Airline *airline;
    double distance{};



public:
    Flight() = default;
    Flight(Airport *destination, Airline *airline);

    Airport *getDestination() const;

    void setDestination(Airport *destination);

    Airline *getAirline() const;

    void setAirline(Airline *airline);

    double getDistance() const;

    void setDistance(double distance);
};

#endif
