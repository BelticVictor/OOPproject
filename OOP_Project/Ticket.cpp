#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket
{
protected:
	const int ID;
	int type; // 0 for normal, 1 for VIP,2+ for smthg else if needed
	static int normal_tickets_bought;
	static int vip_tickets_bought;
	int price;

public:

	//default constructor

	Ticket() : ID(rand()) {
		this->price = 0;
		this->type = 0;
	}

	//constructor

	Ticket(int type) : ID(rand()) {
		this->type = type;
		switch (this->type) {
		case(0):
			normal_tickets_bought++;
			this->price = 10;
			break;
		case(1):
			vip_tickets_bought++;
			this->price = 15;
			break;
		}
	}

	//copy constructor

	Ticket(const Ticket& copy) : ID(copy.ID),price(copy.price) {
		this->type = copy.type;
		switch (this->type) {
		case(0):
			normal_tickets_bought++;
			break;
		case(1):
			vip_tickets_bought++;
			break;
		}
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
		return "error";
	}

	int get_price() { return this->price; }

	int get_ID() { return this->ID; }

	int get_normal_tickets_bought(){ return normal_tickets_bought; }
	int get_vip_tickets_bought() { return vip_tickets_bought; }

	//setter

	int set_price(int _price) {
		if (_price <= 0)
			throw invalid_argument("Invalid price");
	
		this->price = price;
	}

	void set_type(int _type) {
		if (_type < 2) {
			this->type = _type;
		}
		else
			throw invalid_argument("Invalid type");
	}

	void set_normal_tickets_bought(int quantity) {
		if (quantity > 0) {
			this->normal_tickets_bought = quantity;
		}
		else
			throw invalid_argument("Invalid number of tickets bought");
	}

	void set_vip_tickets_bought(int quantity) {
		if (quantity > 0) {
			this->vip_tickets_bought = quantity;
		}
		else
			throw invalid_argument("Invalid number of tickets bought");
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

	static void IncreaseNormalTicketsBought(int amount) { 
		normal_tickets_bought += amount;
	}

	static void IncreaseVipTicketsBought(int amount) {
		vip_tickets_bought += amount;
	}

	int returnType() {
		return this->type;
	}

	//overloads

	Ticket operator++()
	{
		this->normal_tickets_bought++;
		return *this;
	}

	Ticket operator++(int)
	{
		Ticket copy = *this;
		this->normal_tickets_bought++;
		return copy;
	}

	Ticket operator--()
	{
		this->normal_tickets_bought--;
		return *this;
	}

	Ticket operator--(int)
	{
		Ticket copy = *this;
		this->normal_tickets_bought--;
		return copy;
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

	/*Ticket& operator=(const Ticket& tix) {
		this->type = tix.type;
		this->price = tix.price;

		return *this;
	}*/

	friend ostream& operator<<(ostream& console, Ticket& t) {
		console << endl << "The ticket ID is " << t.get_ID();

		console << endl << "It's type is " << t.get_type();

		//console << endl << "The total number of tickets bought is " << t.get_tickets_bought() - 1;

		cout << endl;
		return console;
	}

	friend istream& operator>>(istream& console, Ticket& t) {
		cout << "Input ticket type(0 for Normal, 1 for VIP): ";
		cin >> t.type;

		return console;
	}
};