#include <iostream>
#include <stdlib.h>
#include "tinyxml2.h"

using namespace tinyxml2;
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

bool checkDate(const char* day = 0, const char* month = 0, const char* year = 0) {

	XMLDocument xml_doc;

	XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != XML_SUCCESS) return false;

	XMLNode* elementYear = xml_doc.FirstChildElement(year);
	if (elementYear == nullptr) return false;

	XMLElement* elementMonth = elementYear->FirstChildElement(month);
	if (elementMonth == nullptr) return false;

	XMLElement* elementDay = elementMonth->FirstChildElement(day);
	if (elementDay == nullptr) return false;

	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);

	return true;
}

bool createDate(const char* day = 0, const char* month = 0, const char* year = 0) {

	XMLDocument xml_doc;

	int yearInt = atoi(year);
	int monthInt = atoi(month);
	int dayInt = atoi(day);
	
	if (yearInt <= 0 || monthInt <= 0 || monthInt > 12 || dayInt <= 0 || dayInt >= 31) { 
		return false; 
	}
	else {
		XMLNode * elementYear = xml_doc.NewElement(year);
		xml_doc.InsertFirstChild(elementYear);

		XMLElement * elementMonth = xml_doc.NewElement(month);
		elementYear->InsertEndChild(elementMonth);

		XMLElement * elementDay = xml_doc.NewElement(day);
		elementMonth->InsertEndChild(elementDay);
	}

	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);
	return true;
}

bool addEvent(const char* day = 0, const char* month = 0, const char* year = 0, const char* title = 0,
				const char* description = 0, const char* startTime = 0, const char* duration = 0) {


	XMLDocument xml_doc;

	XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != XML_SUCCESS) return false;

	XMLNode* elementYear = xml_doc.FirstChildElement(year);
	XMLElement* elementMonth = elementYear->FirstChildElement(month);
	XMLElement* elementDay = elementMonth->FirstChildElement(day);
	XMLElement* elementEvent = elementDay->FirstChildElement("event");

	XMLElement* elementTit = xml_doc.NewElement(title);
	elementEvent->InsertEndChild(elementTit);

	XMLElement* elementDesc = xml_doc.NewElement(description);
	elementEvent->InsertEndChild(elementDesc);

	XMLElement* elementST = xml_doc.NewElement(startTime);
	elementEvent->InsertEndChild(elementST);

	XMLElement* elementDur = xml_doc.NewElement(duration);
	elementEvent->InsertEndChild(elementDur);


	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);
}


