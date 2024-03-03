#include "../headers/ships.h"

std::default_random_engine Ship::gen = std::default_random_engine(std::random_device{}());

// Used due to MinGW limitations
// std::default_random_engine Ship::gen = std::default_random_engine(time(NULL));

Ship::Ship(int id) 
{
    this->ShipID(id);
    this->SetType();
    this->GenerateParts();
}

void Ship::SetType()
{
    std::uniform_int_distribution<> uiDistro(0, 100);

    int randNum = uiDistro(Ship::gen);

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
    else if(randNum <= 100) {
        this->type = 'O';
    }
}

void Ship::GenerateParts()
{
    bool isEven = false;
    bool isOdd = false;
    int minVal, maxVal;
    // Representation of the percent chance of a broken part (8 = 8%)
    int brokenVal;

    if(this->Type() == 'H') {
        minVal = 1;
        maxVal= 100;
        brokenVal = 5; // 5%
    }
    else if(this->Type() == 'F') {
        minVal = 75;
        maxVal= 150;
        brokenVal = 8; // 8%
    }
    else if(this->Type() == 'K') {
        minVal = 2;
        maxVal= 200;
        isEven = true;
        brokenVal = 6;
    }
    else if(this->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
        isOdd = true;
        brokenVal = 6;
    }
    else {
        minVal = 200;
        maxVal = 999;
        brokenVal = 7;
    }

    std::uniform_int_distribution<> brokenDistro(0, 100);

    // Special case, generate 100 random parts with ids in the range provided
    if(this->Type() == 'O') {
        std::uniform_int_distribution<> distr(minVal, maxVal);

        for(int x = 0; x < 100; x++) {
            int randNum = distr(Ship::gen);
            int broken = brokenDistro(Ship::gen);

            Part* ptr;

            if(broken <= brokenVal) {
                ptr = new Part(randNum, true);
            }
            else {
                ptr = new Part(randNum);
            }

            this->parts.push_back(*ptr);
            this->parts.sort();
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

        int broken = brokenDistro(Ship::gen);
        Part* ptr;
        
        if(broken <= brokenVal) {
            ptr = new Part(x, true);
        }
        else {
            ptr = new Part(x);
        }

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
        if(i.IsBroken() == true)
        {
            tempStr += "    ";
            tempStr += i.toString();
            tempStr += "\n";
        }
    }

    return tempStr;
}