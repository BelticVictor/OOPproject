#include <iostream>
#include <string>
using namespace std;
#include "Event.cpp"
#include "Venue.cpp"
#include "Ticket.cpp"
#include "Ticket_Manager.cpp"

ostream& operator<<(ostream& console, Venue& v) { //realised its friended so i dont have to call getters, but im too scared to change it at this point
    console << endl << "Venue name is " << v.get_name();

    console << endl << "The maximum capacity is " << v.get_maxSeats();

    console << endl << "There are " << v.get_rows() << " rows";

    for (int i = 0; i < v.get_rows(); i++)
        console << endl << "The number of seats on row " << i+1 << " is " << v[i];

    cout << endl;
    return console;
}

istream& operator>>(istream& console, Venue& v) {
    string buffer;
    cout << "Input Venue name: ";
    console >> buffer;
    if (v.name != nullptr)
    {
        delete[] v.name;
    }
    v.name = new char[buffer.length() + 1];
    strcpy_s(v.name, buffer.length() + 1, buffer.c_str());

    cout << endl << "Input the Venue's maximum capacity: ";
    console >> v.maxSeats;

    cout << endl << "Input the amount of rows: ";
    console >> v.rows;

    v.seats_per_row = new int[v.rows + 1];
    for (int i = 0; i < v.get_rows(); i++) {
        cout << endl << "The number of seats on row " << i + 1 << " is ";
        console >> v.seats_per_row[i];
    }

    return console;
}

ostream& operator<<(ostream& console, Event& e) {
    console << endl << "The event is a " << e.get_name();

    console << endl << "It will start at " << e.get_start_time() << " and end at " << e.get_finish_time();

    console << endl << "The duration is " << e.duration() << " minutes";

    console << endl << "It will take place on " << e.get_date();

    cout << endl;
    return console;
}

istream& operator>>(istream& console, Event& e) {
    cout << endl << "Input event name: ";
    console >> e.name;

    cout << endl << "Input start time: ";
    console >> e.start_time;

    cout << endl << "Input finish time: ";
    console >> e.finish_time;

    cout << endl << "The date is: ";
    console >> e.date;

    return console;
}

ostream& operator<<(ostream& console, Ticket& t) {
    console << endl << "The ticket ID is " << t.get_ID();

    console << endl << "It's type is " << t.get_type();

    //console << endl << "The total number of tickets bought is " << t.get_tickets_bought() - 1;

    cout << endl;
    return console;
}

istream& operator>>(istream& console, Ticket& t) {
    cout << "Input ticket type(0 for Normal, 1 for VIP): ";
    cin >> t.type;
    
    return console;
}

ostream& operator<<(ostream& console, Ticket_Manager& t) {

    console << endl << t.Location;

    console << endl << t.event;

    for (int i = 0; i < t.counter; i++)
        cout << endl << t.tickets[i];

    console << endl << "The number of tickets sold in this eveniment is: " << t.counter;

    console << endl <<endl << "The total number of tickets sold is " << t.tickets->get_tickets_bought() - 1 <<endl;

    cout << endl;
    return console;
}

istream& operator>>(istream& console, Ticket_Manager& Tix) {
    console >> Tix.Location;
    console >> Tix.event;
    int quan, type;
    cout << endl << "Enter the type of tickets you want to buy(0 for Normal, 1 for VIP): ";
    cin >> type;
    cout << endl << "Enter the quantity of tickets you want to buy): ";
    cin >> quan;
    Tix.generateTickets(type, quan);

    cout << endl;
    return console;
}

int Ticket::tickets_bought = 0;

int main() {

    int seats[2] = {10, 10};
    Venue location((char*)"Backyard", 100, 2, seats);
    Event event("Concert","18:30", "19:30", "2023-11-16");
    Ticket_Manager ticketManager(location, event);
    ticketManager.generateTickets(0, 2);
    ticketManager.generateTickets(1, 3);
    Ticket_Manager ticketmanager1;
    cin >> ticketmanager1;
    cout << ticketmanager1;
}