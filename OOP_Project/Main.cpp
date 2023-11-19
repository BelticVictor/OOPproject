#include <iostream>
#include <string>
using namespace std;
#include "Event.cpp"
#include "Venue.cpp"
#include "Ticket.cpp"
#include "Ticket_Manager.cpp"

int main() {
    int seats[2] = {10, 10};
    Venue location((char*)"Backyard", 100, 2, seats);
    Event event("Concert","18:30", "19:30", "2023-11-16");

    Ticket_Manager ticketManager(location, event);
    ticketManager.generateTickets(1, 5);
    ticketManager.generateTickets(0, 10);
}