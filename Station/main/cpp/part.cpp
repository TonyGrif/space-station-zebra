#include "../headers/part.h"

Part::Part(int id, bool b)
{
    this->PartId(id);
    this->IsBroken(b);
}

bool Part::operator==(const Part& rhs) const
{
    if(this->PartId() == rhs.PartId() && this->IsBroken() == rhs.IsBroken()) 
    {
        return true;
    }
    return false;
}

bool Part::operator<(const Part& rhs) const
{
    if(this->PartId() != rhs.PartId()) {
        return (this->PartId() < rhs.PartId());
    }
    return false;
}

std::string Part::toString() const
{
    std::string temp;

    temp.append("Part #");
    temp += std::to_string(this->PartId());
    temp.append(" - ");
    temp += std::to_string(this->IsBroken());

    return temp;
}