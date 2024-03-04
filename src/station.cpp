#include "station/station.h"

Station::Station(std::string id) 
{
    this->StationID(id);
    this->Bays(RepairBay('A'), RepairBay('B'), RepairBay('C'));
}

void Station::RepairTimeStep()
{
    for(auto& i : this->bays) {
        if(i.TimeToRepair() != 0) {
            i.DecrementRepairCounter();
        }
        // If the ship is ready to go
        else {
            i.RemoveShip();

            // Add in another one from the queue if applicable
            if(this->WaitLine().empty() != true) {
                Ship* holdingPtr;
                holdingPtr = this->waitLine.front();
                AddShipToBay(holdingPtr);
                this->RemoveShipFromQueue();
            }
        }
    }
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
            i.AddShip(toAdd);
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
    for(auto& i : this->Bays())
    {
        tempStr.append(i.toString());
        tempStr.append("\n");
    }

    // Add in queue information
    tempStr.append("Wait Line Size - ");
    tempStr.append(std::to_string(this->WaitLine().size()));

    return tempStr;
}
