#include "station/station.h"

Station::Station(std::string id) : bays{RepairBay('A'), RepairBay('B'), RepairBay('C')}
{
    this->StationID(id);
}

void Station::RepairTimeStep()
{
    for (auto& i : this->bays)
    {
        if (i.TimeToRepair() != 0)
        {
            i.DecrementRepairCounter();
        }
        // If the ship is ready to go
        else
        {
            i.RemoveShip();

            // Add in another one from the queue if applicable
            if (this->WaitLine().empty() != true)
            {
                if (this->AddShipToBay(this->waitLine.front()))
                {
                    this->RemoveShipFromQueue();
                }
            }
        }
    }
}

void Station::AddShip(std::unique_ptr<Ship> toAdd)
{
    // If there is already a line, add to queue
    if (this->WaitLine().empty() != true)
    {
        this->AddShipToQueue(std::move(toAdd));

        // Ship to add will be the one at the front of the queue
        // Not popped off the queue until we can determine if it is added to a bay
        if (this->AddShipToBay(this->waitLine.front()) == true)
        {
            this->RemoveShipFromQueue();
        }
    }
    else
    {
        if (this->AddShipToBay(toAdd) != true)
        {
            this->AddShipToQueue(std::move(toAdd));
        }
    }
}

bool Station::AddShipToBay(std::unique_ptr<Ship>& toAdd)
{
    for (auto& i : this->bays)
    {
        if (i.IsFull() == false)
        {
            i.AddShip(std::move(toAdd));
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
    for (auto& i : this->Bays())
    {
        tempStr.append(i.toString());
        tempStr.append("\n");
    }

    // Add in queue information
    tempStr.append("Wait Line Size - ");
    tempStr.append(std::to_string(this->WaitLine().size()));

    return tempStr;
}
