#include <iostream>
#include "Event.h"
#include <string>

Event::Event(string title, string description, int strartTime, int duration) {//will change when the xml for event is working
	this->description = description;
	this->title = title;
	this->startTime = startTime;
	this->duration = duration;
}
string Event::toString() {
	string result = "";
	result = "title :" + title + "\ndescription :" + description + "\nstart time :" + to_string(startTime) + "\nduration :"+ to_string(duration);//will change when the xml for event is working
	return result;
}