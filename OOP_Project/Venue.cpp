#include <iostream>
#include <string>
using namespace std;

class Venue {
	char* name=nullptr;
	int maxSeats;
	int rows;
	int* seats_per_row=nullptr; //seats_per_row[i]=number of seats on row i
	//dont forget to add zones

public:

	//constructor

	Venue(char* _name, int _maxSeats, int _rows, int* _seats_per_row) : maxSeats(_maxSeats) {
		this->set_name(_name);
		this->set_rows(_rows, _seats_per_row);
	}

	//default constructor
	
	Venue() {
		this->maxSeats = 0;
		this->rows = 0;

		this->name = new char[strlen("Venue") + 1];
		strcpy_s(this->name, strlen("Venue") + 1, "Venue");

		this->seats_per_row = new int[1];
		this->seats_per_row[0] = 0;
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
		if(_maxSeats > 0)
			this->maxSeats = _maxSeats;
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

	//destructor

	~Venue() {
		delete[] this->name;
		delete[] this->seats_per_row;
	}
	//add a function that checks that row*seats per row < maxSeats
};