#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket
{
	const int ID;
	int type; // 0 for normal, 1 for VIP,2+ for smthg else if added
	static int tickets_bought;
	int price;

public:

	//default constructor

	Ticket() : ID(rand()) {
		this->type = 0;
		this->price = 0;
		tickets_bought++;
	}

	//constructor

	Ticket(int type,int _price) : ID(rand()) {
		this->type = type;
		this->price = _price;
		tickets_bought++;
	}

	//copy constructor

	Ticket(const Ticket& copy) : ID(rand()), price(copy.price) {
		this->type = copy.type;
		tickets_bought++;
	}

	//getter

	string get_type() {
		switch (this->type) {
		case(0):
			return "Normal";
			break;
		case(1):
			return "VIP";
			break;
		}
	}

	int get_ID() { return (int)this->ID; }

	int get_price() { return (int)this->price; }

	int get_tickets_bought(){ return (int)tickets_bought; }

	//setter

	void set_type(int _type) {
		switch (_type) {
		case(0):
			this->type = _type;
			break;
		case(1):
			this->type = _type;
			break;
		}
	}

	//generic methods

	void change_type() {
		switch (this->type) {
		case(0):
			this->type = 1;
			break;
		case(1):
			this->type = 0;
			break;
		}
	}

	static void IncreaseTicketsBought(int amount) { 
		tickets_bought += amount;
	}

	friend ostream& operator<<(ostream& console, Ticket& s);
	//friend void operator>>(istream& console, Ticket& s);
};