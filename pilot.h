#ifndef pilot_h
#define pilot_h
#include <string>
#include "crewMember.h"
using namespace std;

class Pilot:public CrewMember{
	public:
		void PrintInfo();
		void SetRating(string r);
		void SetHours(int f);
		string GetRating() const;
		int GetHours() const;
	private:
		string rating; // 5 character rating code
		int flightHours; // cumulative flight hours
};
#endif
