#pragma once
#ifndef DAY_H
#define DAY_H

#include <vector>
#include <string>
#include "event.hpp"

class Day {
private:
	std::string date;
	std::vector<Event> events;

public:
	std::string getDate() { return date; }
	void setDate(std::string date) { this->date = date; }
	void setEvent(std::string name, std::string description, int startTime, int duration);
	int numOfEvents() { return events.size(); }
	Event getEvent(int eventNumber);
	void addEvent(std::string title, std::string description, int time, int duration);
	std::string toString();
	Day(std::string date);
	Day();
	~Day();
};

#endif