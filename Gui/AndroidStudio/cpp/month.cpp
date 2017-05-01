#include "include/month.hpp"
#include <cstdlib>
#include "include/helpers.hpp"

using std::string;

Month::Month(string date) {
	this->date = date;
	int year = atoi(date.substr(5, 4).data());
	int mon = atoi(date.substr(2, 2).data());
	int numDays = 0;
	if (mon ==2 && year % 4 == 0 && year % 100 && year % 400) {
		numDays = 29;
	}
	else {
		if (mon == 2) {
			numDays = 28;
		}

		if (mon == 4 || mon == 7 || mon == 9 || mon == 11) {
			numDays = 30;
		}
		else {
			numDays = 31;
		}
	}
	for (int i = 0; i < numDays; i++) {
		Day dayx(numToString(i));
		day.push_back(dayx);
	}

}
Month::Month() {
	std::cout << "please add a month and year." << std::endl;
}

Month::~Month() {}

Day Month::getDay(string date) {
	int theDay = atoi(date.substr(0, 2).data());
	return day.at((u_long)theDay);
}
string Month::toString() {
	string result = "";
	result = "Date is " + date;
	result += "the number of days are " + numToString(day.size());
	return result;
}


