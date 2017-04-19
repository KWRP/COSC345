#include <iostream>
#include <stdlib.h>
#include "tinyxml2.h"

bool Test(const char* day = 0, const char* month = 0, const char* year = 0){

	bool check = checkDate(day,month,year);
	
	if (check == false) {
		return create(day, month, year);
	}
	else{
		return true;
	}
}

bool checkDate(const char* day = 0, const char* month = 0, const char* year = 0) {

	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != tinyxml2::XML_SUCCESS) return false;

	tinyxml2::XMLNode* elementYear = xml_doc.FirstChildElement(year);
	if (elementYear == nullptr) return false;

	tinyxml2::XMLElement* elementMonth = elementYear->FirstChildElement(month);
	if (elementMonth == nullptr) return false;

	tinyxml2::XMLElement* elementDay = elementMonth->FirstChildElement(day);
	if (elementDay == nullptr) return false;

	return true;
}

bool create(const char* day = 0, const char* month = 0, const char* year = 0) {

	tinyxml2::XMLDocument xmlDoc;

	int yearInt = atoi(year);
	int monthInt = atoi(month);
	int dayInt = atoi(day);
	
	if (yearInt <= 0 || monthInt <= 0 || monthInt > 12 || dayInt <= 0 || dayInt >= 31) { return false; }
	
	else {

		tinyxml2::XMLNode * elementYear = xmlDoc.NewElement(year);
		xmlDoc.InsertFirstChild(elementYear);

		tinyxml2::XMLElement * elementMonth = xmlDoc.NewElement(month);
		elementYear->InsertEndChild(elementMonth);

		tinyxml2::XMLElement * elementDay = xmlDoc.NewElement(day);
		elementMonth->InsertEndChild(elementDay);
	}

	return true;
}

int main()
{
	if (Test() == true) {
		std::cout << "success" << std::endl;
	}
	else {
		std::cout << "fail" << std::endl;
	}
}

