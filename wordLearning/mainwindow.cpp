#include "mainwindow.h"
#include <QToolButton>
#include <QStyle>
#include <QTimer>
mainWindow::mainWindow()
{
    this->resize(440, 280);
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

    nickNameLabel.setParent(this);      //昵称处
    nickNameLabel.setGeometry(QRect(30, 10, 50, 25));
    nickNameLabel.setText("昵称");
    tipLabel.setParent(this);       //建议框
    tipLabel.setGeometry(QRect(100, 10, 220, 25));
    tipLabel.setText("您今天背诵了XX个单词");
    time.setParent(this);
    time.setGeometry(320, 10, 60, 25);
    QTimer *timer1 = new QTimer(this);
    timer1->start(1000);
    connect(timer1, SIGNAL(timeout()), this, SLOT(tim_slot()));
    inquireEdit.setParent(this);    //查询区
    inquireEdit.setGeometry(QRect(40, 60, 280, 30));
    inquireEdit.setText("请输入要查询的文本");
    inquireEdit.setFocus();
    search.setParent(this);         //搜索按钮
    search.setGeometry(QRect(330, 60, 100, 30));
    search.setText("开始查询");
    dayEnglish_1.setParent(this);   //每日英语
    dayEnglish_1.setGeometry(QRect(0, 100, 160, 220));
    dayEnglish_1.setWordWrap(true);
    dayEnglish_1.setAlignment(Qt::AlignTop);
    dayEnglish_1.setText("每\n日\n英\n语\n区");
    dayEnglish_1.setStyleSheet("background-color:lightgreen");
    wordEnglish_2.setParent(this);  //单词专区
    wordEnglish_2.setGeometry(QRect(160, 100,160, 220));
    wordEnglish_2.setWordWrap(true);
    wordEnglish_2.setAlignment(Qt::AlignTop);
    wordEnglish_2.setText("英\n语\n单\n词\n区");
    wordEnglish_2.setStyleSheet("background-color:lightyellow");
    testEnglish_3.setParent(this);  //测试专区
    testEnglish_3.setGeometry(QRect(320, 100, 160, 220));
    testEnglish_3.setWordWrap(true);
    testEnglish_3.setAlignment(Qt::AlignTop);
    testEnglish_3.setStyleSheet("background-color:purple");
    testEnglish_3.setText("英\n语\n测\n试\n区");
}

void mainWindow::tim_slot()
{
    QTime qtimeObj = QTime::currentTime();
    QString strTime = qtimeObj.toString("h:m");
    time.setText(strTime);
}

void mainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void mainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void mainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}


