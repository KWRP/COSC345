#include "Year.h"
Year::Year(string date) {
	this->date = date;
	Month monthx(date);
	months.push_back(monthx);
}
Year::~Year() {}
Month Year::getMonth(int mon) {
	return months.at(mon - 1);
}
string Year::toString() {
	string result = "";
	result = "The year is " + date + " there are " + to_string(months.size()) + " in a year.";
	return result;
}