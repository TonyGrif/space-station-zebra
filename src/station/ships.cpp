#include "ships.h"

Ship::Ship() 
{
    this->ShipID(1);
    this->Build();
}

Ship::Ship(int id)
{
    this->ShipID(id);
    this->Build();
}

void Ship::SetType()
{
    // Generate number of parts
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uiDistro(0, 100);

    int randNum = uiDistro(gen);

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
    bool isEven = false;
    bool isOdd = false;
    int minVal, maxVal;

    if(this->Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(this->Type() == 'F') {
        minVal = 75;
        maxVal= 150;
    }
    else if(this->Type() == 'K') {
        minVal = 2;
        maxVal= 200;
        isEven = true;
    }
    else if(this->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
        isOdd = true;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    // Special case, generate 100 random parts with ids in the range provided
    if(this->Type() == 'O') {
        std::random_device rd;
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(minVal, maxVal); // define the range

        for(int x = 0; x < 100; x++) {
            int randNum = distr(gen);
            Part* ptr = new Part(randNum);

            this->parts.push_back(*ptr);
        }
        return;
    }

    for(int x = minVal; x <= maxVal; x++) {
        if(isEven == true && (x%2 != 0)) {
            continue;
        }
        else if(isOdd == true && (x%2 ==0)) {
            continue;
        }
        Part* ptr = new Part(x);

        this->parts.push_back(*ptr);
    }
}

std::string Ship::toString() const
{
    std::string tempStr;

    tempStr += '#';
    tempStr.append(std::to_string(this->ShipID()));

    tempStr += " (Type ";
    tempStr += (this->Type());
    tempStr += ")";

    tempStr += "\n";
    for(auto& i : this->GetParts()) {
        tempStr += i.toString();
        tempStr += "\n";
    }

    return tempStr;
}