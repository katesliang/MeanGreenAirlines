#include "copilot.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CoPilot::PrintInfo(){
	CrewMember::PrintInfo();
	cout << setw(15) << "Rating" << setw(15) << "Flight Hrs." << endl;
	cout << setw(15) << rating << setw(15) << hours << endl;
}

void CoPilot::SetRating(string r){
	rating = r;
}

void CoPilot::SetHours(int h){
	hours = h;
}

string CoPilot::GetRating() const{
	return rating;
}

int CoPilot::GetHours() const{
	return hours;
}
