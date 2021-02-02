#include "button.h"

Button::Button(int x, int y, QPixmap* img, QString text, short sizehor, short sizevert, short factsizevert, QSound* list) : staticEntity(x, y, img)
{
    this->text = text;
    this->sizehor = sizehor;
    this->sizevert = sizevert;
    this->factsizevert = factsizevert;
    this->list = list;
}

void Button::draw(QPainter* paint)
{
    paint->drawPixmap(x, y, img->copy(over * sizehor, 0, sizehor, factsizevert));
    paint->setPen(QPen(Qt::white));
    paint->setFont(QFont("Times New Roman", 28));
    paint->drawText(x, y, sizehor, sizevert, Qt::AlignCenter, text);
}

bool Button::isOver(int x, int y)
{
    if(this->x < x && x < this->x + sizehor && this->y < y && y < this->y + sizevert)
    {
        if(!over)
        {
            list->play();
        }
        over = true;
    }
    else if(over)
    {
        over = false;
    }
    return over;
}

Button::~Button()
{}
