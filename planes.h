#include "flight.h"
#include <vector>

class Planes{ // Collection of Plane
	public:
		void addPlane();
		void editPlane();
		void deletePlane();
		int getNumPlanes() const;
		int findPlane(string id) const;
		void printPlanes();
		void printPlane();
		Plane getPlane(int index);
	private:
		vector <Plane> planes;
};
