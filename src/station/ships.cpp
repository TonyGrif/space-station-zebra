#include "ships.h"

Ship::Ship() 
{
    this->ShipID(1);
    this->SetType();
}

Ship::Ship(int id)
{
    this->ShipID(id);
    this->SetType();
}

void Ship::GenerateParts()
{
    
}

std::string Ship::toString() const
{
    std::string tempStr;

    tempStr += '#';
    tempStr.append(std::to_string(this->ShipID()));

    tempStr += " (Type ";
    tempStr += (this->Type());
    tempStr += ")";

    return tempStr;
}