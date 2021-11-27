#include "Person.h"

/*
Author name: Ramal Seyidli

Author id: 150180901
*/

//Passenger

bool Passenger::buyTicket(int n)
{
	if (this->cash >= n)	//if budget is enough
	{
		this->ticket = true;
		cash -= n;
		return true;
	}
	else       //not enough
	{
		this->ticket = false;
		return false;
	}
}

//Destructor
Passenger::~Passenger()
{
	delete next;
}

//Astronout

void Astronaut::completeMission()
{
	this->numMissions++;
}


//Constructor
Astronaut::Astronaut(string newName, string newSurname, int newNumMissions) :Person(newName, newSurname)
{
	if (newNumMissions < 0) {
		numMissions = 0;
		cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
	} else {
		numMissions = newNumMissions;
	}
	next = NULL;
}

//Destructor
Astronaut::~Astronaut()
{
	delete next;
}