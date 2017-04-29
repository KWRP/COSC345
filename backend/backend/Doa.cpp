#include <iostream>
#include "Year.h"
#include "Week.h"

using namespace std;

Year makeYear(string date) {
	return Year(date);
}
Month getMonth(Year year, string date) {
	int mon = stoi(date.substr(2, 2));
	return year.getMonth(mon);
}

Day getDay(Year year, string date) {
	return getDay(getMonth(year, date), date);
}

Day getDay(Month month, string date) {
	return(month.getDay(date));
}

Day getDay(Week week, string date) {
	return week.getDay(date);
}

Event getEventnum(Day day, string date, int numberOfEvent) {
	return day.getEvent(numberOfEvent - 1);
}

void setEvent(Year year,string date, string title, string description, int time, int duration) {
	Day day = getDay(year, date);
	day.addEvent(title, description, time, duration);
	
}

void setEvent(Week week, string date, string title, string description, int time, int duration) {
	Day day = getDay(week, date);
	day.addEvent(title, description, time, duration);

}


int main() {
	Year year("01/01/2017");
	cout << "hello world" << endl;
}