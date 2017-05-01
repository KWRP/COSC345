#pragma once
#ifndef EVENT_H	
#define EVENT_H

#include <string>

class Event {
private:
	std::string title;
	std::string description;
	int startTime;
	int duration;

public:
	void setTitle(std::string title) { this->title = title; }
	void setDecription(std::string decription) { this->description = decription; }
	void setStartTime(int startTime) { this->startTime = startTime; }
	void setDuration(int duration) { this->duration = duration; }
	std::string getTitle() const { return title; }
	std::string getDescription() const { return description; }
	int getStartTime() const { return startTime; }
	int getDuration() const { return duration; }

	Event(std::string title, std::string description, int startTime, int duration);
	Event();
	~Event();
	
};//will be changed with the xml api.

#endif