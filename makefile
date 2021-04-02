output.exe: main.o flights.o flight.o crewMembers.o crewMember.o planes.o plane.o pilot.o copilot.o cabin.o
	g++ -o output.exe main.o flights.o flight.o crewMembers.o crewMember.o planes.o plane.o pilot.o copilot.o cabin.o

main.o: main.cpp flights.h
	g++ -c main.cpp

flights.o: flights.cpp flights.h
	g++ -c flights.cpp
	
flight.o: flight.cpp flight.h plane.h crewMember.h
	g++ -c flight.cpp

planes.o: planes.cpp planes.h
	g++ -c planes.cpp

plane.o: plane.cpp plane.h
	g++ -c plane.cpp

crewMember.o: crewMember.cpp crewMember.h
	g++ -c crewMember.cpp

crewMembers.o: crewMembers.cpp crewMembers.h
	g++ -c crewMembers.cpp

pilot.o: pilot.cpp pilot.h
	g++ -c pilot.cpp

copilot.o: copilot.cpp copilot.h
	g++ -c copilot.cpp

cabin.o: cabin.cpp cabin.h
	g++ -c cabin.cpp

run : 
	./output.exe

clean:
	rm *.o output.exe
