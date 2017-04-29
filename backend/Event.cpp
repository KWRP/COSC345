#include <iostream>
#include "Event.h"

Event::Event(string title, string description, int strartTime, int duration) {
	this->description = description;
	this->title = title;
	this->startTime = startTime;
	this->duration = duration;
}