#ifndef flight_h
#define flight_h
#include <string>
#include <vector>
#include <ctime>
#include "crewMember.h"
#include "plane.h"
#include "pilot.h"
#include "copilot.h"
#include "cabin.h"
using namespace std;

class Flight{
	public:
		Flight();
		void addPilot(CrewMember* pilot);
		void addCopilot(CrewMember* Copilot);
		void addCrew(CrewMember* member);
		CrewMember getPilot(int id);
		CrewMember getCoPilot(int id);
		CrewMember getCrew(int id);
		int getFlightID() const;
		void setFlightID(int id);
		string getPlaneID() const;
		void setPlaneID(string id);
		int getNumPilots() const;
		void setNumPilots(int num);
		void setNumCrew(int num);
		int getNumCrew() const;
		void printPilots();
		void printCopilots();
		void printCrew();
		time_t getStartTime() const;
		tm getStartTm() const;
		tm getEndTm() const;
		time_t getEndTime() const;
		void setStartTime(time_t start, tm startTm);
		void setEndTime(time_t end, tm endTm);
		string getStartAirport() const;
		void setStartAirport(string code);
		string getEndAirport() const;
		void setEndAirport(string code);
		int getNumPassengers() const;
		void setNumPassengers(int num);
		void setStatus(string s);
		string getStatus() const;
	private:
		int flightID;
		string planeID;
		vector <CrewMember*> pilots; // all pilots
		vector <CrewMember*> copilots; // all copilots
		vector <CrewMember*> crew; // all cabin crew
		time_t startTime; // start time and date
		tm starttm;
		time_t endTime; // end time and date
		tm endtm;
		string startAirport;
		string endAirport;
		int numPassengers;
		string status;
};
#endif
