#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QComboBox>
class registerWindow:public QMainWindow
{
public:
    registerWindow();
private:
    QLabel logo;
    QLabel registerTip;         //杂文字
    QLabel usernameLabel;
    QLineEdit usernameEdit;
    QLabel pswdLabel;
    QLabel pswdLabelConf;
    QLineEdit pswdEdit;
    QLineEdit pswdEditConf;
    QLabel nameLabel;
    QLineEdit nameEdit;
    QComboBox wordNumberBox;
    QLabel wordNumberLabel;
    QPushButton registerButton;
    QPushButton backButton;
    QPushButton notRepeatButton;
    QPushButton notRepeatLabel;
signals:
    void usernameError();
    void usernameRepeat();
    void pswdConf();

};

#endif // REGISTERWINDOW_H
