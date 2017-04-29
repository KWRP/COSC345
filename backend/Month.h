#pragma once
#ifndef MONTH_H
#define MONTH_H
#include "Day.h"

class Month {
private:	vector<Day> day; //maybe use an arrray
			string date;
public:
	void setDate(string date) { this->date = date; }
	string getDate() { return date; }
	string toString();
	Day getDay(string theDay);

	Month(string);
	Month();
	~Month();
};

#endif