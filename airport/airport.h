//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
#include"transport.h"
#include"service.h"
#include<list>
#include<queue>
#include"../src/date.h"

using namespace std;
/**
 * Class Airport
 *
 * The attributes defined in this class are the Airport's name, (and respective 3 letter id), country, city
 * a list of public transports nearby and a queue of services currently under way in the facility
 */
class Airport{
    string idName;
    string name;
    string country;
    string city;
    list<Transport*> transport;
    queue<Service*> services;
public:
    Airport(string idName, string name, string country, string city);
    string getidCode();
    string getName ();
    string getCountry();
    string getCity();
    void setTransport (Transport *transport);
    void delTransport (Transport *transport);
    void addService (Service *service);
    void delService (Date date);
};

#endif //MIKEGAIRLINES_AIRPORT_H
