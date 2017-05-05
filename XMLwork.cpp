#include <iostream>
#include <stdlib.h>
#include "tinyxml2.h"
#include "backend/Day.h"

using namespace tinyxml2;
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

bool checkDate(const char* day = 0, const char* month = 0, const char* year = 0) {

	XMLDocument xml_doc;

	XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != XML_SUCCESS) return false;

	XMLElement* elementYear = xml_doc.FirstChildElement("year");	
	while (elementYear != nullptr){
		if !(elementYear->attribute("YID",year)) elementYear = elementYear->nextSibling("year");
	}
	if (elementYear == nullptr) return false;

	XMLElement* elementMonth = elementYear->FirstChildElement("month");
	while (elementMonth != nullptr){
		if !(elementMonth->attribute("MID",month)) elementMonth = elementMonth->nextSibling("month");
	}
	if (elementMonth == nullptr) return false;

	XMLElement* elementDay = elementMonth->FirstChildElement("day");
	while (elementDay != nullptr){
		if !(elementDay->attribute("DID",day)) elementDay = elementDay->nextSibling("day");
	}
	if (elementDay == nullptr) return false;

	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);

	return true;
}

bool createDate(const char* day = 0, const char* month = 0, const char* year = 0) {

	XMLDocument xml_doc;

	XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != XML_SUCCESS) return false;
	
	int yearInt = atoi(year);
	int monthInt = atoi(month);
	int dayInt = atoi(day);
	
	if (yearInt <= 0 || monthInt <= 0 || monthInt > 12 || dayInt <= 0 || dayInt > 31) { 
		return false; 
	}else if(checkDate(day,month,year)){
		return true;
	}else {
		XMLElement * elementYear = xml_doc.NewElement("year");
		elementyear->setAttribute("YID",year);
		xml_doc.InsertFirstChild(elementYear);

		XMLElement * elementMonth = xml_doc.NewElement("month");
		elementMonth->setAttribute("MID",month)
		elementYear->InsertEndChild(elementMonth);

		XMLElement * elementDay = xml_doc.NewElement("day");
		elementDay->setAttribute("DID",day)
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
	
	createDate(day,month,year);
	
	XMLElement* elementYear = xml_doc.FirstChildElement("year");
	XMLElement* elementMonth = elementYear->FirstChildElement("month");
	XMLElement* elementDay = elementMonth->FirstChildElement("day");
	XMLElement* elementEvent = elementDay->FirstChildElement("event");
	
	int eventNum = elementDay->LastChildElement("event")->IntAttribute(EID);
	eventNum += 1;
	elementEvent->setAttribute("EID",eventNum);

	XMLElement* elementTit = xml_doc.NewElement("title");
	ElementTit->setText(title);
	elementEvent->InsertEndChild(elementTit);

	XMLElement* elementDesc = xml_doc.NewElement("description");
	elementDesc->setText(description);
	elementEvent->InsertEndChild(elementDesc);

	XMLElement* elementST = xml_doc.NewElement("startTime");
	elementST->setText(startTime);
	elementEvent->InsertEndChild(elementST);

	XMLElement* elementDur = xml_doc.NewElement("duration");
	elementDur->setText(duration);
	elementEvent->InsertEndChild(elementDur);

	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);
	return true;
}

bool pullDay(const char* day = 0, const char* month = 0, const char* year = 0) {

	XMLDocument xml_doc;
	
	XMLError eResult = xml_doc.LoadFile("events.xml");
	if (eResult != XML_SUCCESS) return false;
	
	XMLElement* elementYear = xml_doc.FirstChildElement("year");	
	while (elementYear != nullptr){
		if !(elementYear->attribute("YID",year)) elementYear = elementYear->nextSibling("year");
	}
	if (elementYear == nullptr) return false;

	XMLElement* elementMonth = elementYear->FirstChildElement("month");
	while (elementMonth != nullptr){
		if !(elementMonth->attribute("MID",month)) elementMonth = elementMonth->nextSibling("month");
	}
	if (elementMonth == nullptr) return false;

	XMLElement* elementDay = elementMonth->FirstChildElement("day");
	while (elementDay != nullptr){
		if !(elementDay->attribute("DID",day)) elementDay = elementDay->nextSibling("day");
	}
	if (elementDay == nullptr) return false;
	

	//start testing section
	
	int eventCurr = elementDay->FirstChildElement("event")->IntAttribute("EID");
	int eventLast = elementDay->LastChildElement("event")->IntAttribute("EID");
	XMLElement* elementEventCurr = elementDay->FirstChildElement("event");
	Day* day = new Day();
	
	while(eventCurr != eventLast){
		
		const char* title = elementEventCurr->FirstChildElement("title")->getText();
		const char* description = elementEventCurr->FirstChildElement("description")->getText();
		int startTime = elementEventCurr->FirstChildElement("startTime")->getText();
		int duration = elementEventCurr->FirstChildElement("duration")->getText();
		
		//add event to day 
		day->setEvent(title,description,startTime,duration);
		
		//increment event
		elementEventCurr = elementEventCurr->nextSibling("event");
	}
	
	//end testing section
	
	XMLError eResult = xml_doc.SaveFile("events.xml");
	XMLCheckResult(eResult);

	return true;
}
