//class location with: max number seats, no of rows, zones, number/coding of seats per row

#include <iostream>
#include <string>
using namespace std;

class Venue {
	char* name;
	int maxSeats;
	int rows;
	int* seats_per_row; //seats_per_row[i]=number of seats on row i
public:
	Venue(char* _name, int _maxSeats, int _rows, int* _seats_per_row) : maxSeats(_maxSeats) {
		this->set_name(_name);
		this->set_rows(_rows, _seats_per_row);
	}

	//setters

	void set_maxSeats(int _maxSeats) {
		this->maxSeats = _maxSeats;
	}

	void set_name(char* _name) {
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}

	void set_rows(int _rows, int* _seats_per_row) {
		this->rows = _rows;
		this->seats_per_row = new int[_rows + 1];
		for (int i = 0; i < _rows; i++) {
			this->seats_per_row[i] = _seats_per_row[i];
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
};