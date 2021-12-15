//Created by Pedro Barbeira
#include "data.h"

//TODO
bool Data::addFlight(Flight* f){
    //Test this bish
    bool flag;
    AirportPointer find = airports.find(AirportPointer((*f).getOrigin()->airport));
    if(find.getPointer() == nullptr){
        std::cout << "Error: origin airport not found\n"
                  << "Press enter to continue . . . ";
        int c = getchar();
        return false;
    }
    else{
        AirportPointer& addIn = find;
        airports.remove(find);
        flag = addIn.addFlight(f) && airports.insert(addIn);
    }
    if(flag) {
        AirportPointer find = airports.find(AirportPointer((*f).getDestination()->airport));
        if (find.getPointer() == nullptr) {
            std::cout << "Error: destination airport not found\n"
                      << "Press enter to continue . . . ";
            int c = getchar();
            return false;
        }
        else{
            AirportPointer& addOut = find;
            airports.remove(find);
            flag &= addOut.addFlight(f) && airports.insert(addOut);
        }
        if(!flag){
            std::cout << "Error adding out flight\n"
                      << "Press enter to continue . . . ";
            int c = getchar();
            return false;
        }
    }
    else{

        std::cout << "Error adding in flight\n"
                  << "Press enter to continue . . . ";
        int c = getchar();
        return false;
    }
    return true;
}