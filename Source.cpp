/*Structure.
Day->month->years
Day->week.*/

#include<iostream>;
#include<vector>;
#include<ctime>;
#include<string>;

using namespace std;

class Day {
private:
	string date;
	vector< vector<string> > events;

public:
	string getDate() { return date; }
	void setEvent(string name, string description);
	string getEvent();
	string toString();
	Day(string date) {
		this->date = date;
	}
	Day() {
		time_t t = time(0);
		struct tm *now = localtime(&t);
		date = now->tm_year + now->tm_mon + now->tm_mday;
	}
};

void Day::setEvent(string name, string desription){ // maybe add colour here.
	vector& lastElement = events.back;
	events[lastElement].push_back(name);
	events[lastElement].push_back(desription);
}

string Day::getEvent() {
	string result = "";
	for (int i = 0; i < events.size; i++) {
		result = "you have " + events[i].at(1) + "\n Description :" + events[i].at(2);
	}
	return result;

}
string Day::toString() {
	cout << "Date : " << date << endl;
	cout << getEvent() << endl;
}

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
		if (date == "feb" && year%4 ==0 && year %100 && year%400) {
			numDays = 29;
		}
		else {
			if (date = "feb") {
				numdays = 28;
			}

			if (date == "april" || date == "jun" || date == "sep" || date == "nov") {
				numDays = 30;
			}
		}
		for (int i = 0; i < numDays; i++) {
			day[i] = Day((string)i);
		}

	}
	Month() {
		cout << "please add a month and year." << endl;
	}


};




int main() {
	return 0;
}