#ifndef copilot_h
#define copilot_h
#include <string>
#include "crewMember.h"
using namespace std;

class CoPilot : public CrewMember{
	public:
		void SetRating(string r);
		void SetHours(int h);
		void PrintInfo();
		string GetRating() const;
		int GetHours() const;
	private:
		string rating; // 4 character rating code
		int hours; // cumulative flight hours
};
#endif
