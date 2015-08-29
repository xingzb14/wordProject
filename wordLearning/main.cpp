
#include <QApplication>
#include "loginwindow.h"
#include "registerwindow.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainWindow window;
    window.show();
    return app.exec();
}
