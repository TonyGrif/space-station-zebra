#include "ships.h"

Ship::Ship() 
{
    this->ShipID(1);
    this->Type('A');
}

Ship::Ship(int id)
{
    this->ShipID(id);
    this->Type('A');
}

Ship::Ship(char t)
{
    this->ShipID(1);
    this->Type(t);
}

Ship::Ship(int id, char t)
{
    this->ShipID(id);
    this->Type(t);
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