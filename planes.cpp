#include "planes.h"
#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

void Planes::addPlane(){ // Add plane to planes vector
	string id;
	string make;
	int model;
	int numSeats;
	int range;
	int minCrew;
	Plane newPlane;
	do{
	cout << "Enter Plane ID: ";
	cin >> id;
	if(findPlane(id) != -1){
		cout << "Plane ID already used. Please try again." << endl;
	}
	}while(findPlane(id) != -1);
	newPlane.setID(id);
	cin.ignore();
	cout << "Enter Plane Make: ";
	getline(cin, make);
	newPlane.setMake(make);
	cout << "Enter Plane Model: ";
	cin >> model;
	newPlane.setModel(model);
	cin.ignore();
	cout << "Enter number of seats: ";
	cin >> numSeats;
	newPlane.setNumSeats(numSeats);
	cin.ignore();
	cout << "Enter range (miles): ";
	cin >> range;
	newPlane.setRange(range);
	cin.ignore();
	cout << "Enter minimum number of cabin crew: ";
	cin >> minCrew;
	newPlane.setMinCrew(minCrew);
	cin.ignore();
	planes.push_back(newPlane);
}

Plane Planes::getPlane(int index){ // Return plane at index
	return planes.at(index);
}

void Planes::editPlane(){ // Edit plane
	string id;
	string make;
	int model;
	int range;
	int numSeats;
	int minCrew;

	int choice;
	int index;
	do{
	cout << "Enter plane ID of plane you want to edit: ";
	getline(cin, id);
	index = findPlane(id);
	if(index == -1){
		cout << "Invalid Plane ID. Please try again." << endl;
	}
	}while(index == -1);

	do{
	cout << "1. Edit make" << endl;
	cout << "2. Edit model" << endl;
	cout << "3. Edit range" << endl;
	cout << "4. Edit number of seats" << endl;
	cout << "5. Edit minimum number of crew members" << endl;
	cout << "6. Quit program" << endl;
	cout << "What do you want to edit (enter a number)? ";
	cin >> choice;
	cin.ignore();
	switch(choice){
		case 1:
			cout << "Enter new make: ";
			getline(cin, make);
			planes.at(index).setMake(make);
			break;
		case 2:
			cout << "Enter new model: ";
			cin >> model;
			planes.at(index).setModel(model);
			break;
		case 3:
			cout << "Enter new range (miles): ";
			cin >> range;
			cin.ignore();
			planes.at(index).setRange(range);
			break;
		case 4:
			cout << "Enter new number of seats: ";
			cin >> numSeats;
			cin.ignore();
			planes.at(index).setNumSeats(numSeats);
			break;
		case 5:
			cout << "Enter new minimum number of crew members: ";
			cin >> minCrew;
			cin.ignore();
			planes.at(index).setMinCrew(minCrew);
			break;
		case 6:
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 6);
}

void Planes::deletePlane(){ // Delete a plane
	string id;
	int index;
	do{
	cout << "Enter ID of plane you want to delete: ";
	cin >> id;
	cin.ignore();
	index = findPlane(id);
	}while(index == -1);
	planes.erase(planes.begin() + index);
}

int Planes::getNumPlanes() const{ // Return number of planes
	return planes.size();
}

int Planes::findPlane(string id) const{ // Find a plane in vector
	for(unsigned int i = 0; i < planes.size(); i++){
		if(planes.at(i).getID() == id){
			return i;
		}
	}
	return -1;
}

void Planes::printPlanes(){ // Print all planes
	cout << left << setw(15) << "ID" << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "# Seats" << setw(15) << "Range" << setw(15) << "Min. Crew" << endl;
	for(unsigned int i = 0; i < planes.size(); i++){
		cout << setw(15) << planes.at(i).getID() << setw(15) << planes.at(i).getMake() << setw(15) << planes.at(i).getModel() << setw(15) << planes.at(i).getNumSeats() << setw(15) << planes.at(i).getRange() << setw(15) << planes.at(i).getMinCrew() << endl;
	}
}

void Planes::printPlane(){ // Print one plane
	int index;
	string id;
	do{
	cout << "Enter ID of plane you want to print: ";
	cin >> id;
	cin.ignore();
	index = findPlane(id);
	if(index == -1){
		cout << "Invalid ID. Please try again." << endl;
	}
	}while(index == -1);
	cout << left << setw(15) << "ID" << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "# Seats" << setw(15) << "Range" << setw(15) << "Min. Crew" << endl;
	cout << left << setw(15) << planes.at(index).getID() << setw(15) << planes.at(index).getMake() << setw(15) << planes.at(index).getModel() << setw(15) << planes.at(index).getNumSeats() << setw(15) << planes.at(index).getRange() << setw(15) << planes.at(index).getMinCrew() << endl;
}
