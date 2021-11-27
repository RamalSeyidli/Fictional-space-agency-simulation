#ifndef PERSON_H
#define PERSON_H

/*
Author name: Ramal Seyidli

Author id: 150180901
*/

#include <string>	//string library
#include <cstring>	//c string library
#include <cctype>	//isupper, isdigit
#include <iostream>	

using namespace std;

//Base class Person
class Person
{
protected:
	string name;
	string surname;
public:
	Person(string newName, string newSurname) :name(newName), surname(newSurname){}
	string getName() { return name; }
	string getSurname() { return surname; }
};



//Derieved from Person class 
class Passenger:public Person
{
	int cash;
	bool ticket;
public:
	Passenger(string newName, string newSurname, int newCash) :Person(newName, newSurname), cash(newCash) { next = NULL; }
	Passenger(string newName, string newSurname):Person(newName, newSurname){ next = NULL; }
	~Passenger();
	bool buyTicket(int);
	bool getTicket() { return ticket; }
	Passenger* next;
};


//Derieved from Person class 

class Astronaut :public Person
{
	int numMissions;
public:
	Astronaut(string newName, string newSurname, int newNumMissions);
	Astronaut(string newName, string newSurname) :Person(newName, newSurname) { next = NULL; }
	~Astronaut();
	void completeMission();
	Astronaut* next;	//Linked list attribute
	int getNumMissions() { return numMissions; }
};

#endif