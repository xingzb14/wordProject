#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QTime>
class mainWindow:public QMainWindow
{
    Q_OBJECT
public:
    mainWindow();
private:
    QLabel nickNameLabel;
    QLabel tipLabel;
    QLabel time;
    QLineEdit inquireEdit;
    QPushButton search;
    QLabel dayEnglish_1;
    QLabel wordEnglish_2;
    QLabel testEnglish_3;

    QPoint last;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void tim_slot();
};

#endif // MAINWINDOW_H
