#include "Year.h"
#include <string>

Year::Year(string date) {
	this->date = date;
	for (int i = 0; i < 12; i++) {//changing though the months
		string month = "";
		if (i < 9)
			month = "0" + to_string(i+1);
		else
			month = to_string(i+1);
		date = date.erase(3, 2);
		date = date.insert(3, month);
		Month monthx(date);
		months.push_back(monthx);
	}
}
Year::~Year() {}
Month Year::getMonth(string date) {
	int mon = stoi(date.substr(3, 2));
	return months.at(mon - 1);
}
string Year::toString() {
	string result = "";
	result = "The year is " + date + " there are " + to_string(months.size()) + "months in a year.";
	return result;
}