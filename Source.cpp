/*Structure.
Day->month->years
Day->week.*/

#include<iostream>
#include<vector>
#include<ctime>
#include<string>

using namespace std;


class Event {
private:
	string eventTime;
	string eventName;
	string eventDescript;

public: 
	Event(string time, string eventName, string eventDescript) {
		this->eventTime = time;
		this->eventName = eventName;
		this->eventDescript = eventDescript;
	}
	Event() {}
	~Event() {}

	string showEvent() {
		return "Event : " + eventName + " Time: " + 
			eventTime + " Event Descript: " + eventDescript;
	}
};


class Day {
private:
	string date;
	vector<Event> events;

public:
	string getDate() { return date; }
	void createEvent(string time, string name, string description);
	void displayEvents();
	
	Day(string date) {
		this->date = date;
	}
	Day() {
		time_t t = time(0);
		struct tm *now = localtime(&t);
		date = now->tm_year + now->tm_mon + now->tm_mday;
	}
	~Day(){}
};

void Day::createEvent(string time, string name, string description) { // maybe add colour here.
	Event newEvent = Event(time, name, description);
	events.push_back(newEvent);
}

void Day::displayEvents() {
	cout << "The events for " << date << " are as follows: " << endl;

	for (int i = 0; i < events.size() -1; i++){
		cout << events[i].showEvent() << endl;
	}
}

/*
class Month : public Day {
private:
vector<Day> day;
string date;
int year;
public:
void setDate(string date) { this->date = date; }
string getDate() { return date; }
string toString();

Month(string date, int year) {
this->date = date;
this->year = year;
int numDays = 0;
if (date == "feb" && year % 4 == 0 && year % 100 && year % 400) {
numDays = 29;
}
else {
if (date == "feb") {
numDays = 28;
}

if (date == "april" || date == "jun" || date == "sep" || date == "nov") {
numDays = 30;
}
}
for (int i = 0; i < numDays; i++) {
day[i] = Day();
}

}
Month() {
cout << "please add a month and year." << endl;
}


};
*/
int main(int argc, char* argv[])
{
	Day day = Day("Monday 1st of March");

	std::cout << "Hello" << std::endl;
	bool loop = true;;
	while (loop) {
		std::cout << "Please enter a name for the event (or type 'exit' to list all events): " << std::endl;
		string eventName = "";
		std::cin >> eventName;
		if (eventName == "exit") {
			loop = false;
		}
		else {
			std::cout << "Please enter a description of the event: " << std::endl;
			string eventDescript = "";

			std::cin >> eventDescript;
			std::cout << "Please enter a start time for the event: " << std::endl;
			string eventTime = "";

			std::cin >> eventTime;
			day.createEvent(eventTime, eventName, eventDescript);
		}
	}
	// display events
	day.displayEvents();
	int i = 0;
	std::cin >> i;
}
