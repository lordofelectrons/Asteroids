#include "doubleentity.h"

doubleEntity::doubleEntity(double x, double y, QPixmap* img)
{
    this->x = x;
    this->y = y;
    this->img = img;
}

int doubleEntity::getCoord(bool mode)
{
    if(mode)
    {
        return static_cast<int>(x);
    }
    else
    {
        return static_cast<int>(y);
    }
}

doubleEntity::~doubleEntity()
{}
