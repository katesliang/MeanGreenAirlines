#include "cabin.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CabinCrew::PrintInfo(){
	CrewMember::PrintInfo();
	cout << setw(15) << "Position" << endl;
	cout << GetPosition() << endl;
}

void CabinCrew::SetPosition(string p){
	position = p;
}

string CabinCrew::GetPosition() const{
	return position;
}
