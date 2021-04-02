#include "flight.h"
#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;

Flight::Flight(){ // default
	flightID = 0;
	planeID = "";
	startAirport = "";
	endAirport = "";
	numPassengers = 0;
	status = "";
}

void Flight::addPilot(CrewMember* pilot){ //add
	pilots.push_back(pilot);
}

void Flight::addCopilot(CrewMember* copilot){ // add copilot to vector
	copilots.push_back(copilot);
}

CrewMember Flight::getPilot(int id){ // return pilot w that id
	CrewMember noPilot;
	int index = 0;
	for(unsigned int i = 0; i < pilots.size(); i++){
		if(pilots.at(i)->getID() == id){
			index = i;
			return *pilots.at(index);
		}
	}
	return noPilot;
}

CrewMember Flight::getCoPilot(int id){ // return pilot w that id
	CrewMember noPilot;
	int index = 0;
	for(unsigned int i = 0; i < copilots.size(); i++){
		if(copilots.at(i)->getID() == id){
			index = i;
			return *copilots.at(index);
		}
	}
	return noPilot;
}

void Flight::addCrew(CrewMember* member){ // add
	crew.push_back(member);
}

CrewMember Flight::getCrew(int id){ // return
	CrewMember noCrew;
	int index = 0;
	for(unsigned int i = 0; i < crew.size(); i++){
		if(crew.at(i)->getID() == id){
			index = i;
			return *crew.at(index);
		}
	}
	return noCrew;
}

int Flight::getFlightID() const{ // return id
	return flightID;
}

void Flight::setFlightID(int id){ // set id
	flightID = id;
}

string Flight::getPlaneID() const{ // return id
	return planeID;
}

void Flight::setPlaneID(string id){ // set id
	planeID = id;
}

int Flight::getNumPilots() const{ // return num pilots 
	return pilots.size();
}

int Flight::getNumCrew() const{ // return num cabin crew
	return crew.size();
}

void Flight::printPilots(){ // print all pilots info on flight
	cout << "Pilots" << endl;
	for(unsigned int i = 0; i < pilots.size(); i++){
		pilots.at(i)->PrintInfo();
	}
}

void Flight::printCopilots(){
	cout << "Crew Members" << endl;
	cout << setw(15) << "ID";
	cout << setw(15) << "Name";
	cout << setw(15) << "Type" << endl;
	for(unsigned int i = 0; i < copilots.size(); i++){
		copilots.at(i)->PrintInfo();
	}
}

void Flight::printCrew(){ // print all cabin crew in flight
	cout << "Crew Members" << endl;
	cout << setw(15) << "ID";
	cout << setw(15) << "Name";
	cout << setw(15) << "Type" << endl;
	for(unsigned int i = 0; i < crew.size(); i++){
		crew.at(i)->PrintInfo();
	}
}

time_t Flight::getStartTime() const{
	return startTime;
}

tm Flight::getStartTm() const{
	return starttm;
}


time_t Flight::getEndTime() const{
	return endTime;
}

tm Flight::getEndTm() const{
	return endtm;
}


void Flight::setStartTime(time_t start, tm startTm){
	startTime = start;
	starttm = startTm;
}

void Flight::setEndTime(time_t end, tm endTm){
	endTime = end;
	endtm = endTm;
}

string Flight::getStartAirport() const{
	return startAirport;
}

void Flight::setStartAirport(string code){
	startAirport = code;
}

string Flight::getEndAirport() const{
	return endAirport;
}

void Flight::setEndAirport(string code){ // set end airport to code
	endAirport = code;
}

int Flight::getNumPassengers() const{ // return number passengers on flight
	return numPassengers;
}

void Flight::setNumPassengers(int num){
	numPassengers = num;
}

void Flight::setStatus(string s){
	status = s;
}

string Flight::getStatus() const{
	return status;
}
