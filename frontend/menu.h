//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>
#include "user.h"
#include "voyage.h"
#include "airport.h"

//Eventually add Client subclass to user and create a user.h


/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportFlightList> airports;
    std::vector<Voyage*> voyages;
    BST<FlightPointer> flights;
    BST<PlanePointer> planes;
    std::vector<Ticket*> tickets;
    BST<UserPointer> users;
    //BST<ClientPointer> clients;
    //BST<CompanyPointer> company;
    friend class MikeG;
public:
    Data() : airports(AirportFlightList(nullptr)), flights(FlightPointer(nullptr)),
             planes(PlanePointer(nullptr)), users(UserPointer(nullptr)){
        BST<UserPointer> u(UserPointer(nullptr));
        users = u;
        voyages.clear();
        tickets.clear();
    }
    //Add get methods
    BST<AirportFlightList> getAirport() const{
        return airports;};
    std::vector<Voyage*> getVoyages() const{
        return voyages;};
    BST<FlightPointer> getFlights() const{
        return flights;};
    BST<PlanePointer> getPlanes() const{
        return planes;};
    std::vector<Ticket*> getTickets() const{
        return tickets;
    }
    //Add find methods
};

/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */

class Menu{
protected:
    User* user;
    Data* data;
    Time* sysTime;
public:
    explicit Menu(Data* d = nullptr) : data(d){
        sysTime = new Time;
        sysTime->now();
    };
    virtual void mainScreen() const;
};

//Clear definitons from all the mainScreens() and write them in menu.cpp
//The definitoins below were just to test the control flow and the logIn() function
/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
    //This would have a Client* user
public:
    explicit ClientMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const;
};

/**
 * Frontend class that handles Unregistered Client menus
 */
class JustBuy : public ClientMenu{
public:
    explicit JustBuy(Data* d = nullptr){
        user = nullptr;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
};

/**
 * Frontend class that handles Company menus
 */
class CompanyMenu : public Menu{
    //This would have a Company* user, to make sure only company memebers
    //cout access this menu
};

/**
 * Frontend class that handles Admin menus
 */
class AdminMenu : public CompanyMenu{
public:
    explicit AdminMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override{
        std::cout << "we are @ Admin\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{
public:
    explicit ManagerMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override{
        std::cout << "we are @ Manager\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{
public:
    explicit BoardingMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override{
        std::cout << "we are @ Boarding\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
};

//Eventually split this into BoardingPassenger and CheckinPassenger

/**
 * Frontend class that handles Service Worker menus
 */
class ServiceMenu : public CompanyMenu{
public:
    explicit ServiceMenu(User* u = nullptr, Data*d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override{
        std::cout << "we are @ Service\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
};

std::ostream& operator<<(ostream& out, const UserPointer& user);
void readInput(char& in);
void readInput(std::string& in);

#endif //MAIN_CPP_MENU_H
