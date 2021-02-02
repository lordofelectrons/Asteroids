#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updtim = new QTimer();
    connect(updtim, SIGNAL(timeout()), this, SLOT(updsl()));
    aster.load(":/image/asteroid!!.png");
    smallaster.load(":/image/smallasteroids.png");
    backgrounds.load(":/image/backgrounds.jpg");
    buts.load(":/image/buts.png");
    backbut.load(":/image/backbut.png");
    spaceship.load(":/image/spaceships.png");
    bul.load(":/image/bul.png");
    rel.load(":/image/reload.png");
    shootsound = new QSound(":/sounds/shoot.wav");
    setWindowIcon(QIcon(":/image/icon.ico"));
    setIconSize(QSize(ASTERSIZE, ASTERSIZE));
    game.setSounds(new QSound(":/sounds/crack.wav"), new QSound(":/sounds/list.wav"));
    updtim->start(15);
    this->setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    namein = new QLineEdit(this);
    namein->setStyleSheet("QLineEdit {background-color: rgba(0, 0, 0, 0); color: white;}");
    namein->setFont(QFont("Times New Roman", 25, Qt::white));
    namein->move(BUTSTARTX, BUTSTARTY - BUTHEIGHT);
    namein->setMinimumSize(QSize(BUTWIDTH, NAMEHEIGHT));
    namein->setAlignment(Qt::AlignCenter);
    namein->setMaxLength(17);
    namein->setText("DefaultPlayer");
    game.setDef(&aster, &backgrounds, &buts, &backbut, &spaceship, &step, &curbackframe, &directions[0], &bul, &rel, &smallaster, namein);
}

void MainWindow::updsl()
{
    if(step % UPDSTEP == 0)
    {
        update();
    }
    if(step < MAXSHORT)
    {
        step++;
    }
    else
    {
        step = 0;
    }
    game.action();
    namein->setVisible(!game.isInGame());
    if(game.isInGame())
    {
        setFocus();
    }
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    paint.drawPixmap(0, 0, backgrounds.copy(curbackframe * WINDOWWIDTH, 0, WINDOWWIDTH, WINDOWHEIGHT));
    game.draw(&paint);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x(), y = event->y();
    game.checkCoord(x, y, true);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x(), y = event->y();
    game.checkCoord(x, y);
}

void MainWindow::checkClick(QKeyEvent* event, bool mode)
{
    if(!event->isAutoRepeat())
    {
        short num = -1;
        switch(event->key())
        {
        case Qt::Key_Up:
        {
            num = 0;
            break;
        }
        case Qt::Key_Down:
        {
            num = 1;
            break;
        }
        case Qt::Key_Left:
        {
            num = 2;
            break;
        }
        case Qt::Key_Right:
        {
            num = 3;
            break;
        }
        }
        if(num >= 0)
        {
            directions[num] = mode;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    checkClick(event, true);
    if(event->key() == Qt::Key_Space)
    {
        if(game.relBar->shoot())
        {
            shootsound->play();
            game.shoot();
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    checkClick(event, false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
