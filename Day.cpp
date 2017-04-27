#include "Day.h"

Day::Day(string date) {
	this->date = date;
}
Day::Day() {
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
		result = "you have " + events[i].getTitle() + "\n Description :" + events[i].getDescription() + "\n starting at " + to_string(events[i].getStartTime()) + " till " + to_string(events[i].getDuration());
	}
	return result;

}
string Day::toString() {
	string result = "";
	result = "Date : " + date + "\nEvents : " + getEvent() + "\n";
	return result;
}