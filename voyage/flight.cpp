//Created by Pedro Barbeira
#include "flight.h"

/**Flight*/
Flight::Flight(TimePlace* o, TimePlace* d, Plane* p):
        origin(o), destination(d), plane(p){
    stringstream ss;
    count++;
    ss << "MG" << setw(3) << setfill('0') << count;
    flightID = ss.str();
    voyageID = "noVoyage";
}

Flight::~Flight(){
    origin->airport = nullptr;
    destination->airport = nullptr;
    plane = nullptr;
    delete origin;
    delete destination;
}

void Flight::setPrice(uint16_t f, uint16_t b, uint16_t e) {
    plane->setFClassPrice(f);
    plane->setBClassPrice(b);
    plane->setEClassPrice(e);
}

void Flight::print(ostream& out) const{
    out << setw(10) << left << setfill(' ') << flightID
        << setw(9) << left << origin->airport->getidCode()
        << setw(10) << left << destination->airport->getidCode();
    //finish with airport and plane
    std::cout << '\n';
}


