#include "qbasewidget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QBaseWidget loginin;
    loginin.show();
    return app.exec();
}
