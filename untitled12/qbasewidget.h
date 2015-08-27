#ifndef QBASEWIDGET_H
#define QBASEWIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QKeyEvent>
class QBaseWidget:public QMainWindow
{
    Q_OBJECT
public:
    QBaseWidget();
private:
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit usernameEdit;
    QLineEdit passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;

    QPoint last;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
signals:
    void loginSuccess();
public slots:
    void validate();
    void openWidgets2();

};

#endif // QBASEWIDGET_H
