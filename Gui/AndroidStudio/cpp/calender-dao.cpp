#include <iostream>
#include "include/year.hpp"
#include "include/week.hpp"
#include "include/event.hpp"
#include <cstdlib>

using namespace std;

Year makeYear(string date) {
	return Year(date);
}
Month getMonth(Year year, string date) {
	int mon = atoi(date.substr(2, 2).data()); //changed from stoi
	return year.getMonth(mon);
}

Day getDay(Year year, string date) {
	return getMonth(year, date).getDay(date);
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


//int main() {
//	Year year("01/01/2017");
//	cout << "hello world" << endl;
//}
