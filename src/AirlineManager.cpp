
#include <fstream>
#include <sstream>
#include "AirlineManager.h"

void AirlineManager::readFiles(const string &file1, const string &file2, const string &file3) {
    std::fstream in1, in2, in3;
    std::string token;
    Airport currentAirport;


    in1.open(file1); in2.open(file2); in3.open(file3);

    std::getline(in1,token, '\n'); //step var names ahead
    std::getline(in2,token,'\n');  //step var names ahead
    std::getline(in3,token,'\n');  //step var names ahead


    //reads airports.csv

    while(std::getline(in2,token,'\n')){
        std::stringstream iss(token);
        std::vector<std::string> temp;
        std::string tempstr;

        while((std::getline(iss, tempstr, ','))){
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


        airports_.insert(currentAirport);

    }



}

const Graph &AirlineManager::getFlights() const {
    return flights_;
}

const AirlineManager::airportH &AirlineManager::getAirports() const {
    return airports_;
}
