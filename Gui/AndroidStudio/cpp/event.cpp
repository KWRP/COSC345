#include "include/event.hpp"

using namespace std;
using std::string;
Event::Event(string title, string description, int startTime, int duration) {
	this->description = description;
	this->title = title;
	this->startTime = startTime;
	this->duration = duration;
}

Event::Event(){};
Event::~Event(){};