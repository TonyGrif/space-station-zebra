#include "parts.h"

Parts::Parts()
{
    this->PartId(1);
    this->IsBroken(false);
}

Parts::Parts(int id, bool b)
{
    this->PartId(id);
    this->IsBroken(b);
}

std::string Parts::toString() const
{
    std::string temp;

    temp.append("    Part #");
    temp += std::to_string(this->PartId());
    temp.append(" - ");
    temp += std::to_string(this->IsBroken());

    return temp;
}