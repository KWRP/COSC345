#include <iostream>
#include <stdlib.h>
#include "tinyxml2.h"

bool Test(const char* day = 0, const char* month = 0, const char* year = 0){

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

int main()
{
	if (Test() == true) {
		std::cout << "success" << std::endl;
	}
	else {
		std::cout << "fail" << std::endl;
	}
}

