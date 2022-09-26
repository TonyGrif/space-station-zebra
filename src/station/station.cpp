#include "station.h"

Station::Station() 
{
    this->StationID("Zebra");
    this->Bays(RepairBay('A'), RepairBay('B'), RepairBay('C'));
    // Queue is already initialized
}

Station::Station(std::string id)
{
    this->StationID(id);
    this->Bays(RepairBay('A'), RepairBay('B'), RepairBay('C'));
}

Station::Station(RepairBay a, RepairBay b, RepairBay c)
{
    this->StationID("Zebra");
    this->Bays(a, b, c);
}

void Station::AddShip(Ship* toAdd)
{
    Ship* tempPtr;

    // If there is already a line, add to queue
    if(this->WaitLine().empty() != true) {
        this->AddShipToQueue(toAdd);

        // Ship to add will be the one at the front of the queue
        // Not popped off the queue until we can determine if it is added to a bay
        tempPtr = this->waitLine.front();
        if(this->AddShipToBay(tempPtr) == true) {
            this->RemoveShipFromQueue();
        }
    }
    else {
        tempPtr = toAdd;
        if(this->AddShipToBay(tempPtr) != true) {
            this->AddShipToQueue(tempPtr);
        }
    }
}

bool Station::AddShipToBay(Ship* toAdd)
{
    for(auto& i : this->bays) {
        if(i.IsFull() == false) {
            i.CurrentShip(toAdd);
            return true;
        }
    }
    return false;
}

std::string Station::toString() const
{
    std::string tempStr;

    // Add in station information
    tempStr.append("Status report for " + this->StationID() + "\n");
    tempStr.append("=============================================");
    tempStr.append("\n");

    // Add in repair bay information
    // TODO: Iterator support
    for(int x = 0; x < NUM_OF_REPAIR_BAYS; x++)
    {
        tempStr.append(bays[x].toString());
        tempStr.append("\n");
    }

    // Add in queue information
    tempStr.append("Wait Line Size - ");
    tempStr.append(std::to_string(this->WaitLine().size()));

    return tempStr;
}