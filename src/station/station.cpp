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

void Station::AddShipToBay(Ship* toAdd)
{
    for(int x = 0; x < NUM_OF_REPAIR_BAYS; x++)
    {
        if(this->Bays()[x].IsFull() == false) {
            this->bays[x].CurrentShip(toAdd);
            return;
        }
    }
    this->AddShipToQueue(toAdd);
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