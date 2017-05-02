#pragma once
#ifndef YEAR_H
#define YEAR_H

#include <string>
#include <vector>
#include "month.hpp"

class Year {
private:
	std::vector<Month>months;
	std::string date;

public:
	void setDate(std::string date) { this->date = date; }
	std::string getDate() { return date; }
	std::string toString();
	Month getMonth(int mon);
	void setMonths(std::string date);
	Year(std::string date);
	Year();
	~Year();

};
#endif