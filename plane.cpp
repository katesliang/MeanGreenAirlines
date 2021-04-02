#include "plane.h"

Plane::Plane(){ // Default constructor
	make = "";
	model = 0;
	planeID = "";
	numSeats = 0;
	range = 0;
	minCrew = 0;
}

void Plane::setMake(string m){ // set make
	make = m;
}

string Plane::getMake() const{ // get make
	return make;
}

void Plane::setModel(int num){ // set model
	model = num;
}

int Plane::getModel() const{ // get model
	return model;
}

void Plane::setID(string id){ // set plane id
	planeID = id;
}

string Plane::getID() const{ // get plane id
	return planeID;
}

void Plane::setNumSeats(int num){ // set number of seats
	numSeats = num;
}

int Plane::getNumSeats() const{ // return number of seats
	return numSeats;
}

void Plane::setRange(int r){ // set plane range
	range = r;
}

int Plane::getRange() const{ // get plane range
	return range;
}

void Plane::setMinCrew(int min){ // set min number of cabin crew
	minCrew = min;
}

int Plane::getMinCrew() const{ // get min number of cabin crew
	return minCrew;
}
