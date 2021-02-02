#include "mainwindow.h"
#include <QApplication>
#include "constants.h"

int main(int argc, char *argv[])
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMaximumSize(WINDOWWIDTH, WINDOWHEIGHT);
    w.setMinimumSize(WINDOWWIDTH, WINDOWHEIGHT);
    return a.exec();
}
