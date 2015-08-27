#include "qbasewidget.h"
#include "widget2.h"
#include <QToolButton>
#include <QStyle>
QBaseWidget::QBaseWidget()
{
    this->resize(250,300);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:lightblue");
    background->setGeometry(0,0,this->width(),this->height());

    int width = this->width();
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton = new QToolButton(this);

    connect(minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    minButton->setGeometry(width-50,5,20,20);
    closeButton->setGeometry(width-25,5,20,20);

    QPixmap minPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));

    minButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent;");

    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *loginButton;
    QPushButton *registerButton;

    loginButton = new QPushButton(this);
    registerButton = new QPushButton(this);
    loginButton->setGeometry(QRect(60,250,60,20));
    registerButton->setGeometry(QRect(130,250,60,20));
    loginButton->setText("登录");
    loginButton->setStyleSheet("color:blue;");
    registerButton->setText("注册");
    loginButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background:purple;color:yellow");
    connect(loginButton, SIGNAL(clicked()), this, SLOT(validate()));
    connect(this, SIGNAL(loginSuccess()), this, SLOT(openWidgets2()));
    connect(this, SIGNAL(loginSuccess()), this, SLOT(close()));

    usernameEdit.setParent(this);
    passwordEdit.setParent(this);
    usernameEdit.setGeometry(QRect(110,190,100,20));
    passwordEdit.setGeometry(QRect(110,220,100,20));
    usernameEdit.setMaxLength(20);
    passwordEdit.setMaxLength(20);
    passwordEdit.setEchoMode(QLineEdit::Password);
    usernameEdit.setFocus();

    usernameLabel = new QLabel(this);
    passwordLabel = new QLabel(this);
    usernameLabel->setGeometry(QRect(50,190,40,20));
    passwordLabel->setGeometry(QRect(50,220,40,20));
    usernameLabel->setText("username");
    passwordLabel->setText("password");

}

void QBaseWidget::openWidgets2()
{
    widget2 *widget = new widget2();
    widget->show();
}

void QBaseWidget::validate()
{
    if(usernameEdit.text()=="admin" && passwordEdit.text()=="admin")
        loginSuccess();
    else
        QMessageBox::warning(this,"warning", tr("输入的用户名或密码错误！"),QMessageBox::Yes);


}

void QBaseWidget::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void QBaseWidget::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void QBaseWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}
void QBaseWidget::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Enter||Qt::Key_Return)
    {
        validate();
    }
}
