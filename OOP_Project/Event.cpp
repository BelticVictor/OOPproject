#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event {
	string name;
	string start_time; //the hour it starts between 0 and 24
	string finish_time; //----||---- finishes ----||----
	string date;
public:
	//constructor

	Event(string name, string start_time, string finish_time, string date) :name(name), start_time(start_time), finish_time(finish_time), date(date) {}

	//copy constructor

	Event(const Event& copy) : name(copy.name), start_time(copy.start_time), finish_time(copy.finish_time), date(copy.date) {}

	//default consturctor

	Event() {
		this->name = "Event";
		this->start_time = "00:00";
		this->finish_time = "00:00";
		this->date = "01-01-2003";
	}

	//setters

	void set_name(string _name) {
		if(_name.empty())
			this->name = _name;
	}

	void set_date(string _date) {
		if (_date.empty())
			this->date = _date;
	}

	void set_time(string _start_time, string _finish_time) {
		if (_start_time.empty())
			this->start_time = _start_time;
		if (_finish_time.empty())
			this->finish_time = _finish_time;
	}


	//getters

	string get_name() { return this->name; }
	string get_date() { return this->date; }
	string get_start_time() { return this->start_time; }
	string get_finish_time() { return this->finish_time; }

};