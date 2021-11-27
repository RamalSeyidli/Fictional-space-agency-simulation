#include "Person.h"
#include "Mission.h"
#include "Agency.h"

#include <iostream>
#include <cstdlib>


using namespace std;

// Initialize the static member
int Mission::numMissions = 0;

int main(int argc, char const *argv[])
{
    // Set the PRNG seed
    srand(1773);


    cout << "*** Agency creation ***" << endl;
    // Create agency with given name, cash and ticket price
    Agency newAgency = Agency("NASA",20000,-40);
    cout << newAgency;
    // Set the ticket price which is set to 0 before
    newAgency.setTicketPrice(10000);
    // Print agency information
    cout << newAgency;
    // Execute the next mission
    newAgency.executeNextMission();

    cout << endl << "*** Astronaut creation ***" << endl;
    // Create astronauts
    Astronaut* astronautList[5];
    astronautList[0] = new Astronaut("Neil","Armstrong",3);
    astronautList[1] = new Astronaut("Buzz","Aldrin",-4);
    astronautList[2] = new Astronaut("Sally","Ride");
    astronautList[3] = new Astronaut("Judith","Resnik",4);
    astronautList[4] = new Astronaut("Yuri","Gagarin",5);


    cout << endl << "*** Passenger creation ***" << endl;
    // Create astronauts
    Passenger* passengerList[5];
    passengerList[0] = new Passenger("Dennis","Tito",12000);
    passengerList[1] = new Passenger("Mark","Shuttleworth",10000);
    passengerList[2] = new Passenger("Gregory","Olsen",15000);
    passengerList[3] = new Passenger("Charles","Simonyi",24000);
    passengerList[4] = new Passenger("Alperen","Kantarcı");

    // Every passenger tries to buy a ticket
    for(int i=0; i<5; i++){
        passengerList[i]->buyTicket(newAgency.getTicketPrice());
    }
    
    cout << endl << "*** Moon mission creation ***" << endl;

    // Create moon mission
    Mission moonMission = Mission("MN-01",5000,20);
    
    moonMission += astronautList[0];
    moonMission += astronautList[1];
    moonMission += astronautList[2];
    moonMission += passengerList[0];
    moonMission += passengerList[1];
    moonMission += passengerList[2];
    newAgency.addMission(moonMission);

    
    
    cout << endl << "*** Venus mission creation ***" << endl;
    
    // Create venus mission
    Mission venusMission = Mission("TG223",35000,80);		//Here

    cout << "Name of the mission: " << venusMission.getName() << endl;
    venusMission.setName("VS-01");
    
    venusMission += astronautList[3];
    venusMission += astronautList[4];
    venusMission += passengerList[3];
    venusMission += passengerList[4];
    
    newAgency.addMission(venusMission);

    cout << endl << "*** Mission creation finished ***" << endl;
    // Show information of the agency
    cout << newAgency;

    cout << endl << "*** Lift off ***" << endl;
    // Execute next mission
    newAgency.executeNextMission();

    cout << newAgency;

    cout << endl << "*** Lift off ***" << endl;
    // Execute another mission
    newAgency.executeNextMission();

    cout << newAgency << endl;
    
    // Delete the allocated space
    for(int i=0; i<5; i++){
        delete astronautList[i];
        delete passengerList[i];
    }

    return 0;
}
