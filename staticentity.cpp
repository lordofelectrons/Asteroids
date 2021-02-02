#include "staticentity.h"

staticEntity::staticEntity(int x, int y, QPixmap* img)
{
    this->x = x;
    this->y = y;
    this->img = img;
}

staticEntity::~staticEntity()
{}
