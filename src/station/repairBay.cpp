#include "repairBay.h"

RepairBay::RepairBay()
{
    this->Designation('A');
    this->CurrentShip(NULL);
    this->CalculateRepairTime();
}

RepairBay::RepairBay(char d, Ship* ptr)
{
    this->Designation(d);
    this->CurrentShip(ptr);
    this->CalculateRepairTime();
}

void RepairBay::CalculateRepairTime() 
{
    if(this->CurrentShip() == NULL) {
        this->repairTime = 0;
        return;
    }

    int minTime, maxTime;

    switch (this->CurrentShip()->Type())
    {
    case 'H':
        minTime = 1;
        maxTime = 5;
        break;

    case 'F':
        minTime = 2;
        maxTime = 7;
        break;

    case 'K':
        minTime = 2;
        maxTime = 6;
        break;

    case 'R':
        minTime = 3;
        maxTime = 7;
        break;
    
    case 'O':
        minTime = 1;
        maxTime = 10;
        break;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uiDistro(minTime, maxTime);
    
    for(auto& i : this->CurrentShip()->GetParts()) {
        if(i.IsBroken()) {
            repairTime += uiDistro(gen);
        }
    }
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

    tempStr.append("ETA - ");
    tempStr.append(std::to_string(this->TimeToRepair()));
    tempStr.append(" Time Cycles to Repair");
    tempStr.append("\n");

    return tempStr;
}