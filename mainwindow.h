#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QPixmap aster;
    QPixmap smallaster;
    QPixmap backgrounds;
    QPixmap buts;
    QPixmap backbut;
    QPixmap spaceship;
    QPixmap bul;
    QPixmap rel;
    QTimer* updtim;
    Game& game = Game::getInstance();
    //up down left right
    bool directions[DIRAMOUNT] = {false, false, false, false};
    unsigned short step = 0;
    unsigned char curbackframe = 0;
    void checkClick(QKeyEvent* event, bool mode);
    QSound* shootsound;
    QLineEdit* namein;

private slots:
    void updsl();
};

#endif // MAINWINDOW_H
