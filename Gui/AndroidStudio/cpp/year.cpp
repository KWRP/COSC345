#include <string>
#include "include/year.hpp"
#include "include/helpers.hpp"

using namespace std;

Year::Year(string date) {
	this->date = date;
    setMonths(date);
}

Year::Year() {}
Year::~Year() {}

Month Year::getMonth(int mon) {
	return months.at(mon -1);
}

void Year::setMonths(string date) {
    Month month(date);
    months.push_back(month);
}

string Year::toString() {
	string result = "";

	result = "The year is " + date + " there are " + numToString(months.size()) + " in a year.";
	return result;
}

