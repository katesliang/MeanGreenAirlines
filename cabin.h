#ifndef cabin_h
#define cabin_h
#include <string>
#include "crewMember.h"
using namespace std;

class CabinCrew:public CrewMember{
	public:
		void PrintInfo();
		void SetPosition(string p);
		string GetPosition() const;
	private:
		string position;
};
#endif
