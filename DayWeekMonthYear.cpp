/*Structure.
Day->month->years
Day->week.*/


#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

class Day {
private:
	string date;
	vector< vector<string> > events;

public:
	string getDate() { return date; }
	void setDate(string date) { this->date = date; }
	void setEvent(string name, string description);
	string getEvent();
	string toString();
	Day(string date) {
		this->date = date;
	}
	Day() {
	/*	time_t t = time(0);
		struct tm *now = localtime(&t);
		date = now->tm_year + now->tm_mon + now->tm_mday;*/
	}
};

void Day::setEvent(string name, string description){ // maybe add colour here.
	//vector<string> &lastElement = events.back;
	events[events.size()].push_back(name);
	events[events.size()].push_back(description);
}

string Day::getEvent() {
	string result = "";
	for (unsigned int i = 0; i < events.size(); i++) {//I think that casting is bad there need to find another way.
		result = "you have " + events[i].at(1) + "\n Description :" + events[i].at(2);
	}
	return result;

}
string Day::toString() {
	string result = "";
	result = "Date : " + date + "\nEvents : " +getEvent()+endl;
	return result; 
}

class Month : public Day {
private:	vector<Day> day;
	string date;
	int year;
public:
	void setDate(string date) { this->date = date; }
	void setYear(int year) { this->year = year; }
	string getDate() { return date; }
	string toString();
	Day getDay(string theDay);

	Month(string date, int year) {
		this->date = date;
		this->year = year;
		int numDays = 0;
		if (date == "feb" && year%4 ==0 && year %100 && year%400) {
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
			day.push_back(Day(to_string(i)));
		}

	}
	Month() {
		cout << "please add a month and year." << endl;
	}
};

Day Month::getDay(string theDay) {
	return day.at(stoi(theDay));
}
string Month::toString() {
	string result = "";
	result ="The month is " + date + " and the year " + to_string(year);
	result = +"the number of days are " + to_string(day.size());
	return result;
}

class Year : public Month {
private:
	vector<Month>months;
	string date;

public:
	void setDate(string date) { this->date = date; }
	string getDate() { return date; }
	string toString();
	Month getMonth(int mon);

	Year(string date) {
		this->date = date;
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

			months.push_back(Month(mon, stoi(date)));
		}
	}

};

Month Year::getMonth(int mon){
	return months.at(mon - 1);
}
string Year::toString() {
	string result = "";
	result = "The year is " + date + " there are " + to_string(months.size()) + " in a year.";
	return result;
}

class Week : public Day {
private:
	string date;
	vector<Day> week;

public:
	string getDate() { return date; }
	void setDate(string date) { this->date = date; }
	Day getDay(string day);
	string toString();

	Week(string date) {
		this->date = date;
		int mon = stoi(date.substr(2, 2));
		int daysInMonth = 1;
		if (mon == 04 || mon == 06 || mon == 9 || mon == 11) {
			 daysInMonth = 30;
		}
		else if (mon = 02) {
			int year = stoi(date.substr(5, 4));
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
		for (int i; i < 7; i++) {
			int dateOfWeek = stoi(date.substr(0, 2)) + i %daysInMonth;
			week.push_back(Day(date.substr(dateOfWeek)));
		}

	}

};

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
int main() {
	cout << "hello world" << endl;
	cout << "hello world1" << endl;
	Day day("5");
	cout << day.toString() << endl;
	day.setEvent("test", "testing days");
	cout << day.toString() << endl;
	return 0;
}