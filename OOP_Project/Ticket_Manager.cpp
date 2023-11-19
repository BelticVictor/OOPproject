#include <iostream>
#include <string>
using namespace std;

#include "Venue.cpp"
#include "Event.cpp"
#include "Ticket.cpp"

class Ticket_Manager {
	Venue Location;
	Event event;
	Ticket* tickets;
public:
	//constructor

	Ticket_Manager(const Venue& _Location, const Event& event) : Location(_Location), event(event) {}

	void generateTickets(int _type, int quantity) {
		this->tickets = new Ticket[quantity + 1];
		for(int i=0; i<quantity;i++)
			this->tickets[i].set_type(_type);
	}

};