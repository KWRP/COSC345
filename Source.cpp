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
	result = "Date : " + date +getEvent();
	return result;
}

class Month : public Day {
private:
	vector<Day> day;
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

