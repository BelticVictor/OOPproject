#include <iostream>
#include <string>
using namespace std;
#include "Event.cpp"
#include "Venue.cpp"
#include "Ticket.cpp"
#include "Ticket_Manager.cpp"

ostream& operator<<(ostream& console, Venue& v) {
    console << endl << "Venue name is " << v.get_name();

    console << endl << "The maximum capacity is " << v.get_maxSeats();

    console << endl << "There are " << v.get_rows() << " rows";

    for (int i = 0; i < v.get_rows(); i++)
        console << endl << "The number of seats on row " << i+1 << " is " << v[i];

    return console;
}

ostream& operator<<(ostream& console, Event& e) {
    console << endl << "The event is a " << e.get_name();

    console << endl << "It will start at " << e.get_start_time() << " and end at " << e.get_finish_time();

    console << endl << "The duration is " << e.duration() << " minutes";

    console << endl << "It will take place on " << e.get_date();

    return console;
}

ostream& operator<<(ostream& console, Ticket& t) {
    console << endl << "The ticket ID is " << t.get_ID();

    console << endl << "It costed " << t.get_price();

    console << endl << "It's type is " << t.get_type();

    //console << endl << "The total number of tickets bought is " << t.get_tickets_bought() - 1;

    return console;
}
ostream& operator<<(ostream& console, Ticket_Manager& t) {

    console << endl << t.Location;

    console << endl << t.event;

    for (int i = 0; i < t.tickets->get_tickets_bought(); i++)
        cout << endl << t.tickets[i];
    console << endl << "The total number of tickets bought is " << t.tickets->get_tickets_bought() - 1;

    return console;
}
int Ticket::tickets_bought = 0;

int main() {

    int seats[2] = {10, 10};
    Venue location((char*)"Backyard", 100, 2, seats);
    Event event("Concert","18:30", "19:30", "2023-11-16");
    Ticket_Manager ticketManager(location, event);
    ticketManager.generateTickets(1, 2);
    ticketManager.generateTickets(0, 3);
    cout << ticketManager;
    //cout << location;
    //cout << event;
    //cout << ticketManager;
}