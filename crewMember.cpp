#include "crewMember.h"
#include <iostream>
#include <iomanip>
using namespace std;

CrewMember::CrewMember(){ // default
	name = "";
	id = 0;
	type = "";
}

void CrewMember::PrintInfo(){ // print all info
	cout << left << setw(15) << setw(15) << "Type" << setw(15) << "ID" << setw(15) << "Name" << setw(15) << "Status" << endl;
	cout << setw(15) << getType() << setw(15) << getID() <<  setw(15) << getName() << getStatus()<< endl;
}

void CrewMember::setName(string n){ // set name to n
	name = n;
}

string CrewMember::getName() const{ // return name
	return name;
}

void CrewMember::setID(int i){ // set id to i
	id = i;
}

int CrewMember::getID() const{ // return id
	return id;
}

void CrewMember::setStatus(string s){ // set status to s
	status = s;
}

string CrewMember::getStatus() const{ // return status
	return status;
}

void CrewMember::setType(string t){
	type = t;
}

string CrewMember::getType() const{
	return type;
}