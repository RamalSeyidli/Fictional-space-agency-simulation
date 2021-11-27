#ifndef MISSION_H
#define MISSION_H
#include "Person.h"

/*
Author name: Ramal Seyidli

Author id: 150180901
*/

class Mission
{
	string name;
	int missionNumber;
	int cost;
	int faultProbablity;
	bool completed;
	Passenger* passengers;
	Astronaut* crew;
	static int numMissions;

public:
	//Asked members
	Mission(string, int, int);	//arguments: name, cost, faultProbablity
	~Mission();	//Destructor
	void operator+=(Astronaut*);		//Operator overloading
	void operator+=(Passenger*);		//Operator overloading
	bool executeMission();
	int calculateProfit(int);
	Mission* next;	//for linked list

	//Getters
	int getMissionNumber() { return missionNumber; }
	string getName() { return name; }
	int getCost() { return cost; }
	Passenger* getPassengers() { return passengers; }
	Astronaut* getCrew() { return crew; }
	bool getCompleted() { return completed; }
	

	//Setters
	void setName(string);
	void setPassengers(Passenger* inObj);
	void setCrew(Astronaut* inObj) { crew = inObj; }

	//Counters
	int crewCounter();	//added to count number of crew members
	int passengerCounter();  //added to count number of passengers
};
#endif