#include <iostream>
#include "Year.h"
#include "Week.h"
#include<string>

using namespace std;
/*need to change the methods parm for pointer*/
Year makeYear(string date) {
	return Year(date);
}
Month getMonth(Year year, string date) {
	return year.getMonth(date);
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

void setEvent(Year year,string date, string title, string description, int time, int duration) {//need to change for pointer/ references
	Day day = getDay(year, date);
	day.addEvent(title, description, time, duration);
	cout << day.toString() << endl;
	day = day;
}

void setEvent(Week week, string date, string title, string description, int time, int duration) {
	Day day = getDay(week, date);
	day.addEvent(title, description, time, duration);

}


int main() {
	string quit;
	cout << "hello world" << endl;

	Year year = Year("01/01/2017");
	setEvent(year,"02.05.2017", "test", "testing set event", 245, 5);
	cout << getDay(year, "02.05.2017").toString() << endl;
	cout << getEventnum(getDay(year, "02.05.2017"), "02.05.2017", 1).toString() << endl;
	cin >> quit;
	while (quit != "q") {
		cin >> quit;
	}
	return 0;
}
