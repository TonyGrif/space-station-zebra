#include "repairBay.h"

RepairBay::RepairBay()
{
    this->Designation('A');
    this->CurrentShip(NULL);
}

RepairBay::RepairBay(char d, Ship* ptr)
{
    this->Designation(d);
    this->CurrentShip(ptr);
}

std::string RepairBay::toString() const
{
    std::string tempStr;

    tempStr.append("Repair Bay ");
    tempStr += this->Designation();

    if(this->IsFull() == false)
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