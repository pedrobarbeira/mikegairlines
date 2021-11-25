//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include <C:\Coding\Cpp\AEDA\mikegairlines\date.h>
#include <C:\Coding\Cpp\AEDA\mikegairlines\voyage\plane.h>
#include <vector>
#include <list>

class Flight;

class Voyage{
    //std::vector<Ticket*> tickets;
    std::list<Flight*> route;
};

class Flight{
    std::string flightID;
    Date* departure;
    Date* arrival;
    //Airport* origin;
    //Airport* destination;
    Plane* plane;
};

#endif //AIPORTMIKEG_VOYAGE_H
