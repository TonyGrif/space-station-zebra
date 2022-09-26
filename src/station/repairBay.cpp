#include "repairBay.h"

RepairBay::RepairBay()
{
    this->Designation('A');
    this->CurrentShip(NULL);
}

RepairBay::RepairBay(char d)
{
    this->Designation(d);
    this->CurrentShip(NULL);
}

RepairBay::RepairBay(Ship* sPtr)
{
    this->Designation('A');
    this->CurrentShip(sPtr);
}

std::string RepairBay::toString() const
{
    std::string tempStr;

    tempStr.append("Repair Bay ");
    tempStr += this->Designation();

    if(this->IsFull() != true)
    {
        tempStr.append(" - Empty");
    }
    else
    {
        tempStr.append(" - ");
        tempStr.append(this->CurrentShip()->toString());
    }

    return tempStr;
}