#include "crewMembers.h"

class Flights{ // Collection of flight
	public:
		void addFlight(Planes planes, CrewMembers crewMembers);
		void editFlight();
		void deleteFlight();
		int findFlight(int flightID);
		void printFlight();
		void printFlights();
		void updateFlight();
		void printSchedule();
		void printMemberSchedule(CrewMembers crewMembers);
		void printCrew();
		void printStatus();
		void autoDelete();
	private:
		vector <Flight> flights;
};

