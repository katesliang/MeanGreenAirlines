#include "crewMembers.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CrewMembers::addMember(){
	int id;
	string name;
	int choice;
	string status;
	do{
	cout << "Enter Crew Member ID: ";
	cin >> id;
	if(findMember(id) != -1){
		cout << "ID already used. Please try again." << endl;
	}
	}while(findMember(id) != -1);
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	do{
	cout << "Select status:" << endl;
	cout << "1. Available" << endl;
	cout << "2. On leave" << endl;
	cout << "3. Sick" << endl;
	cout << "Choose option: ";
	cin >> choice;
	if(choice == 1){
		status = "Available";
	}
	else if(choice == 2){
		status = "On leave";
	}
	else if(choice == 3){
		status = "Sick";
	}
	else{
		cout << "Invalid choice. Please try again." << endl;
	}
	}while(choice != 1 && choice != 2 && choice != 3);

	cout << "Select Crew Member type: " << endl;
	cout << "1. Cabin Crew" << endl;
	cout << "2. Copilot" << endl;
	cout << "3. Pilot" << endl;
	cout << "Choose an option: ";
	cin >> choice;
	cin.ignore();
	do{
	if(choice == 1){
		CabinCrew* newCabin = new CabinCrew;
		string position;
		int c;
		newCabin->setID(id);
		newCabin->setName(name);
		newCabin->setStatus(status);
		newCabin->setType("Cabin Crew");
		do{
		cout << "Choose cabin crew member position: " << endl;
		cout << "1. First class" << endl;
		cout << "2. Business Class" << endl;
		cout << "3. Economy front" << endl;
		cout << "4. Economy rear" << endl;
		cout << "5. Lead" << endl;
		cout << "Choose an option: ";
		cin >> c;
		cin.ignore();
		if(c == 1){
			newCabin->SetPosition("First Class");
		}
		else if(c == 2){
			newCabin->SetPosition("Business Class");
		}
		else if(c == 3){
			newCabin->SetPosition("Economy Front");
		}
		else if(c == 4){
			newCabin->SetPosition("Economy Rear");
		}
		else if(c == 5){
			newCabin->SetPosition("Lead");
		}
		else{
			cout << "Invalid choice. Please try again." << endl;
		}
		}while(c != 1 && c != 2 && c != 3 && c != 4 && c != 5);
		crewMembers.push_back(newCabin);
	}
	else if(choice == 2){
		CoPilot* newCopilot = new CoPilot;
		string rating;
		int hours;
		newCopilot->setID(id);
		newCopilot->setName(name);
		newCopilot->setStatus(status);
		newCopilot->setType("Copilot");
		do{
		cout << "Enter 4-character rating code: " << endl;
		cin >> rating;
		if(rating.size() == 4){
			break;
		}
		else{
			cout << "Size not correct. Try again." << endl;
		}
		}while(rating.size() != 4);
		newCopilot->SetRating(rating);
		cout << "Enter cumulative flight hours: " << endl;
		cin >> hours;
		newCopilot->SetHours(hours);
		crewMembers.push_back(newCopilot);
	}
	else if(choice == 3){
		Pilot* newPilot = new Pilot;
		string rating;
		int hours;
		newPilot->setID(id);
		newPilot->setName(name);
		newPilot->setStatus(status);
		newPilot->setType("Pilot");
		do{
		cout << "Enter 5-character rating code: " << endl;
		cin >> rating;
		if(rating.size() == 5){
			break;
		}
		else{
			cout << "Size not correct. Try again." << endl;
		}
		}while(rating.size() != 5);
		newPilot->SetRating(rating);
		cout << "Enter cumulative flight hours: " << endl;
		cin >> hours;
		newPilot->SetHours(hours);
		crewMembers.push_back(newPilot);
	}
	else{
		cout << "Invalid choice. Please try again." << endl;
	}
	}while(choice != 1&&choice != 2 && choice != 3);
}

void CrewMembers::deleteMember(){
	int id;
	int index;
	do{
	cout << "Enter ID of crew member you want to remove: ";
	cin >> id;
	cin.ignore();
	index = findMember(id);
	}while(index == -1);
	crewMembers.erase(crewMembers.begin() + index);
}

CrewMember* CrewMembers::getMember(int index){
	return crewMembers.at(index);
}

void CrewMembers::editMember(){
	int id;
	string name;
	string status;
	string rating;
	int choice;
	int index;
	do{
	cout << "Enter crew member ID you want to edit: ";
	cin >> id;
	cin.ignore();
	index = findMember(id);
	if(index == -1){
		cout << "Invalid ID. Please try again." << endl;
	}
	}while(index == -1);

	do{
	cout << "1. Edit name" << endl;
	cout << "2. Edit status" << endl;
	cout << "3. Edit rating (Copilot and pilot ONLY)" << endl;
	cout << "4. Edit position (Cabin Crew ONLY)" << endl;
	cout << "5. Edit cumulative flight hours (Copilot and pilot ONLY)" << endl;
	cout << "6. Quit editing" << endl;
	cout << "What do you want to edit (enter a number)? ";
	cin >> choice;
	cin.ignore();
	switch(choice){
		case 1:
			cout << "Enter new name: ";
			getline(cin, name);
			crewMembers.at(index)->setName(name);
			break;
		case 2:{
			int c;
			do{
			cout << "Select status:" << endl;
			cout << "1. Available" << endl;
			cout << "2. On leave" << endl;
			cout << "3. Sick" << endl;
			cout << "Choose option: ";
			cin >> c;
			if(c == 1){
				crewMembers.at(index)->setStatus("Available");
			}
			else if(c == 2){
				crewMembers.at(index)->setStatus("On leave");
			}
			else if(c == 3){
				crewMembers.at(index)->setStatus("Sick");
			}
			else{
				cout << "Invalid choice. Please try again." << endl;
			}
			}while(c != 1 && c != 2 && c != 3);}
			break;
		case 3:
			if(crewMembers.at(index)->getType() == "Pilot"){
				do{
				cout << "Enter 5-character rating code: " << endl;
				cin >> rating;
				if(rating.size() == 5){
					((Pilot*)crewMembers.at(index))->SetRating(rating);
					break;
				}
				else{
					cout << "Size not correct. Try again." << endl;
				}
				}while(rating.size() != 5);
			}
			else if(crewMembers.at(index)->getType() == "Copilot"){
				do{
				cout << "Enter 4-character rating code: " << endl;
				cin >> rating;
				if(rating.size() == 4){
					((CoPilot*)crewMembers.at(index))->SetRating(rating);
					break;
				}
				else{
					cout << "Size not correct. Try again." << endl;
				}
				}while(rating.size()!= 4);
			}
			else{
				cout << "Crew Member is not a pilot or copilot." << endl;
			}
			break;
		case 4:{
			int c;
			cout << "Choose cabin crew member position: " << endl;
			cout << "1. First class" << endl;
			cout << "2. Business Class" << endl;
			cout << "3. Economy front" << endl;
			cout << "4. Economy rear" << endl;
			cout << "5. Lead" << endl;
			cout << "Choose an option: ";
			cin >> c;
			cin.ignore();
			if(c == 1){
				((CabinCrew*)crewMembers.at(index))->SetPosition("First Class");
			}
			else if(c == 2){
				((CabinCrew*)crewMembers.at(index))->SetPosition("Business Class");
			}
			else if(c == 3){
				((CabinCrew*)crewMembers.at(index))->SetPosition("Economy Front");
			}
			else if(c == 4){
				((CabinCrew*)crewMembers.at(index))->SetPosition("Economy Rear");
			}
			else if(c == 5){
				((CabinCrew*)crewMembers.at(index))->SetPosition("Lead");
			}
			else{
				cout << "Invalid choice. Please try again." << endl;
			}
			while(c != 1 && c != 2 && c != 3 && c != 4 && c != 5);}
			break;
		case 5:
			int hours;
			if(crewMembers.at(index)->getType() == "Pilot"){
			cout << "Enter cumulative flight hours: " << endl;
			cin >> hours;
			((Pilot*)crewMembers.at(index))->SetHours(hours);
			}
			else if(crewMembers.at(index)->getType() == "CoPilot"){
			cout << "Enter cumulative flight hours: " << endl;
			cin >> hours;
			((CoPilot*)crewMembers.at(index))->SetHours(hours);
			}
			break;
		case 6:
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 6);

}

int CrewMembers::findMember(int id) const{
	for(unsigned int i = 0; i < crewMembers.size(); i++){
		if(crewMembers.at(i)->getID() == id){
			return i;
		}
	}
	return -1;
}

int CrewMembers::getNumMembers() const{
	return crewMembers.size();
}

void CrewMembers::printMembers(){
	for(unsigned int i = 0; i < crewMembers.size(); i++){
		crewMembers.at(i)->PrintInfo();
	}

}

void CrewMembers::printMember(){
	int index;
	int id;
	do{
	cout << "Enter ID of member you want to print: ";
	cin >> id;
	cin.ignore();
	index = findMember(id);
	if(index == -1){
		cout << "Invalid ID. Please try again." << endl;
	}
	}while(index == -1);
	crewMembers.at(index)->PrintInfo();
}
