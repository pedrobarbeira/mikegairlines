//#include "mainmenu.h"
#include "mikeg.h"
#include "funcoes.h"
//Use vectors and comparator functions to allow for different searches



/**
 * Airport-related testing
 */
void testAirport(){
    //airport();
    /*
    Airport porto("oPo", "Sá Carneiro", "Portugal", "Porto" );
    Date date(10,12,2021);
    Plane *plane = new Plane;
    Staff *staff1 = new Staff("Manel");
    Cleaning *cle1 = new Cleaning(plane);
    Cleaning *cle2 = new Cleaning(plane, date, staff1);
    Date date1(30, 11, 21);
    Date date2(1, 12, 21);
    (*cle1).setResponsible(staff1);
    porto.addService(cle1);
    Maintenance mai3(plane, date2, staff1);
    porto.addService(cle2);
    porto.delService(date2);
    Transport *test1 = new Transport('m', 2);
    Transport *test2 = new Transport('b', 0);
    Transport *test3 = new Transport('b', 1);
    Transport *test4 = new Transport('t', 5);
    Time time1(10, 0, 0);
    Time time2(11, 30, 0);
    Time time3(12, 0, 0);
    Time time4(13, 15, 0);
    Time time5(15, 0, 0);
    (*test1).addTime(time1);
    (*test1).addTime(time2);
    (*test1).addTime(time4);
    (*test2).addTime(time1);
    (*test2).addTime(time2);
    (*test3).addTime(time2);
    (*test3).addTime(time3);
    (*test4).addTime(time1);
    (*test4).addTime(time5);
    porto.setTransport(test1);
    porto.setTransport(test2);
    porto.setTransport(test3);
    porto.setTransport(test4);
    porto.nextTransportMetro(time2);
    porto.nextTransportBus(time1);
    porto.nextTransportTrain(time3);
    Time time6(23, 59, 59);
    porto.nextTransportTrain(time6);
     */
}

/**
 * Voyage-related testing
 */
void testVoyage() {
    std::queue<std::string> first({"A", "M"});
    Airbus* arb1=new Airbus(first);
    Airbus* arb2 = new Airbus(first);
    Airbus* arb3 = new Airbus(first);

    BST<PlanePointer> pbst(PlanePointer(nullptr));

    PlanePointer pptr1(arb1);
    PlanePointer pptr2(arb2);
    PlanePointer pptr3(arb3);

    pbst.insert(pptr2);
    pbst.insert(pptr3);
    pbst.insert(pptr1);

    arb1->showSeats();

}

/**
 * Passenger-related testing
 */
void testPassenger() {
   /* vector<Ticket *> tickets;
    vector<Luggage *> passLugg;
    queue<stack<Luggage*>> bags;
    while (true) {
        cout << "[1] comprar bilhetes" << endl;
        cout << "[2] lista bilhetes" << endl;
        cout << "[3] enviar malas"<< endl;
        cout << "[4] voltar" << endl;
        int escolha;
        cin >> escolha;
        if( escolha==4){
            break;
        }
        switch (escolha) {
            case 1:
                buyTicket(tickets, passLugg);
                break;
            case 2:
                listBilhetes(tickets);
                break;
            case 3:
                fazerpilha(bags,passLugg);
        }
    }*/
}
/**
 * Menu-related testing
 */
void testMenu(){
    MikeG main;
    bool flag = false;
    main.start(flag);
}

/**
 * Interfacing for the test framework
 */
void testInterface(){
    while(true) {
        system(CLEAR);
        char c;
        std::cout << "[RunTests]\n"
                  << "\n\t[1] Airport"
                  << "\n\t[2] Voyage"
                  << "\n\t[3] Passenger"
                  << "\n\t[4] Menu\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        std::cin >> c;
        switch (c) {
            case '1': testAirport(); break;
            case '2': testVoyage(); break;
            case '3': testPassenger(); break;
            case '4': testMenu(); break;
            case '0': exit(0);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

int main(){
    Time t(10, 25, 00);

    t.print(std::cout);


    testInterface();

    return 0;
}