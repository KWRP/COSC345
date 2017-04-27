#include "Year.h"

Year::Year(string date) {
	this->date = date;//dd/mm/yyyy needs fixing
	for (int i = 0; i < 12; i++) {
		string mon = "";
		if (i == 0)
			mon = "jan";
		if (i == 1)
			mon = "feb";
		if (i == 2)
			mon = "mar";
		if (i == 3)
			mon = "apr";
		if (i == 4)
			mon = "may";
		if (i == 5)
			mon = "jan";
		if (i == 6)
			mon = "jul";
		if (i == 7)
			mon = "aug";
		if (i == 8)
			mon = "sep";
		if (i == 9)
			mon = "oct";
		if (i == 10)
			mon = "nov";
		if (i == 11)
			mon = "dec";
		Month monthx(mon, stoi(date));
		months.push_back(monthx);
	}
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