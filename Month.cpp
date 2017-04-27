#include "Month.h"

Month::Month(string date, int year) {
	this->date = date;
	this->year = year;
	int numDays = 0;
	if (date == "feb" && year % 4 == 0 && year % 100 && year % 400) {
		numDays = 29;
	}
	else {
		if (date == "feb") {
			numDays = 28;
		}

		if (date == "apr" || date == "jun" || date == "sep" || date == "nov") {
			numDays = 30;
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
Day Month::getDay(string theDay) {
	return day.at(stoi(theDay));
}
string Month::toString() {
	string result = "";
	result = "The month is " + date + " and the year " + to_string(year);
	result = +"the number of days are " + to_string(day.size());
	return result;
}