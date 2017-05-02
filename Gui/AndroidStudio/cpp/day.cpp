#include "include/day.hpp"
#include "include/helpers.hpp"
#include "include/event.hpp"

using namespace std;
using std::string;
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
	events.push_back(Event::Event(name, description, startTime, duration));
}

Event Day::getEvent(int eventNumber) {
	return events.at(eventNumber-1);

}
string Day::toString() {
	string result = "";
	result = "Date : " + date + "\n number of Events : " + numToString(events.size()) + "\n";
	return result;
}

void Day::addEvent(string title, string description, int time, int duration) {
	events.push_back(Event(title, description, time, duration));
}