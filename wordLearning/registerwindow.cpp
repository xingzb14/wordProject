#include "registerwindow.h"

registerWindow::registerWindow()
{
    this->resize(290, 350);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:lightblue");
    background->setGeometry(0,0,this->width(),this->height());

    logo.setParent(this);
    logo.setText("logo");
    logo.setGeometry(QRect(20, 20, 40, 40));
    logo.setStyleSheet("background:yellow");

    registerTip.setParent(this);
    registerTip.setGeometry(QRect(70, 20, 200, 40));
    registerTip.setText("注册可以获得更好的体验");

    usernameLabel.setParent(this);
    usernameLabel.setGeometry(QRect(30, 80, 80, 25));
    usernameLabel.setText("设置用户名");

    usernameEdit.setParent(this);
    usernameEdit.setGeometry(QRect(120, 80, 150, 25));
    usernameEdit.setMaxLength(16);
    usernameEdit.setFocus();

    notRepeatLabel.setParent(this);
    notRepeatLabel.setGeometry(QRect(120, 120, 80, 25));
    notRepeatLabel.setStyleSheet("background-color:transparent;font-size:11px");
    notRepeatLabel.setText("请确认您的用户名");
    notRepeatButton.setParent(this);
    notRepeatButton.setGeometry(QRect(210, 120, 70, 25));
    notRepeatButton.setText("确认");

    pswdLabel.setParent(this);
    pswdLabel.setGeometry(QRect(30, 160, 80, 25));
    pswdLabel.setText("设置密码");
    pswdEdit.setParent(this);
    pswdEdit.setGeometry(QRect(120, 160, 150, 25));
    pswdEdit.setEchoMode(QLineEdit::Password);

    pswdLabelConf.setParent(this);
    pswdLabelConf.setGeometry(QRect(30, 210, 80, 25));
    pswdLabelConf.setText("确认密码");
    pswdEditConf.setParent(this);
    pswdEditConf.setGeometry(QRect(120, 210, 150, 25));
    pswdEditConf.setEchoMode(QLineEdit::Password);

    wordNumberLabel.setParent(this);
    wordNumberLabel.setGeometry(QRect(30, 260, 80, 25));
    wordNumberLabel.setText("选择词汇量");
    wordNumberBox.setParent(this);
    wordNumberBox.setGeometry(QRect(130, 260, 130, 25));
    QStringList str;
    str << "2000以下" << "2000-3000" << "3000-4000" << "4000-5000" << "5000-6000" << "6000-8000" <<"8000-10000" << "10000-15000" << "15000以上";
    wordNumberBox.addItems(str);

    registerButton.setParent(this);
    registerButton.setGeometry(QRect(50, 310, 120, 25));
    registerButton.setText("确认注册");

    backButton.setParent(this);
    backButton.setGeometry(QRect(200, 310, 80, 25));
    backButton.setText("返回登陆");

}
