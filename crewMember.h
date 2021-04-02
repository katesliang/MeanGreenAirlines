#ifndef crewMember_h
#define crewMember_h
#include <iostream>
using namespace std;

class CrewMember{
	public:
		CrewMember();
		void setName(string n);
		string getName() const;
		void setID(int i);
		int getID() const;
		void setStatus(string s);
		string getStatus() const;
		virtual void PrintInfo();
		void setType(string t);
		string getType() const;
	private:
		string name; // name
		int id; // crew member id
		string status; // available, sick, on leave
		string type; // type of crew member
};
#endif
