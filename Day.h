#pragma once
#ifndef DAY_H
#define DAY_H
#include<vector>
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

class Day {
private:
	string date;
	vector<Event> events;

public:
	string getDate() { return date; }
	void setDate(string date) { this->date = date; }
	void setEvent(string name, string description, int startTime, int duration);
	string getEvent();
	string toString();
	Day(string);
	Day();
	~Day();
};

#endif