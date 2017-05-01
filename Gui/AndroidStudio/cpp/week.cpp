#include "include/week.hpp"
#include "include/helpers.hpp"
#include <cstdlib>


using namespace std;
using std::string;
Week::Week(string date) {
	this->date = date;
	int mon = atoi(date.substr(3, 1).data());
	int daysInMonth = 1;
	if (mon == 04 || mon == 06 || mon == 9 || mon == 11) {
		daysInMonth = 30;
	}
	else if (mon == 02) {
		int year = atoi(date.substr(6, 3).data());
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
	for (int i = 0; i < 7; i++) {
		int dateOfWeek = atoi(date.substr(0, 1).data()) + i;
		if (dateOfWeek == daysInMonth) {
			dateOfWeek = 1;
			int month = atoi(date.substr(2, 2).data());
			int year = atoi(date.substr(5, 4).data());
			if (mon == 12) {
				year++;
				date = "01/01/" + numToString(year);
			}
			else {
				date = "01/" + numToString(month + 1) + "/" + numToString(year);
			}
		}
		Day dayx(date);
		this->week.push_back(dayx);
	}

}
Week::Week() {}
Week::~Week() {}
Day Week::getDay(string day) {
	int startDateOfWeek = atoi(date.substr(0,2).data());
	int theDay = atoi(day.substr(0.2).data());
	int dayOfWeek = startDateOfWeek - theDay;
	return week.at(dayOfWeek -1);
}
string Week::toString() {
	string result = "";
	result = date;
	return result;
}
