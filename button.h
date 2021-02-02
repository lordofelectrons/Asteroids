#ifndef BUTTON_H
#define BUTTON_H

#include "staticentity.h"

class Button : staticEntity
{
public:
    Button(int x, int y, QPixmap* img, QString text, short sizehor, short sizevert, short factsizevert, QSound* list);
    bool isOver(int x, int y);
    virtual void draw(QPainter* paint);
    virtual ~Button();

private:
    QString text;
    QSound* list = nullptr;
    bool over = false;
    short sizehor = 0, sizevert = 0, factsizevert = 0;
};

#endif // BUTTON_H
