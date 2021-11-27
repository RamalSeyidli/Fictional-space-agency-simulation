#include "Mission.h"


/*
Author name: Ramal Seyidli

Author id: 150180901
*/


using namespace std;

class Agency
{
	string name;
	int cash;
	int ticketPrice;
	Mission* completedMissions;
	Mission* nextMissions;
public:
	Agency(string, int, int);	//Constructor
	~Agency();	//Destructor

	void addMission(Mission&);

	void executeNextMission();

	friend ostream& operator<<(ostream&, Agency&);

	void setTicketPrice(int newPrice) { ticketPrice = newPrice; }	//Inline function

	//Added by me

	void setCash(int newCash) { cash = newCash; }
	int getCash() { return cash; }
	string getName() { return name; }
	
	int getTicketPrice() { return ticketPrice; }
};
