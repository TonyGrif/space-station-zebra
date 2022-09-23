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