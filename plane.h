#include <string>
using namespace std;

class Plane{
	public:
		Plane(); // default
		void setMake(string m);
		string getMake() const;
		void setModel(int num);
		int getModel() const;
		void setID(string id);
		string getID() const;
		void setNumSeats(int num);
		int getNumSeats() const;
		void setRange(int r);
		int getRange() const;
		void setMinCrew(int min);
		int getMinCrew() const;
	private:
		string make;
		int model;
		string planeID;
		int numSeats; // number of seats
		int range; // range (miles)
		int minCrew; // min number of cabin crew
};
