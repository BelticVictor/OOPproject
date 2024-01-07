#pragma once
#include <iostream>
#include <string>
class Ticket_Manager;
using namespace std;

class Venue {
protected:
	char* VenueName=nullptr;
	int maxSeats;
	int rows;
	int* seats_per_row=nullptr; //seats_per_row[i]=number of seats on row i
	//maybe add zones
	

public:

	//default constructor

	Venue() {
		this->maxSeats = 0;
		this->rows = 0;
		this->VenueName = nullptr;
		this->seats_per_row = nullptr;
	}

	//constructor

	Venue(const char* _name, int _maxSeats, int _rows, const int* _seats_per_row) : maxSeats(_maxSeats), rows(_rows) {
		if (_name != nullptr) {
			this->VenueName = new char[strlen(_name) + 1];
			strcpy_s(this->VenueName, strlen(_name) + 1, _name);
		}
		else
			this->VenueName = nullptr;

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
		this->VenueName = new char[strlen(copy.VenueName) + 1];
		strcpy_s(this->VenueName, strlen(copy.VenueName) + 1, copy.VenueName);

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
		else
			throw invalid_argument("Invalid number of seats");
	}

	void set_venuename(char* _name) {
		if (_name != nullptr) {
			this->VenueName = new char[strlen(_name) + 1];		
			strcpy_s(this->VenueName, strlen(_name) + 1, _name);
	    }
		else
			throw invalid_argument("Invalid name");
	}

	void set_rows(int _rows, int* _seats_per_row) {
		if (_rows > 0 && _seats_per_row != nullptr) {
			this->rows = _rows;
			this->seats_per_row = new int[_rows + 1];		
			for (int i = 0; i < _rows; i++) {			
				this->seats_per_row[i] = _seats_per_row[i];
		    }
		}
		else
			throw invalid_argument("Invalid number of rows");
	}

	//getters

	char* get_venuename() { return this->VenueName; }
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
		return (string)this->VenueName;
	}

	//destructor

	~Venue() {
		delete[] this->VenueName;
		delete[] this->seats_per_row;
	}

	Venue& operator=(const Venue& ven) {
		if (this->VenueName != nullptr)
			delete[] this->VenueName;
		this->VenueName = new char[strlen(ven.VenueName) + 1];
		strcpy_s(this->VenueName, strlen(ven.VenueName) + 1, ven.VenueName);

		this->maxSeats = ven.maxSeats;

		this->rows = ven.rows;

		this->seats_per_row = new int[ven.rows + 1];
		for (int i = 0; i < ven.rows; i++) {
			this->seats_per_row[i] = ven.seats_per_row[i];
		}

		return *this;
	}

	friend ostream& operator<<(ostream& console, Venue& s);

	friend istream& operator>>(istream& console, Ticket_Manager& s);

	friend istream& operator>>(istream& console, Venue& v);
};

