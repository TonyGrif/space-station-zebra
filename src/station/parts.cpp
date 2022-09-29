#include "parts.h"

Part::Part()
{
    this->PartId(1);
    this->IsBroken(false);
}

Part::Part(int id)
{
    this->PartId(id);
    this->IsBroken(false);
}

std::string Part::toString() const
{
    std::string temp;

    temp.append("    Part #");
    temp += std::to_string(this->PartId());
    temp.append(" - ");
    temp += std::to_string(this->IsBroken());

    return temp;
}