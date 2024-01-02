#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Venue.cpp"
#include "Event.cpp"
#include "Ticket.cpp"

class Ticket_Manager:Venue,Event,Ticket { //has all the data for a specified eveniment
	Venue Location;
	Event event;
	Ticket* tickets=nullptr;
	int counter = 0;

public:
	//constructor
	Ticket_Manager() {}

	Ticket_Manager(const Venue& _Location, const Event& event) : Location(_Location), event(event) {}

	//setters

	void set_location(Venue loc) {
		this->Location = loc;
	}

	void set_event(Event eve) {
		this->event = eve;
	}

	//generic methods

	void generateTickets(int _type, int quantity) {
		if (this->tickets == nullptr) {
			this->tickets = new Ticket[quantity];
			for (int i = 0; i < quantity; i++) {
				this->tickets[i].set_type(_type);
				tickets[i]++;
			}
			counter = quantity;
		}
		else {
			int quan = quantity + this->counter;

			int initialTCount = this->counter;

			int* old_ticket_type = new int[initialTCount];

			for (int i = 0; i < initialTCount; i++)
				old_ticket_type[i]= this->tickets[i].returnType();

			delete[] this->tickets;
			this->tickets = new Ticket[quan];

			for (int i = 0; i < initialTCount; i++)
				this->tickets[i].set_type(old_ticket_type[i]);

			for (int i = initialTCount; i < quan; i++) {
				this->tickets[i].set_type(_type);
				tickets[0]++;
			}

			counter = quan;

			delete[] old_ticket_type;
		}
	}

	bool checkTicketOverflow() {
		if (this->counter > this->Location.get_maxSeats())
			return true;  //there is an overflow
		else
			return false;
	}

	double profit(Ticket* t) {
		if (counter > 0 && t->get_price() > 0) {
			double profit = t->get_price() * counter;
			return profit;
		}
		else
			return 0;
	}

	static double totalProfit(Ticket_Manager t) {
		if (t.counter > 0 && t.tickets->get_price() > 0) {
			double profit = t.tickets->get_tickets_bought() * t.tickets->get_price();
			return profit;
		}
		else
			return 0;
	}

	//Ticket_Manager& operator=(const Ticket_Manager& tix) {
	//	this->Location = tix.Location;
	//	this->event = tix.event;

	//	if(counter>0)
	//		for (int i = 0; i < this->counter; i++) {
	//			this->tickets[i] = tix.tickets[i];
	//		}

	//	return *this;
	//}

	friend ostream& operator<<(ostream& console, Ticket_Manager& s);
	//set it up so that seats create a matrix of seats which people can pick out of
	//take example and add method so it shows up the matrix of all seats when selecting a specific seat
	
	friend istream& operator>>(istream& console, Ticket_Manager& s);
};