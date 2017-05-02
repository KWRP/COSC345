#include "Month.h"
#include <string>

Month::Month(string date) {
	this->date = date;
	int year = stoi(date.substr(6, 4));
	int mon = stoi(date.substr(3, 2));
	int numDays = 0;
	if (mon ==2 && year % 4 == 0 && year % 100 && year % 400) {//equation for leap year
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
		Day dayx(to_string(i));
		day.push_back(dayx);
	}

}
Month::Month() {
	cout << "please add a month and year." << endl;
}
Month::~Month() {}
Day Month::getDay(string date) {
	int theDay = stoi(date.substr(0, 2));
	return day.at(theDay);
}
string Month::toString() {
	string result = "";
	result = "Date is " + date;
	result = +"the number of days are " + to_string(day.size());
	return result;
}
