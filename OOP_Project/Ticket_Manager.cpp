#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Venue.cpp"
#include "Event.cpp"
#include "Ticket.cpp"

class Ticket_Manager { //has all the data for a specified eveniment
	Venue Location;
	Event event;
	Ticket* tickets=nullptr;
public:
	//constructor
	Ticket_Manager(const Venue& _Location, const Event& event) : Location(_Location), event(event) {}

	void generateTickets(int _type, int quantity) {
		this->tickets = new Ticket[quantity + 1];
		for(int i=0; i<quantity;i++)
			this->tickets[i].set_type(_type);
	}

	bool checkOverflow() {
		if (this->tickets[0].get_tickets_bought() > this->Location.get_maxSeats())
			return true;  //there is an overflow
		else
			return false;
	}

	friend ostream& operator<<(ostream& console, Ticket_Manager& s);
	//set ip up so that seats create a matrix of seats which people can pick out of
	//take example and add method so it shows up the matrix of all seats when selecting a specific seat
	
	//friend void operator>>(istream& console, Ticket_Manager& s);
};