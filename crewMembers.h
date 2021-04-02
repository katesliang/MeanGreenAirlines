#include "planes.h"
#include "pilot.h"
#include "cabin.h"
#include "copilot.h"
#include <vector>

class CrewMembers{ // Collection of crew member
	public:
		void printMembers();
		void printMember();
		void deleteMember();
		void addMember();
		void editMember();
		int findMember(int id) const;
		int getNumMembers() const;
		CrewMember* getMember(int index);
	private:
		vector <CrewMember*> crewMembers;
};
