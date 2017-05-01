#pragma once
#ifndef WEEK_H
#define WEEK_H

#include <string>
#include <vector>
#include "day.hpp"

class Week {
private:
	std::string date;
	std::vector<Day> week;

public:
	std::string getDate() { return date; }
	void setDate(std::string date) { this->date = date; }
	Day getDay(std::string day);
	std::string toString();

	Week(std::string date);
	Week();
	~Week();
};
#endif