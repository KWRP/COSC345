#pragma once
#ifndef YEAR_H
#define YEAR_H

#include "Month.h"

class Year {
private:
	vector<Month>months;
	string date;

public:
	void setDate(string date) { this->date = date; }
	string getDate() { return date; }
	string toString();
	Month getMonth(int mon);

	Year(string);
	~Year();

};
#endif