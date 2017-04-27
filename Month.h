#pragma once
#ifndef MONTH_H
#define MONTH_H
#include "Day.h"

class Month {
private:	vector<Day> day;
			string date;
			int year;
public:
	void setDate(string date) { this->date = date; }
	void setYear(int year) { this->year = year; }
	string getDate() { return date; }
	string toString();
	Day getDay(string theDay);

	Month(string, int);
	Month();
	~Month();
};

#endif