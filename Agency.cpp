#include "Agency.h"
#include <iostream>
//Constructor

/*
Author name: Ramal Seyidli

Author id: 150180901
*/


//Constructor
Agency::Agency(string name, int cash, int ticketPrice)
{
	this->name = name;
	this->cash = cash;
	if (ticketPrice >= 0)
	{
		this->ticketPrice = ticketPrice;
	}
	else
	{
		this->ticketPrice = 0;
		std::cerr << "Ticket price can't be negative. It is set to 0."<<endl;
	}
	this->completedMissions = NULL;
	this->nextMissions = NULL;
}


//Destructor

Agency::~Agency()
{
	delete completedMissions;
	delete nextMissions;
}



void Agency::addMission(Mission& inMission)
{
	if (this->nextMissions == NULL)
	{
		this->nextMissions = &inMission;
		inMission.next = NULL;
	}
	else
	{
		Mission* iter = this->nextMissions;
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		iter->next = &inMission;
		iter = iter->next;
		iter->next = NULL;
	}
}

void Agency::executeNextMission()
{
	if (this->nextMissions == NULL)		//for security
	{
		cout << "No available mission to execute!" << endl;
		return;
	}

	this->nextMissions->executeMission();
	
	if (this->nextMissions->getCompleted())
	{
		Mission* temp = this->nextMissions;
		this->setCash(this->nextMissions->calculateProfit(this->getTicketPrice()) + this->getCash());	//modifies agency cash by profit
		this->nextMissions = this->nextMissions->next;	//to keep repetition

		Mission* iter = this->completedMissions;
		if (iter == NULL)
		{
			this->completedMissions = temp;
		}
		else
		{
			while (iter->next != NULL)
			{
				iter = iter->next;
			}
			iter->next = temp;
		}
		temp->next = NULL;
	}
	else
	{
		this->setCash(this->nextMissions->calculateProfit(this->getTicketPrice()) + this->getCash());	//modifies agency cash by profit

		Mission* temp = this->nextMissions;
		Mission* iter = this->nextMissions;
		if (iter->next != NULL)
		{
			this->nextMissions = this->nextMissions->next;	//to keep repetition
			
			Mission* tail = iter;
			
			while (iter != NULL)
			{
				tail = iter;
				iter = iter->next;
			}
			tail->next = temp;
			temp->next = NULL;
			cout << "Agency reschedules the mission." << endl;
		}
	}
}


ostream& operator<<(ostream& os, Agency& inobj)
{
	os << "Agency name: " << inobj.getName() << ", Total cash: " << inobj.getCash() << ", Ticket Price: " << inobj.getTicketPrice() << endl;
	os << "Next Missions: " << endl;
	if (inobj.nextMissions == NULL) 
	{
		os << "No missions available." << endl;
	}
	else
	{
		Mission* iter = inobj.nextMissions;
		while (iter != NULL)
		{
			os << "Mission number: " << iter->getMissionNumber() << " Mission name: " << iter->getName() << " Cost: " << iter->getCost() << endl;
			iter = iter->next;
		}
	}
	os << "Completed Missions:" << endl;
	if (inobj.completedMissions == NULL)
	{
		os << "No missions completed before." << endl;
	}
	else
	{
		Mission* iter = inobj.completedMissions;
		while (iter != NULL)
		{
			os << "Mission number: " << iter->getMissionNumber() << " Mission name: " << iter->getName() << " Cost: " << iter->getCost() << endl;
			iter = iter->next;
		}
	}
	return os;
}