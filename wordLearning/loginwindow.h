#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QKeyEvent>
#include <QEvent>
#include <QPoint>
#include <QCheckBox>
class loginWindow:public QMainWindow
{
    Q_OBJECT

public:
    loginWindow();
private:
    QLabel logininLabel;    //“登录界面”
    QLabel wordLearning;    //“单词学习”
    QLabel join_us; //“加入我们”
    QLabel usernameLabel;
    QLabel passwordLabel;
    QPushButton loginButton;
    QPushButton regisButton;
    QLineEdit usernameEdit;
    QLineEdit passwordEdit;
    QLabel rememberPasswordLabel;   //记住密码
    QCheckBox passwordBox;

    QPoint last;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


};

#endif // LOGINWINDOW_H
