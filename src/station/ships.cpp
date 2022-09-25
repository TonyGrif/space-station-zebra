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

void Ship::SetType()
{
    // Quick and dirty way
    srand((unsigned) time(NULL)); 
    // Min + (rand() % max)
    int randNum = (1 + (rand() % 100));

    if(randNum <= 51) {
        this->type = 'H';
    }
    else if(randNum <= 65) {
        this->type = 'F';
    }
    else if(randNum <= 75) {
        this->type = 'K';
    }
    else if(randNum <= 80) {
        this->type = 'R';
    }
    else {
        this->type = 'O';
    }
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