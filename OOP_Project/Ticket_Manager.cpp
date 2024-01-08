#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Venue.cpp"
#include "Event.cpp"
#include "Ticket.cpp"

class Ticket_Manager:public Venue,public Event{ //has all the data for a specified eveniment
	Ticket* tickets=nullptr;
	int counter = 0;

public:
	//constructor

	Ticket_Manager():Venue(),Event() {}

	Ticket_Manager(const char* _name, int _maxSeats, int _rows, const int* _seats_per_row, string name, string start_time, string finish_time, string date):Venue(_name,_maxSeats,_rows,_seats_per_row), Event(name,start_time,finish_time,date) {}

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
		if (this->counter > this->get_maxSeats())
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

	Ticket_Manager& operator=(const Ticket_Manager& tix) {
		if (this->VenueName != nullptr)
			delete[] this->VenueName;
		this->VenueName = new char[strlen(tix.VenueName) + 1];
		strcpy_s(this->VenueName, strlen(tix.VenueName) + 1, tix.VenueName);

		this->maxSeats = tix.maxSeats;

		this->rows = tix.rows;

		this->seats_per_row = new int[tix.rows + 1];
		for (int i = 0; i < tix.rows; i++) {
			this->seats_per_row[i] = tix.seats_per_row[i];
		}

		this->EventName = tix.EventName;
		this->date = tix.date;
		this->start_time = tix.start_time;
		this->finish_time = tix.finish_time;

		return *this;
	}
	//set it up so that seats create a matrix of seats which people can pick out of
	//take example and add method so it shows up the matrix of all seats when selecting a specific seat
	

	friend ostream& operator<<(ostream& console, Ticket_Manager& t) {
		//******************venue
		console << endl << "Venue name is " << t.get_venuename();

		console << endl << "The maximum capacity is " << t.get_maxSeats();

		console << endl << "There are " << t.get_rows() << " rows";

		for (int i = 0; i < t.get_rows(); i++)
			console << endl << "The number of seats on row " << i + 1 << " is " << t[i];
		//*********************event
		console << endl << "The event is a " << t.get_eventname();

		console << endl << "It will start at " << t.get_start_time() << " and end at " << t.get_finish_time();

		console << endl << "The duration is " << t.duration() << " minutes";

		console << endl << "It will take place on " << t.get_date();

		if (t.counter > 0)
			for (int i = 0; i < t.counter; i++)
				cout << endl << t.tickets[i];

		console << endl << "The number of tickets sold in this eveniment is: " << t.counter;

		console << endl << endl << "The total number of tickets sold is " << t.tickets->get_tickets_bought() << endl;

		cout << endl;
		return console;
	}

	friend istream& operator>>(istream& console, Ticket_Manager& Tix) {
		//*****************venue
		string buffer;
		cout << "Input Venue name: ";
		console >> buffer;
		if (Tix.VenueName != nullptr)
		{
			delete[] Tix.VenueName;
		}
		Tix.VenueName = new char[buffer.length() + 1];
		strcpy_s(Tix.VenueName, buffer.length() + 1, buffer.c_str());

		cout << endl << "Input the Venue's maximum capacity: ";
		console >> Tix.maxSeats;

		cout << endl << "Input the amount of rows: ";
		console >> Tix.rows;

		Tix.seats_per_row = new int[Tix.rows + 1];
		for (int i = 0; i < Tix.get_rows(); i++) {
			cout << endl << "The number of seats on row " << i + 1 << " is ";
			console >> Tix.seats_per_row[i];
		}
		//*****************event

		cout << endl << "Input event name: ";
		console >> Tix.EventName;

		cout << endl << "Input start time: ";
		console >> Tix.start_time;

		cout << endl << "Input finish time: ";
		console >> Tix.finish_time;

		cout << endl << "The date is: ";
		console >> Tix.date;

		/* int quan, type; tickets are generated manually
		 cout << endl << "Enter the type of tickets you want to buy (0 for Normal, 1 for VIP): ";
		 cin >> type;
		 cout << endl << "Enter the quantity of tickets you want to buy): ";
		 cin >> quan;
		 Tix.generateTickets(type, quan);*/

		cout << endl;
		return console;
	}

};