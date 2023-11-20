#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket
{
	const int ID;
	int type; // 0 for normal, 1 for VIP
	static int tickets_bought;

public:


	//constructor

	Ticket(int type) : ID(rand()) {
		this->type = type;
		tickets_bought++;
	}

	//default constructor

	Ticket() : ID(rand()) {
		this->type = 0;
		tickets_bought++;
	}

	//copy constructor

	Ticket(const Ticket& copy) : ID(rand()) {
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
};
int Ticket::tickets_bought = 0;