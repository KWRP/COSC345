/*Structure.
Day->month->years
Day->week.*/

#include<iostream>
#include<vector>
#include<ctime>
#include<string>

using namespace std;

class Day {
private:
	string date;
	vector< vector<string> > events;

public:
	string getDate() { return date; }
	void setEvent(string name, string description);
	string getEvent();
	string show();
	Day(string date) {
		this->date = date;
	}
	Day() {
		time_t t = time(0);
		struct tm *now = localtime(&t);
		date = now->tm_year + now->tm_mon + now->tm_mday;
	}
};

void Day::setEvent(string name, string desription) { // maybe add colour here.
	vector<string>& lastElement = events.back();
	//events.push_back(<vector>name);
	//events.push_back(desription);
}

string Day::getEvent() {
	string result = "";
	for (int i = 0; i < events.size(); i++) {
		result += "you have " + events[i][0] + "\n Description :" + events[i][1];
	}
	return result;
}

string Day::show() {
	return "Date : " + date + " Event: " + getEvent();
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
	Day day = Day("Monday 1st");

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
			day.setEvent(eventName, eventDescript);
		}
	}
	// display events
	std::cout << day.show() << std::endl;
	int i = 0;
	std::cin >> i;
}