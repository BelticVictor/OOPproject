#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket
{
	const int ID;
	int type; // 0 for normal, 1 for VIP,2+ for smthg else if needed
	static int tickets_bought;
	int price;

public:

	//default constructor

	Ticket() : ID(rand()) {
		this->price = 0;
		this->type = 0;
		tickets_bought++;
	}

	//constructor

	Ticket(int type,int _price) : ID(rand()),price(_price) {
		this->type = type;
		tickets_bought++;
	}

	//copy constructor

	Ticket(const Ticket& copy) : ID(copy.ID),price(copy.price) {
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

	int get_price() { return this->price; }

	int get_ID() { return (int)this->ID; }

	int get_tickets_bought(){ return (int)tickets_bought; }

	//setter

	int set_price(int _price) {
		if (_price > 0) {
			this->price = price;
		}
	}

	void set_type(int _type) {
		if (_type < 2) {
			this->type = _type;
		}
	}

	void set_tickets_bought(int quantity) {
		if (quantity > 0) {
			this->tickets_bought = quantity;
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

	int returnType() {
		return this->type;
	}

	//overloads

	Ticket operator++()
	{
		this->tickets_bought++;
		return *this;
	}

	Ticket operator--()
	{
		this->tickets_bought--;
		return *this;
	}

	bool operator!() {
		switch (this->type) {
		case(0):
			return 1;
			break;
		case(1):
			return 0;
			break;
		}
	}

	friend ostream& operator<<(ostream& console, Ticket& s);
	friend istream& operator>>(istream& console, Ticket& s);
};