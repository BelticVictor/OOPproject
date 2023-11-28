#pragma once
#include <iostream>
#include <string>
using namespace std;

class Venue {
	char* name=nullptr;
	int maxSeats;
	int rows;
	int* seats_per_row=nullptr; //seats_per_row[i]=number of seats on row i
	//maybe add zones
	

public:

	//default constructor

	Venue() {
		this->maxSeats = 0;
		this->rows = 0;
		this->name = nullptr;
		this->seats_per_row = nullptr;
	}

	//constructor

	Venue(const char* _name, int _maxSeats, int _rows, const int* _seats_per_row) : maxSeats(_maxSeats), rows(_rows) {
		if (_name != nullptr) {
			this->name = new char[strlen(_name) + 1];
			strcpy_s(this->name, strlen(_name) + 1, _name);
		}
		else
			this->name = nullptr;

		if (_rows > 0 && _seats_per_row != nullptr) {
			this->rows = _rows;
			this->seats_per_row = new int[_rows + 1];
			for (int i = 0; i < _rows; i++) {
				this->seats_per_row[i] = _seats_per_row[i];
			}
		}
	}

	//copy constructor

	Venue(const Venue& copy) : maxSeats(copy.maxSeats), rows(copy.rows) {
		this->name = new char[strlen(copy.name) + 1];
		strcpy_s(this->name, strlen(copy.name) + 1, copy.name);

		this->seats_per_row = new int[copy.rows + 1];
		for (int i = 0; i < copy.rows; i++) {
			this->seats_per_row[i] = copy.seats_per_row[i];
		}
	}

	//setters

	void set_maxSeats(int _maxSeats) {
		if (_maxSeats > 0) {
			this->maxSeats = _maxSeats;
		}
	}

	void set_name(char* _name) {
		if (_name != nullptr) {
			this->name = new char[strlen(_name) + 1];		
			strcpy_s(this->name, strlen(_name) + 1, _name);
	    }
	}

	void set_rows(int _rows, int* _seats_per_row) {
		if (_rows > 0 && _seats_per_row != nullptr) {
			this->rows = _rows;
			this->seats_per_row = new int[_rows + 1];		
			for (int i = 0; i < _rows; i++) {			
				this->seats_per_row[i] = _seats_per_row[i];
		    }
		}
	}

	//getters

	char* get_name() { return this->name; }
	int get_maxSeats() { return this->maxSeats; }
	int get_rows() { return this->rows; }
	int* get_seats_per_row() { return this->seats_per_row; }

	//generic method

	bool maxSeatsCheck() { //0 for too many seats, 1 for under the max amount
		int Seats = 0;
		for (int i = 0; i < this->rows; i++) {
			Seats = Seats + this->seats_per_row[i];
		}
		if (Seats > this->maxSeats) {
			cout << "Error, too many seats, exceeds the maximum amount";
			return 0;
		}
		else
			return 1;
	}

	void FixMaxSeats() {
		this->maxSeats = 0;
		for (int i = 0; i < this->rows; i++)
			this->maxSeats = this->maxSeats + this->seats_per_row[i];
	}

	//overloads

	int operator[](int pos) { 
		if (pos >= 0 && pos < this->rows) {
			return this->seats_per_row[pos];
		}
		throw exception("invalid position");
	}

	explicit operator string() {
		return (string)this->name;
	}

	//destructor

	~Venue() {
		delete[] this->name;
		delete[] this->seats_per_row;
	}

	friend ostream& operator<<(ostream& console, Venue& s);

	friend istream& operator>>(istream& console, Venue& v);
};

