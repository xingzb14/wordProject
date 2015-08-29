#include "loginwindow.h"
#include <QToolButton>
#include <QStyle>

loginWindow::loginWindow()
{
    this->resize(480,240);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:lightblue");
    background->setGeometry(0,0,this->width(),this->height());

    int width = this->width();
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton = new QToolButton(this);

    connect(minButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    minButton->setGeometry(width-50, 5, 20, 20);
    closeButton->setGeometry(width-25, 5, 20, 20);

    QPixmap minPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    minButton->setToolTip("最小化");
    closeButton->setToolTip("关闭");

    minButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");

    logininLabel.setParent(this);
    logininLabel.setGeometry(QRect(20, 30, 150, 60));
    logininLabel.setText("登陆界面");
    logininLabel.setStyleSheet("font-size:30px;color:black");

    wordLearning.setParent(this);
    wordLearning.setGeometry(QRect(280, 20, 180, 80));
    wordLearning.setText("单词攻克者");
    wordLearning.setStyleSheet("font-size:30px");

    join_us.setParent(this);
    join_us.setGeometry(QRect(280, 120, 200, 40));
    join_us.setText("  如果还没有加入我们\n请点击注册以获得更佳体验");

    usernameLabel.setParent(this);
    usernameLabel.setGeometry(QRect(50, 100, 50, 20));
    usernameLabel.setText("用户名");

    passwordLabel.setParent(this);
    passwordLabel.setGeometry(QRect(50, 130, 50, 20));
    passwordLabel.setText("密码");

    usernameEdit.setParent(this);
    usernameEdit.setGeometry(QRect(105, 100, 120, 20));
    usernameEdit.setMaxLength(20);
    usernameEdit.setFocus();
    passwordEdit.setParent(this);
    passwordEdit.setGeometry(QRect(105, 130, 120, 20));
    passwordEdit.setMaxLength(25);
    passwordEdit.setEchoMode(QLineEdit::Password);

    loginButton.setParent(this);
    regisButton.setParent(this);
    loginButton.setGeometry(QRect(100, 180, 100, 30));
    loginButton.setText("login");
    regisButton.setGeometry(QRect(305, 180, 100, 30));
    regisButton.setText("点我注册");

    passwordBox.setParent(this);
    passwordBox.setGeometry(145, 155, 15, 15);
    rememberPasswordLabel.setParent(this);
    rememberPasswordLabel.setGeometry(165, 155, 70, 15);
    rememberPasswordLabel.setText("记住密码");

}

void loginWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void loginWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void loginWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}
