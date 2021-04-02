/* Name: Kate Liang
CSCE 1040.001 */

#include "flights.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// Add flight to flights vector
void Flights::addFlight(Planes planes, CrewMembers crewMembers){
	Flight newFlight; // new flight to add
	string planeID; // new flight plane id
	int flightID; // new flight flight id
	int numPassengers;
	int numPilots;
	int numCopilots = 0;
	int numCrew;
	string startAirport;
	string endAirport;
	int planeIndex;
	int minPilot = 0;
	int minCopilot = 0;
	int minCrew;
	tm start;
	tm end;
	time_t startingTime;
	time_t endTime;
	bool planeExist = false;

	do{
		cout << "Enter flight ID: ";
		cin >> flightID;
		if(findFlight(flightID) != -1){
			cout << "Flight ID already taken. Please try again." << endl;
		}
	}while(findFlight(flightID) != -1);

	newFlight.setFlightID(flightID);
	do{
	cout << "Enter plane ID: ";
	cin >> planeID;
	if(planes.findPlane(planeID) == -1){
		cout << "Plane ID does not exist. Please try again." << endl;
	}
	else
		planeExist = true;
	}while(planeExist == false);

	newFlight.setPlaneID(planeID);
	planeIndex = planes.findPlane(planeID);
	do{
	cout << "Enter number of passengers: ";
	cin >> numPassengers;
	if(numPassengers > planes.getPlane(planeIndex).getNumSeats()){
		cout << "# of passengers exceed # seats. Please try again." << endl;
	}
	}while(numPassengers > planes.getPlane(planeIndex).getNumSeats());

	cin.ignore();
	newFlight.setNumPassengers(numPassengers);
	int input = 0;

	bool planeFree = false;
	cout << "Enter starting time year: ";
	cin >> input;
	start.tm_year = input - 1900;
	cout << "Enter starting time month (1-12): ";
	cin >> input;
	start.tm_mon = input - 1;
	cout << "Enter starting time day (1-31): ";
	cin >> start.tm_mday;
	cout << "Enter starting time hour (0-23): ";
	cin >> start.tm_hour;
	cout << "Enter starting time minute (0-59): ";
	cin >> start.tm_min;
	cout << "Enter starting time second: ";
	cin >> start.tm_sec;
	startingTime = mktime(&start);
	newFlight.setStartTime(startingTime, start);
	cout << "Enter ending time year: ";
	cin >> input;
	end.tm_year = input - 1900;
	cout << "Enter ending time month (1-12): ";
	cin >> input;
	end.tm_mon = input - 1;
	cout << "Enter ending time day: ";
	cin >> end.tm_mday;
	cout << "Enter ending time hour: ";
	cin >> end.tm_hour;
	cout << "Enter ending time minute: ";
	cin >> end.tm_min;
	cout << "Enter ending time second: ";
	cin >> end.tm_sec;
	endTime = mktime(&end);
	newFlight.setEndTime(endTime, end);
	if(difftime(endTime, startingTime) > 8){
		minPilot = 2;
		minCopilot = 2;
		minCrew = planes.getPlane(planeIndex).getMinCrew() * 2;
	}
	else{
		minCrew = planes.getPlane(planeIndex).getMinCrew();
	}

	do{
	cout << "Enter number of pilots: ";
	cin >> numPilots;
	cin.ignore();
	if(numPilots < minPilot){
		cout << "# of pilots too small. Please try again." << endl;
	}
	} while(numPilots < minPilot);
	int pilotID;
	bool inFlight = false;
	for(int i = 0; i < numPilots; i++){
		do{
		cout << "Enter pilot #" << i + 1 << " ID: ";
		cin >> pilotID;
		if(crewMembers.findMember(pilotID) == -1){
			cout << "ID does not exist. Please try again" << endl;
		}
		else if(crewMembers.getMember(crewMembers.findMember(pilotID))->getType() != "Pilot"){
			cout << "Member is not a pilot. Please try again" << endl;
		}
		else if(crewMembers.getMember(crewMembers.findMember(pilotID))->getStatus() != "Available"){
			cout << "Member is not a pilot. Please try again." << endl;
		}
		else{
			for(int i = 0; i < flights.size(); i++){
				if(flights.at(i).getPilot(pilotID).getID() == pilotID){
					if(flights.at(i).getEndTime() > startingTime || flights.at(i).getStartTime() < endTime)
						inFlight = true;
				}
			}
			if(inFlight){
				cout << "Member is already in another flight during this flight. Please try again." << endl;
			}
		}
		}while(crewMembers.findMember(pilotID) == -1 || crewMembers.getMember(crewMembers.findMember(pilotID))->getType() != "Pilot" || crewMembers.getMember(crewMembers.findMember(pilotID))->getStatus() != "Available");
		newFlight.addPilot(crewMembers.getMember(crewMembers.findMember(pilotID)));
	}
	do{
	cout << "Enter number of copilots: ";
	cin >> numCopilots;
	cin.ignore();
	if(numCopilots < minCopilot){
		cout << "# of copilots too small. Please try again." << endl;
	}
	}while(numCopilots < minCopilot);
	for(int i = 0; i < numCopilots; i++){
		do{
		cout << "Enter copilot #" << i + 1 << " ID: ";
		cin >> pilotID;
		if(crewMembers.findMember(pilotID) == -1){
			cout << "ID does not exist please try again" << endl;
		}
		else if(crewMembers.getMember(crewMembers.findMember(pilotID))->getType() != "Copilot"){
			cout << "Member is not a copilot. Please try again" << endl;
		}
		else if(crewMembers.getMember(crewMembers.findMember(pilotID))->getStatus() != "Available"){
			cout << "Member is not available. Please try again." << endl;
		}
		else{
			for(int i = 0; i < flights.size(); i++){
				if(flights.at(i).getCoPilot(pilotID).getID() == pilotID){
					if(flights.at(i).getEndTime() > startingTime || flights.at(i).getStartTime() < endTime)
						inFlight = true;
				}
			}
			if(inFlight){
				cout << "Member is already in another flight during this flight. Please try again." << endl;
			}
		}
		}while(crewMembers.findMember(pilotID) == -1 || crewMembers.getMember(crewMembers.findMember(pilotID))->getType() != "Copilot" || crewMembers.getMember(crewMembers.findMember(pilotID))->getStatus() != "Available");
		newFlight.addCopilot(crewMembers.getMember(crewMembers.findMember(pilotID)));
	}
	do{
	cout << "Enter number of cabin crew: ";
	cin >> numCrew;
	if(numCrew < minCrew){
		cout << "# of crew too small. Please try again." << endl;
	}
	}while(numCrew < minCrew);
	int crewID;
	for(int i = 0; i < numCrew; i++){
		do{
		cout << "Enter crew #" << i + 1 << " ID: ";
		cin >> crewID;
		if(crewMembers.findMember(crewID) == -1){
			cout << "ID does not exist please try again" << endl;
		}
		else if(crewMembers.getMember(crewMembers.findMember(crewID))->getType() != "Cabin Crew"){
			cout << "Member is not a cabin crew member. Please try again" << endl;

		}
		else if(crewMembers.getMember(crewMembers.findMember(crewID))->getStatus() != "Available"){
			cout << "Member is not available. Try again." << endl;
		}
		else{
			for(int i = 0; i < flights.size(); i++){
				if(flights.at(i).getCrew(pilotID).getID() == crewID){
					if(flights.at(i).getEndTime() > startingTime || flights.at(i).getStartTime() < endTime)
						inFlight = true;
				}
			}
			if(inFlight){
				cout << "Member is already in another flight during this flight. Please try again." << endl;
			}
		}
		}while(crewMembers.findMember(crewID) == -1 || crewMembers.getMember(crewMembers.findMember(crewID))->getType() != "Cabin Crew" || crewMembers.getMember(crewMembers.findMember(crewID))->getStatus() != "Available");
		newFlight.addCrew(crewMembers.getMember(crewMembers.findMember(crewID)));
	}
	cout << "Enter starting airport code (3 letters): ";
	cin >> startAirport;
	cin.ignore();
	newFlight.setStartAirport(startAirport);
	cout << "Enter ending airport code (3 letters): ";
	cin >> endAirport;
	cin.ignore();
	newFlight.setEndAirport(endAirport);
	newFlight.setStatus("Active");
	flights.push_back(newFlight);
}

void Flights::deleteFlight(){ // Delete a flight from a vector
	int index = 0;
	int id;
	do{
	cout << "Enter ID of flight you want to delete: ";
	cin >> id;
	cin.ignore();
	index = findFlight(id);
	}while(index == -1);
	flights.erase(flights.begin() + index);
}

void Flights::printSchedule(){ // Print a flights schedule
	int flightID;
	int index = 0;
	do{
	cout << "Enter flight ID of flight you want to print: ";
	cin >> flightID;
	if(findFlight(flightID) == -1){
		cout << "Invalid ID. Please try again." << endl;
	}
	}while(findFlight(flightID) == -1);
	index = findFlight(flightID); 
	time_t Time;
	cout << setw(15) << "Start Airport";
	cout << setw(15) << "End Airport" << endl;
	cout << setw(15) << flights.at(index).getStartAirport();
	cout << setw(15) << flights.at(index).getEndAirport() << endl;
	cout << setw(15) << "Start Time" << endl;
	Time = flights.at(index).getStartTime();
	cout << setw(15) << asctime(gmtime(&Time));
	cout << setw(15) << "End Time" << endl;
	Time = flights.at(index).getEndTime();
	cout << setw(15) << asctime(gmtime(&Time));
}

void Flights::printMemberSchedule(CrewMembers crewMembers){ // print a crew member's flights schedule
	int id;
	do{
		cout << "Enter crew member ID you want to print: ";
		cin >> id;
		if(crewMembers.findMember(id) == -1){
			cout << "Invalid ID. Please try again." << endl;
		}
	}while(crewMembers.findMember(id));

	time_t Time;

	for(int i = 0; i < flights.size(); i++){
		if(flights.at(i).getPilot(id).getID() != 0 || flights.at(i).getCrew(id).getID() != 0){
			cout << setw(15) << "Start Time" << endl;
			Time = flights.at(i).getStartTime();
			cout << setw(15) << asctime(gmtime(&Time));
			cout << setw(15) << "End Time" << endl;
			Time = flights.at(i).getEndTime();
			cout << setw(15) << asctime(gmtime(&Time)) << endl;
			cout << setw(15) << "Start Airport";
			cout << setw(15) << "End Airport" << endl;
			cout << setw(15) << flights.at(i).getStartAirport();
			cout << setw(15) << flights.at(i).getEndAirport();
		}
	}

}

void Flights::updateFlight(){ // update flight based on time
	time_t currTime;
	currTime = time(0);
	for(int i = 0; i < flights.size(); i++){
		if(currTime > flights.at(i).getEndTime()){
			flights.at(i).setStatus("Completed");
		}
	}
}

void Flights::autoDelete(){ // auto clear vector
	int index = 0;
	for(unsigned int i = 0; i < flights.size(); i++){
		if(flights.at(i).getStatus() == "Cancelled" || flights.at(i).getStatus() == "Completed"){
			index = findFlight(flights.at(i).getFlightID());
		}
	}
	flights.erase(flights.begin() + index);
}

void Flights::editFlight(){ // edit flight's features
	int flightID;
	int choice;
	do{
	cout << "Enter flight ID of flight you want to edit: ";
	cin >> flightID;
	if(findFlight(flightID) == -1){
		cout << "Flight not found. Try again." << endl;
	}
	}while(findFlight(flightID) == -1);
	cout << "1. Cancel flight" << endl;
	cout << "2. Edit starting time" << endl;
	cout << "3. Edit end time" << endl;
	cout << "4. Edit starting airport" << endl;
	cout << "5. Edit ending airport" << endl;
	cout << "6. Edit # of pilots" << endl;
	cout << "7. Edit pilots flying" << endl;
	cout << "8. Edit # of copilots" << endl;
	cout << "9. Edit copilots flying" << endl;
	cout << "10. Edit # of cabin crew" << endl;
	cout << "11. Edit crew flying" << endl;
	cout << "12. Edit plane flying" << endl;
	cout << "13. Edit # of passengers" << endl;
	cout << "14. Quit editing" << endl;
	cin >> choice;
	do{
	switch(choice){
		case 1:
			flights.at(findFlight(flightID)).setStatus("Cancelled");
			break;
		case 2:{
			time_t startingTime;
			tm Time;
			int input;
			cout << "Enter starting time year: ";
			cin >> input;
			Time.tm_year = input - 1900;
			cout << "Enter starting time month: ";
			cin >> input;
			Time.tm_mon = input - 1;
			cout << "Enter starting time day: ";
			cin >> Time.tm_mday;
			cout << "Enter starting time hour: ";
			cin >> Time.tm_hour;
			cout << "Enter starting time minute: ";
			cin >> Time.tm_min;
			cout << "Enter starting time second: ";
			cin >> Time.tm_sec;
			startingTime = mktime(&Time);
			flights.at(findFlight(flightID)).setStartTime(startingTime, Time);
			}
			break;
		case 3:{
			tm Time;
			int input;
			time_t endTime;
			cout << "Enter starting time year: ";
			cin >> input;
			Time.tm_year = input - 1900;
			cout << "Enter starting time month: ";
			cin >> input;
			Time.tm_mon = input - 1;
			cout << "Enter starting time day: ";
			cin >> Time.tm_mday;
			cout << "Enter starting time hour: ";
			cin >> Time.tm_hour;
			cout << "Enter starting time minute: ";
			cin >> Time.tm_min;
			cout << "Enter starting time second: ";
			cin >> Time.tm_sec;
			endTime = mktime(&Time);
			flights.at(findFlight(flightID)).setEndTime(endTime, Time);}
			break;
		case 4:{
			string startingAirport;
			cout << "Enter new starting airport code (3 letters): ";
			cin >> startingAirport;
			flights.at(findFlight(flightID)).setStartAirport(startingAirport);}
			break;
		case 5:{
			string endingAirport;
			cout << "Enter new end airport code (3 letters): ";
			cin >> endingAirport;
			flights.at(findFlight(flightID)).setEndAirport(endingAirport);}
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			int numPassengers;
			cout << "Enter new # of passengers";
			cin >> numPassengers;
			flights.at(findFlight(flightID)).setNumPassengers(numPassengers);
			break;
		case 14:
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
	}
	} while(choice != 14);
}

int Flights::findFlight(int flightID){ // find flight in vector
	for(unsigned int i = 0; i < flights.size(); i++){
		if(flights.at(i).getFlightID() == flightID){
			return i;
		}
	}
	return -1;
}

void Flights::printCrew(){ // print all crew on flight
	int id;
	int index;
	do{
	cout << "Enter flight ID: ";
	cin >> id;
	cin.ignore();
	index = findFlight(id);
	if(index == -1){
		cout << "Invalid flight ID. Please try again." << endl;
	}
	}while(index == -1);
	flights.at(index).printPilots();
	flights.at(index).printCopilots();
	flights.at(index).printCrew();
}

void Flights::printStatus(){ // print flights based on status
	int choice;
	time_t Time;
	cout << "1. Active" << endl;
	cout << "2. Completed" << endl;
	cout << "3. Cancelled" << endl;
	cout << "Which option # do you want to print? ";
	cin >> choice;
	switch(choice){
		case 1:
			for(unsigned int i = 0; i < flights.size(); i++){
				if(flights.at(i).getStatus() == "Active"){
					cout << left << setw(15) << "ID" << setw(15) << "Plane ID" << setw(15) << "Start airport" << setw(15) << "End airport" << setw(15) << "# Passengers" << setw(15) << "# Pilots" << setw(15) << "# Crew" << endl;
					cout << setw(15) << flights.at(i).getFlightID();
					cout << setw(15) << flights.at(i).getPlaneID();
					cout << setw(15) << flights.at(i).getStartAirport();
					cout << setw(15) << flights.at(i).getEndAirport();
					cout << setw(15) << flights.at(i).getNumPassengers();
					cout << setw(15) << flights.at(i).getNumPilots();
					cout << setw(15) << flights.at(i).getNumCrew() << endl;	
					cout << setw(15) << "Start Time"  << endl;	
					Time = flights.at(i).getStartTime();
					cout << setw(15) << asctime(gmtime(&Time));
					cout << setw(15) << "End time" << endl;
					Time = flights.at(i).getEndTime();
					cout << setw(15) << asctime(gmtime(&Time)) << endl;		
				}
			}
			break;
		case 2:
			for(unsigned int i = 0; i < flights.size(); i++){
				if(flights.at(i).getStatus() == "Completed"){
					cout << left << setw(15) << "ID" << setw(15) << "Plane ID" << setw(15) << "Start airport" << setw(15) << "End airport" << setw(15) << "# Passengers" << setw(15) << "# Pilots" << setw(15) << "# Crew" << endl;
					cout << setw(15) << flights.at(i).getFlightID();
					cout << setw(15) << flights.at(i).getPlaneID();
					cout << setw(15) << flights.at(i).getStartAirport();
					cout << setw(15) << flights.at(i).getEndAirport();
					cout << setw(15) << flights.at(i).getNumPassengers();
					cout << setw(15) << flights.at(i).getNumPilots();
					cout << setw(15) << flights.at(i).getNumCrew() << endl;	
					cout << setw(15) << "Start Time"  << endl;	
					Time = flights.at(i).getStartTime();
					cout << setw(15) << asctime(gmtime(&Time));
					cout << setw(15) << "End time" << endl;
					Time = flights.at(i).getEndTime();
					cout << setw(15) << asctime(gmtime(&Time)) << endl;					
				}
			}
			break;
		case 3:
			for(unsigned int i = 0; i < flights.size(); i++){
				if(flights.at(i).getStatus() == "Cancelled"){
					cout << left << setw(15) << "ID" << setw(15) << "Plane ID" << setw(15) << "Start airport" << setw(15) << "End airport" << setw(15) << "# Passengers" << setw(15) << "# Pilots" << setw(15) << "# Crew" << endl;
					cout << setw(15) << flights.at(i).getFlightID();
					cout << setw(15) << flights.at(i).getPlaneID();
					cout << setw(15) << flights.at(i).getStartAirport();
					cout << setw(15) << flights.at(i).getEndAirport();
					cout << setw(15) << flights.at(i).getNumPassengers();
					cout << setw(15) << flights.at(i).getNumPilots();
					cout << setw(15) << flights.at(i).getNumCrew() << endl;	
					cout << setw(15) << "Start Time"  << endl;	
					Time = flights.at(i).getStartTime();
					cout << setw(15) << asctime(gmtime(&Time));
					cout << setw(15) << "End time" << endl;
					Time = flights.at(i).getEndTime();
					cout << setw(15) << asctime(gmtime(&Time)) << endl;	
				}
			}
			break;
		default:
			cout << "Invalid choice. Please try again" << endl;
			break;
	}
}

void Flights::printFlights(){ // print all flights
	time_t Time;
	for(unsigned int i = 0; i < flights.size(); i++){
		cout << left << setw(15) << "ID" << setw(15) << "Plane ID" << setw(15) << "Starting airport" << setw(15) << "Ending airport" << setw(15) << "# Passengers" << setw(15) << "# Pilots" << setw(15) << "# Crew" << endl;
		cout << setw(15) << flights.at(i).getFlightID();
		cout << setw(15) << flights.at(i).getPlaneID();
		cout << setw(15) << flights.at(i).getStartAirport();
		cout << setw(15) << flights.at(i).getEndAirport();
		cout << setw(15) << flights.at(i).getNumPassengers();
		cout << setw(15) << flights.at(i).getNumPilots() << setw(15) << flights.at(i).getNumCrew() << endl;
		cout << setw(15) << "Start Time" << endl;
		Time = flights.at(i).getStartTime();
		cout << setw(15) << asctime(gmtime(&Time));
		cout << setw(15) << "End time" << endl;
		Time = flights.at(i).getEndTime();
		cout << setw(15) << asctime(gmtime(&Time));
	}
}

void Flights::printFlight(){ // print one flight
	int i;
	int id;
	time_t Time;
	do{
	cout << "Enter ID of flight you want to print: ";
	cin >> id;
	i = findFlight(id);
	if(i == -1){
		cout << "Invalid ID. Please try again." << endl;
	}
	}while(i == -1);
	cout << left << setw(15) << "ID" << setw(15) << "Plane ID" << setw(15) << "Start airport" << setw(15) << "End airport" << setw(15) << "# Passengers" << setw(15) << "# Pilots" << setw(15) << "# Crew" << endl;
	cout << setw(15) << flights.at(i).getFlightID();
	cout << setw(15) << flights.at(i).getPlaneID();
	cout << setw(15) << flights.at(i).getStartAirport();
	cout << setw(15) << flights.at(i).getEndAirport();
	cout << setw(15) << flights.at(i).getNumPassengers();
	cout << setw(15) << flights.at(i).getNumPilots();
	cout << setw(15) << flights.at(i).getNumCrew() << endl;	
	cout << setw(15) << "Start Time"  << endl; 	
	Time = flights.at(i).getStartTime();
	cout << setw(15) << asctime(gmtime(&Time));
	cout << setw(15) << "End time" << endl;
	Time = flights.at(i).getEndTime();
	cout << setw(15) << asctime(gmtime(&Time)) << endl;	
}
