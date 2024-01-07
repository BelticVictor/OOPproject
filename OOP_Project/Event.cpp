#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event {
protected:
	string EventName;
	string start_time; //the hour it starts between 0 and 24
	string finish_time; //----||---- finishes ----||----
	string date;
public:

	//default consturctor

	Event() {
		this->EventName = "Event";
		this->start_time = "00:00";
		this->finish_time = "00:00";
		this->date = "01-01-2003";
	}

	//constructor

	Event(string name, string start_time, string finish_time, string date) :EventName(name), start_time(start_time), finish_time(finish_time), date(date) {}

	//copy constructor

	Event(const Event& copy) : EventName(copy.EventName), start_time(copy.start_time), finish_time(copy.finish_time), date(copy.date) {}

	//setters

	void set_eventname(string _name) {
		if (_name.empty()) {
			this->EventName = _name;
		}
		else
			throw invalid_argument("Invalid name");
	}

	void set_date(string _date) {
		if (_date.empty()) {
			this->date = _date;
		}
		else
			throw invalid_argument("Invalid date");
	}

	void set_time(string _start_time, string _finish_time) {
		if (_start_time.empty()) {
			this->start_time = _start_time;
		}
		else
			throw invalid_argument("Invalid time");
		if (_finish_time.empty()) {
			this->finish_time = _finish_time;
		}
		else
			throw invalid_argument("Invalid time");
	}

	//getters

	string get_eventname() { return this->EventName; }
	string get_date() { return this->date; }
	string get_start_time() { return this->start_time; }
	string get_finish_time() { return this->finish_time; }

	//generic methods

	int convertHour(string time) {
		int hour = 0;
		for (int i = 0; i < 2; i++) {
				hour = hour * 10 + (time[i] - '0');
		}
		return hour;
	}

	int convertMinute(string time) {
		int minute = 0;
		for (int i = 3; i < 5; i++) {
				minute = minute * 10 + (time[i] - '0');
		}
		return minute;
	}

	int duration() {
		int duration;
		duration = (convertHour(this->finish_time) * 60 + convertMinute(this->finish_time)) - (convertHour(this->start_time) * 60 + convertMinute(this->start_time));
		return duration;
	}

	//overloads

	void operator+(int time) {
		int start_hour = convertHour(this->start_time) + time;
		for (int i = 0; i < 2; i++) {
			if (i == 0)
				this->start_time[i] = (start_hour / 10) + '0';
			else
				this->start_time[i] = (start_hour % 10) + '0';
		}
		int finish_hour = convertHour(this->finish_time) + time;
		for (int i = 0; i < 2; i++) {
			if (i == 0)
				this->finish_time[i] = (finish_hour / 10) + '0';
			else
				this->finish_time[i] = (finish_hour % 10) + '0';
		}
	}
	bool operator>(string time) {
		int timeHour = convertHour(this->start_time);
		int timeMinute = convertMinute(this->start_time);
		int compareHour = convertHour(time);
		int compareMinute = convertMinute(time);
		if (timeHour == compareHour)
			if (timeMinute > compareMinute)
				return true;
			else
				return false;
		else if (timeHour > compareHour)
			return true;
		else
			return false;
	}

	bool operator<(string time){
		int timeHour = convertHour(this->start_time);
		int timeMinute = convertMinute(this->start_time);
		int compareHour = convertHour(time);
		int compareMinute = convertMinute(time);
		if (timeHour == compareHour)
			if (timeMinute > compareMinute)
				return false;
			else
				return true;
		else if (timeHour > compareHour)
			return false;
		else
			return true;
	}

	Event& operator=(const Event& even) {
		this->EventName = even.EventName;
		this->date = even.date;
		this->start_time = even.start_time;
		this->finish_time = even.finish_time;

		return *this;
	}

	friend ostream& operator<<(ostream& console, Event& s);
	friend istream& operator>>(istream& console, Event& s);
};