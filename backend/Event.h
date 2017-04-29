#pragma once
#ifndef EVENT_H	
#define EVENT_H
//#include <iostream>
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

#endif