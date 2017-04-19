/*Structure.
Day->month->years
Day->week.*/


#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;
class Event {
private:
	string title;
	string description;
	int startTime;
	int duration;

public:
	void setTitle(string title) { this->title = title; }
	void setDecription(string decription) { this->description = decription; }
	void setStartTime(int startTime) { this->startTime = startTime; }
	void setDuration(int duration) { this->duration = duration; }
	string getTitle() const { return title; }
	string getDescription() const { return description; }
	int getStartTime() const { return startTime; }
	int getDuration() const { return duration; }

	Event(string, string, int, int);
};//will be changed with the xml api.
Event::Event(string title, string description, int strartTime, int duration) {
	this->description = description;
	this->title = title;
	this->startTime = startTime;
	this->duration = duration;
}
class Day {
private:
	string date;
	vector<Event> events;

public:
	string getDate() { return date; }
	void setDate(string date) { this->date = date; }
	void setEvent(string name, string description, int startTime, int duration);
	string getEvent();
	string toString();
	Day(string);
	Day();
	~Day();
};
Day ::Day(string date) {
	this->date = date;
}
Day ::Day() {
	/*	time_t t = time(0);
	struct tm *now = localtime(&t);
	date = now->tm_year + now->tm_mon + now->tm_mday;*/
}
Day::~Day() {}
void Day::setEvent(string name, string description, int startTime, int duration) { // maybe add colour here.
	events.push_back(Event(name, description, startTime, duration));
}

string Day::getEvent() {
	string result = "";
	for (unsigned int i = 0; i < events.size(); i++) {//need to fix times.
		result = "you have " + events[i].getTitle() + "\n Description :" + events[i].getDescription()+"\n starting at " +to_string(events[i].getStartTime()) +" till "+to_string(events[i].getDuration());
	}
	return result;

}
string Day::toString() {
	string result = "";
	result = "Date : " + date + "\nEvents : " + getEvent() + "\n";
	return result;
}

class Month{
private:	vector<Day> day;
			string date;
			int year;
public:
	void setDate(string date) { this->date = date; }
	void setYear(int year) { this->year = year; }
	string getDate() { return date; }
	string toString();
	Day getDay(string theDay);

	Month(string, int);
	Month();
	~Month();
};
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

class Year{
private:
	vector<Month>months;
	string date;

public:
	void setDate(string date) { this->date = date; }
	string getDate() { return date; }
	string toString();
	Month getMonth(int mon);

	Year(string);
	~Year();

};
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

class Week{
private:
	string date;
	vector<Day> week;

public:
	string getDate() { return date; }
	void setDate(string date) { this->date = date; }
	Day getDay(string day);
	string toString();

	Week(string date);
	~Week();
};
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
		int dateOfWeek = (stoi(date.substr(0, 1)) + i) %daysInMonth;
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
int main() {
	cout << "hello world1" << endl;
	Day day("5");
	day.setDate("21");
	cout << day.toString() << endl;
//	cout << "hello world" << endl;
	day.setEvent("test", "testing days", 0, 10);
	Week week("21/03/1996");
	cout <<week.toString() << endl;
	cout << day.toString() << endl;
	Month month("feb", 2004);
	cout << month.toString() << endl;
	return 0;
}