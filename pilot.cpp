#include "pilot.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Pilot::PrintInfo(){
	CrewMember::PrintInfo();
	cout << setw(15) << "Rating" << setw(15) << "Flight Hrs." << endl;
	cout << setw(15) << rating << setw(15) << flightHours << endl;
}

string Pilot::GetRating() const{
	return rating;
}

void Pilot::SetRating(string r){
	rating = r;
}

int Pilot::GetHours() const{
	return flightHours;
}

void Pilot::SetHours(int f){
	flightHours = f;
}
