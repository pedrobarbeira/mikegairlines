//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include "data.h"
#include "sorter.h"

//Think about making the sorter into a class

/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */

class Menu{
protected:
    Data* data;
    Time* sysTime;
public:
    explicit Menu(Data* d = nullptr) : data(d){
        sysTime = new Time;
        sysTime->now();
    };
    virtual void mainScreen();
};

class Dev : public Menu{
    std::vector<std::string> logs;
    std::vector<std::string> newLogs;
public:
    Dev();
    void mainScreen();
    void showLogs(bool flag) const;
    void showNewLogs();
    void save(bool flag);
};

//Clear definitons from all the mainScreens() and write them in menu.cpp
//The definitoins below were just to test the control flow and the logIn() function
/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
protected:
    Client* user;
public:
    explicit ClientMenu(Client* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
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
    void mainScreen() override;
};

class CheckIn : public ClientMenu{};

class Register : public ClientMenu{};

/**
 * Frontend class that handles Company menus
 */
class CompanyMenu : public Menu{
protected:
    Company* user;
    //Add an airport
    //Add service ticket queue
    //add complete service queue
};

/**
 * Frontend class that handles Admin menus
 */
class AdminMenu : public CompanyMenu{
public:
    explicit AdminMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{
public:
    explicit ManagerMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{
public:
    explicit BoardingMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

//Eventually split this into BoardingPassenger and CheckinPassenger

/**
 * Frontend class that handles ServiceTicket Worker menus
 */
class ServiceMenu : public CompanyMenu{
public:
    explicit ServiceMenu(Company* u = nullptr, Data*d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }

    void mainScreen() override;

};

void readInput(char& in);
void readInput(std::string& in);

#endif //MAIN_CPP_MENU_H
