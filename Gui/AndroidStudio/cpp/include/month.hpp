#pragma once
#ifndef MONTH_H
#define MONTH_H

#include <string>
#include <vector>
#include "day.hpp"

class Month {
private:
	std::vector<Day> day; //maybe use an arrray
	std::string date;
public:
	void setDate(std::string date) { this->date = date; }
	std::string getDate() { return date; }
	std::string toString();
	Day getDay(std::string theDay);

	Month(std::string date);
	Month();
	~Month();
};

#endif