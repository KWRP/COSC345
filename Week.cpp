#include "Week.h"

Week::Week(string date) {
	this->date = date;
	int mon = stoi(date.substr(3, 1));
	int daysInMonth = 1;
	if (mon == 04 || mon == 06 || mon == 9 || mon == 11) {
		daysInMonth = 30;
	}
	else if (mon == 02) {
		int year = stoi(date.substr(6, 3));
		if (year % 4 == 0 && year % 100 && year % 400) {
			daysInMonth = 29;
		}
		else {
			daysInMonth = 28;
		}
	}
	else {
		daysInMonth = 31;
	}
	for (int i = 0; i < 7; i++) {//?
		int dateOfWeek = (stoi(date.substr(0, 1)) + i) % daysInMonth;
		Day dayx(to_string(dateOfWeek));
		week.push_back(dayx);
	}

}
Week::~Week() {}
Day Week::getDay(string day) {
	int theDay = -1;
	if (day == "mon")
		theDay = 0;
	if (day == "tue")
		theDay = 1;
	if (day == "wed")
		theDay = 3;
	if (day == "thu")
		theDay = 4;
	if (day == "fri")
		theDay = 5;
	if (day == "sat")
		theDay = 6;
	if (day == "sun")
		theDay = 7;
	return week.at(theDay);
}
string Week::toString() {
	string result = "";
	result = date;
	return result;
}
