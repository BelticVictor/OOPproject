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
	int counter;

public:
	//constructor
	Ticket_Manager() {}

	Ticket_Manager(const Venue& _Location, const Event& event) : Location(_Location), event(event) {}

	void generateTickets(int _type, int quantity) {
		if (this->tickets == nullptr) {
			this->tickets = new Ticket[quantity];
			for (int i = 0; i < quantity; i++)
				this->tickets[i].set_type(_type);
			counter = quantity;
		}
		else {
			int quan = quantity + tickets->get_tickets_bought();
			int initialTCount = tickets->get_tickets_bought();
			int* old_ticket_type = new int[initialTCount];
			for (int i = 0; i < initialTCount; i++)
				old_ticket_type[i]= this->tickets[i].returnType();
			delete[] this->tickets;
			this->tickets = new Ticket[quan];
			for (int i = 0; i < initialTCount; i++)
				this->tickets[i].set_type(old_ticket_type[i]);
			for (int i = initialTCount; i < quan; i++)
				this->tickets[i].set_type(_type);
			tickets->set_tickets_bought(quan);
			counter = quan;
		}
	}

	bool checkTicketOverflow() {
		if (this->tickets[0].get_tickets_bought() > this->Location.get_maxSeats())
			return true;  //there is an overflow
		else
			return false;
	}

	friend ostream& operator<<(ostream& console, Ticket_Manager& s);
	//set it up so that seats create a matrix of seats which people can pick out of
	//take example and add method so it shows up the matrix of all seats when selecting a specific seat
	
	friend istream& operator>>(istream& console, Ticket_Manager& s);
};