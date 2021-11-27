#include "Mission.h"
#include <ctime>	//for random number generation

/*
Author name: Ramal Seyidli

Author id: 150180901
*/

//Constructor
Mission::Mission(string newName, int newCost, int newFaultProbablity)
{
	this->cost = newCost;
	this->faultProbablity = newFaultProbablity;

	//for name check

	if (newName.length() == 5 && isupper(newName[0]) && isupper(newName[1]) && isdigit(newName[3]) && isdigit(newName[4]))
	{
		this->name = newName;
	}
	else
	{
		cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
		this->name = "AA-00";
	}
	this->numMissions++;
	this->missionNumber = this->numMissions;
	this->passengers = NULL;
	this->setCrew(NULL);
	this->completed = false;
}


//Destructor
Mission::~Mission()
{
	delete passengers;
	delete crew;
	delete next;
}


//Operator overloading
void Mission::operator+=(Astronaut* inObj)
{
	if (this->getCrew() == NULL)	//for the first element of Linked list (head)
	{
		this->setCrew(inObj);
		inObj->next = NULL;
	}
	else                    //Body
	{
		Astronaut* iter = this->getCrew();
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = inObj;
		iter = iter->next;
		iter->next = NULL;
	}
}


//Overloading overloaded operator
void Mission::operator+=(Passenger* inObj)
{
	if (inObj->getTicket())
	{
		this->setPassengers(inObj);			
	}
	else
	{
		cerr << "Passenger " << inObj->getName() << " " << inObj->getSurname() <<" does not have a valid ticket!" << endl;
	}
}


//added by me to count memebers of linked list
int Mission::crewCounter()
{
	int number = 1;
	Astronaut* iter = this->getCrew();
	while (iter->next != NULL)
	{
		number++;
		iter = iter->next;
	}
	return number;
}

//added by me to count memebers of linked list
int Mission::passengerCounter()
{
	int number = 0;
	Passenger* iter = this->getPassengers();
	
	while (iter != NULL)
	{
		number++;
		iter = iter->next;
	}
	return number;
}


bool Mission::executeMission()
{
	srand((unsigned)time(NULL));
	int b = 101, a = 0;
	int r = (rand() % (b - a)) + a;
	if (r > this->faultProbablity)
	{
		cout << "MISSION " << this->name << " SUCCESSFUL!" << endl;

		Astronaut* iter = this->getCrew();
		for (int i = 0; i < this->crewCounter(); i++)
		{
			iter->completeMission();
			cout << "Astronaut " << iter->getName() << " " << iter->getSurname() << " successfully completed " << iter->getNumMissions() << " missions." << endl;
			iter = iter->next;
		}
		this->completed = true;
		return true;
	}
	else
	{
		cout << "MISSION " << this->name << " FAILED!" << endl;
		this->completed = false;
		return false;
	}
}


int Mission::calculateProfit(int ticketPrice)
{
	int profit = 0;
	if (this->completed)
	{
		profit = this->passengerCounter() * ticketPrice;
	}
	return profit - this->cost;
}

//Some setter members
void Mission::setName(string newName)
{
	this->name = newName;
}

void Mission::setPassengers(Passenger* inObj)
{
	Passenger* iter = this->passengers;
	if (iter == NULL)
	{
		// add head
		this->passengers = inObj;
		this->passengers->next = NULL;
	}
	else
	{
		// add body
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = inObj;
		inObj->next = NULL;
	}
}