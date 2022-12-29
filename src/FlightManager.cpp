#include <fstream>
#include <sstream>
#include <cmath>
#include "FlightManager.h"

void FlightManager::readFiles(const string &file1, const string &file2, const string &file3) {
    std::fstream in1, in2, in3;
    std::string token;
    Airport currentAirport;
    Airline currentAirline;


    in1.open(file1);
    in2.open(file2);
    in3.open(file3);

    std::getline(in1, token, '\n'); //step var names ahead
    std::getline(in2, token, '\n');  //step var names ahead
    std::getline(in3, token, '\n');  //step var names ahead


    //reads airports.csv
    while (std::getline(in1, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        currentAirport.setCode(temp[0]);
        currentAirport.setName(temp[1]);
        currentAirport.setCity(temp[2]);
        currentAirport.setCountry(temp[3]);
        currentAirport.setLatitude(stod(temp[4]));
        currentAirport.setLongitude(stod(temp[5]));

        airports.insert(currentAirport);
    }


    //read airlines.csv
    while (std::getline(in2, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        currentAirline.setCode(temp[0]);
        currentAirline.setName(temp[1]);
        currentAirline.setCallSign(temp[2]);
        currentAirline.setCountry(temp[3]);

        airlines.insert(currentAirline);
    }

    //reads flights.csv
    while (std::getline(in3, token, '\n')) {
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;
        Airport airport1, airport2;
        Airline airline1;

        while ((std::getline(iss, tempstr, ','))) {
            if (!tempstr.empty() && tempstr[tempstr.size() - 1] == '\r')
                tempstr.erase(tempstr.size() - 1);
            temp.push_back(tempstr);
        }

        // change if there is a more efficient way to find the data
        for(const Airport& airport : airports){
            if(airport.getCode() == temp[0])
                airport1 = airport;
            else if (airport.getCode() == temp[1])
                airport2 = airport;

        }

        for(const Airline& airline : airlines){
            if(airline.getCode() == temp[2]) {
                airline1 = airline;
                break;
            }
        }

        flights.addEdge(airport1, airport1, airline1);
    }
}

const FlightManager::airportH &FlightManager::getAirports() const {
    return this->airports;
}

const set<Airline> &FlightManager::getAirlines() const {
    return this->airlines;
}

const Graph &FlightManager::getFlights() const {
    return flights;
}
