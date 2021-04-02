/* Name: Kate Liang
CSCE 1040.001 Homework 4 */

#include "flights.h"
#include <iostream>

int main(){
	Flights flight; // Declare flights type
	Planes plane; // Declare planes type
	CrewMembers crew; // Declare crew type
	int choice; // choice on menu
	cout << "Welcome to Mean Green Airlines!" << endl;
	do{
		cout << "0. Quit program" << endl; // Print menu
		cout << "1. Add Plane" << endl;
		cout << "2. Add Crew Member" << endl;
		cout << "3. Add flight" << endl;
		cout << "4. Delete Plane" << endl;
		cout << "5. Delete Crew Member" << endl;
		cout << "7. Edit plane" << endl;
		cout << "8. Edit crew member" << endl;
		cout << "9. Edit flight" << endl;
		cout << "10. Print all planes" << endl;
		cout << "11. Print one plane" << endl;
		cout << "12. Print all crew member" << endl;
		cout << "13. Print one crew member" << endl;
		cout << "14. Print flights based on status" << endl;
		cout << "15. Print all flights" << endl;
		cout << "16. Print one flight" << endl;
		cout << "17. Print flight schedule" << endl;
		cout << "18. Print crew member's schedule" << endl;
		cout << "19. Print all crew members in a flight" << endl;
		cout << "20. Update flights vector (delete cancelled or completed flights)" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice){ // Call function based on corresponding menu choice
			case 0:
				break;
			case 1:
				plane.addPlane();
				break;
			case 2:
				crew.addMember();
				break;
			case 3:
				flight.addFlight(plane, crew);
				break;
			case 4:
				plane.deletePlane();
				break;
			case 5:
				crew.deleteMember();
				break;
			case 6:
				flight.deleteFlight();
				break;
			case 7:
				plane.editPlane();
				break;
			case 8:
				crew.editMember();
				break;
			case 9:
				flight.editFlight();
				break;
			case 10:
				plane.printPlanes();
				break;
			case 11:
				plane.printPlane();
				break;
			case 12:
				crew.printMembers();
				break;
			case 13:
				crew.printMember();
				break;
			case 14:
				flight.printStatus();
				break;
			case 15:
				flight.printFlights();
				break;
			case 16:
				flight.printFlight();
				break;
			case 17:
				flight.printSchedule();
				break;
			case 18:
				flight.printMemberSchedule(crew);
				break;
			case 19:
				flight.printCrew();
				break;
			case 20:
				flight.autoDelete();
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
		flight.updateFlight();
	}while(choice != 0);
	return 0;
}
