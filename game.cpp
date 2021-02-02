#include "game.h"

void Game::setDef(QPixmap* aster, QPixmap* backgrounds,
                  QPixmap* buts, QPixmap* backbut, QPixmap* spaceship,
                 unsigned short* step, unsigned char* curback, bool* directions,
                  QPixmap* bul, QPixmap* rel, QPixmap* smallaster,
                  QLineEdit* line)
{
    this->aster = aster;
    this->smallaster = smallaster;
    this->backgrounds = backgrounds;
    this->buts = buts;
    this->backbut = backbut;
    this->spaceship = spaceship;
    this->step = step;
    this->curback = curback;
    this->directions = directions;
    this->bul = bul;
    this->rel = rel;
    this->line = line;
    relBar = new reloadBar(BARX, BARY, rel);
    for(unsigned char i = 0; i < BUTAMOUNT; i++)
    {
        buttons[i] = new Button(BUTSTARTX, BUTSTARTY + i * BUTHEIGHT, buts, texts[i], BUTWIDTH, BUTHEIGHT, BUTJURYHEIGHT, list);
    }
    back = new Button(0, 0, backbut, nullptr, BUTHEIGHT, BUTHEIGHT, BUTHEIGHT, list);
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Game::shoot()
{
    bullets.append(new Bullet(ship.getCoord(true) + SHIPSIZE / 4, ship.getCoord(false) + SHIPSIZE / 4, bul, ship.getAngle()));
}

Game& Game::getInstance()
{
    static Game theSingleInstance;
    return theSingleInstance;
}

void Game::action()
{
    checkControls();
    if(*step % UPDSTEP == 0)
    {
        relBar->action();
    }
    if(inGame)
    {
        if(qrand() % MAXCHANCE < GENCHANCE)
        {
            asteroids.append(genNewAster());
        }
    }
    if(*step % UPDSTEP == 0)
    {
        checkCollisions();
    }
}

void Game::checkCollisions()
{
    checkScreenBounds(&asteroids, ASTERSIZE);
    checkScreenBounds(&bullets, BULLETSIZE);
    for(int i = 0; i < asteroids.count(); i++)
    {
        for(int j = 0; j < bullets.count(); j++)
        {
            if(asteroids[i]->checkBUM(bullets[j]->getCoord(true) + BULLETSIZE / 2, bullets[j]->getCoord(false) + BULLETSIZE / 2))
            {
                if(asteroids[i]->isBig())
                {
                    createPieces(asteroids[i]);
                    score += SCOREBIG;
                }
                else
                {
                    score += SCORESMALL;
                }
                delete asteroids[i];
                delete bullets[j];
                asteroids.removeAt(i);
                bullets.removeAt(j);
                crack->play();
                return;
            }
        }

        if(asteroids[i]->checkBUM(ship.getCoord(true) + SHIPSIZE / 2, ship.getCoord(false) + SHIPSIZE / 2))
        {
            backToMain();
        }
    }
}

void Game::setSounds(QSound* crack, QSound* list)
{
    this->crack = crack;
    this->list = list;
}

template<class T>
void Game::checkScreenBounds(T* smth, int size)
{
    int x = 0, y = 0;
    for(int i = 0; i < smth->count(); i++)
    {
        x = (*smth)[i]->getCoord(true);
        y = (*smth)[i]->getCoord(false);
        if(x < -size || y < -size || x > WINDOWWIDTH || y > WINDOWHEIGHT)
        {
            delete (*smth)[i];
            (*smth).removeAt(i);
        }
    }

}

void Game::createPieces(Asteroid* potsient)
{
    unsigned char amount = qrand() % SMALLMAX + SMALLMIN;
    int anglestep = MAXTURN / amount;
    short angle = 0;
    int x = potsient->getCoord(true) + ASTERSIZE / 2 - SMALLASTERSIZE / 2;
    int y = potsient->getCoord(false) + ASTERSIZE / 2 - SMALLASTERSIZE / 2;
    for(unsigned char i = 0; i < amount; i++)
    {
        asteroids.append(new Asteroid(x, y, smallaster, angle, potsient->getType()));
        angle += anglestep;
    }
}

void Game::checkControls()
{
    if(*(directions + 2))
    {
        ship.moveside(false);
    }
    else if(*(directions + 3))
    {
        ship.moveside(true);
    }
    if(*(directions))
    {
        ship.movestraight(true);
    }
    else if(*(directions + 1))
    {
        ship.movestraight(false);
    }
}

void Game::draw(QPainter* paint)
{
    if(inGame)
    {
        for(auto& bul : bullets)
        {
            bul->draw(paint);
        }
        ship.draw(paint);
        for(auto& ast : asteroids)
        {
            ast->draw(paint);
        }
        paint->setPen(QPen(Qt::white));
        paint->setFont(QFont("Times New Roman", 25));
        QString str;
        str.setNum(score);
        paint->drawText(0,0,WINDOWWIDTH,BUTHEIGHT,Qt::AlignRight, str);
        back->draw(paint);
        relBar->draw(paint);
    }
    else
    {
        for(unsigned char i = 0; i < BUTAMOUNT; i++)
        {
            buttons[i]->draw(paint);
        }
    }
}

bool Game::isInGame()
{
    return inGame;
}

void Game::checkCoord(int x, int y, bool press)
{
    short mode = -1;
    if(inGame)
    {
        if(back->isOver(x, y) && press)
        {
            mode = 4;
        }
    }
    else
    {
        for(unsigned char i = 0; i < BUTAMOUNT; i++)
        {
            if(buttons[i]->isOver(x, y) && press)
            {
                mode = i;
                break;
            }
        }
    }
    if(mode >= 0)
    {
        list->play();
    }

    switch(mode)
    {
    case 0:
    {
        startGame();
        break;
    }
    case 1:
    {
        showRecords();
        break;
    }
    case 2:
    {
        mes.setText(helptext);
        mes.show();
        break;
    }
    case 3:
    {
        qApp->exit();
        break;
    }
    case 4:
    {
        backToMain();
        break;
    }
    }
}

Asteroid* Game::genNewAster()
{
    bool side = qrand() % 2, side1 = qrand() % 2;
    int x = -ASTERSIZE, y = -ASTERSIZE;
    short angle = qrand() % HALFCIRCLE;
    if(side && side1)
    {
        y = qrand() % WINDOWHEIGHT;
    }
    else if(side)
    {
        y = qrand() % WINDOWHEIGHT;
        x = WINDOWWIDTH + ASTERSIZE;
        angle = MAXTURN - angle;
    }
    else if(side1)
    {
        y = WINDOWHEIGHT + ASTERSIZE;
        x = qrand() % WINDOWWIDTH;
        angle -= (HALFCIRCLE / 2);
    }
    else
    {
        x = qrand() % WINDOWWIDTH;
        angle += (HALFCIRCLE / 2);
    }
    return new Asteroid(x, y, aster, angle, qrand() % ASTERTYPES);
}

void Game::startGame()
{
    readRecords();
    inGame = true;
    score = 0;
    *curback = qrand() % (FRAMESAMOUNT - 1) + 1;
    ship.setDef(WINDOWWIDTH / 2 - SHIPSIZE / 2, WINDOWHEIGHT / 2 - SHIPSIZE / 2, spaceship, bul, step);
}

void Game::showRecords()
{
    std::string str = "";
    readRecords();
    qDebug()<<names.count();
    for(int i = 0; i < names.count(); i++)
    {
        str = str + names[i] + ' ' + QString::number(records[i]).toLocal8Bit().constData() + '\n';
    }
    mes.setText(QString::fromStdString(str));
    mes.show();
}

void Game::clearMem()
{
    for(auto& bul : bullets)
    {
        delete bul;
    }
    for(auto& aster : asteroids)
    {
        delete aster;
    }
    bullets.clear();
    asteroids.clear();
}

void Game::backToMain()
{
    inGame = false;
    *curback = 0;
    addRecord();
    clearMem();
}

void Game::readRecords()
{
    names.clear();
    records.clear();
    std::ifstream in(recordPath);
    if(!in.is_open())
    {
        std::ofstream create(recordPath);
        create.close();
        readRecords();
        return;
    }
    int n = 0;
    in>>n;
    qDebug()<<n;
    for(int i = 0; i < n; i++)
    {
        std::string name;
        unsigned int rec = 0;
        in>>name>>rec;
        names.append(name);
        records.append(rec);
    }
    in.close();
}

void Game::writeRecords()
{
    std::ofstream out(recordPath);
    out<<names.count()<<std::endl;
    for(int i = 0; i < names.count(); i++)
    {
        out<<names[i]<<' '<<records[i]<<std::endl;
    }
    out.close();
}

void Game::addRecord()
{
    bool washere = false;
    for(int i = 0; i < names.count(); i++)
    {
        if(QString::fromStdString(names[i]) == line->text())
        {
            if(records[i] < score)
            {
                records[i] = score;
            }
            washere = true;
            break;
        }
    }
    if(!washere)
    {
        names.append(line->text().toLocal8Bit().constData());
        records.append(score);
    }
    writeRecords();
}
