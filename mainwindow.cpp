#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ct1 = new QVBoxLayout;
    ct2 = new QVBoxLayout;
    ct3 = new QHBoxLayout;

    QLabel *mlb1 = new QLabel;
    mlb1->setObjectName("mytarget");
    QString picPath = QDir::currentPath() + "/" + "pic" + "/" + "csc.png";
    QPixmap *m_pixmap = new QPixmap(picPath);
    mlb1->setPixmap(*m_pixmap);

    ct1->addWidget(mlb1);

    QPushButton *mbtn1 = new QPushButton;
    mbtn1->setText("Test");
    connect(mbtn1,&QPushButton::clicked,this,&MainWindow::test);

    ct2->addWidget(mbtn1);

    ct3->addLayout(ct1,9);
    ct3->addLayout(ct2,1);

    QWidget *m_wd = new QWidget;
    m_wd->setLayout(ct3);

    m_animation = new QPropertyAnimation;
    m_animation->setTargetObject(mlb1);
    m_animation->setEasingCurve(QEasingCurve::Linear);

    setCentralWidget(m_wd);
}

MainWindow::~MainWindow()
{
}

void MainWindow::test()
{

    QPoint mp(this->findChild<QLabel *>("mytarget")->pos());
    int x0 = mp.x();
    int y0 = mp.y();

    m_animation->setPropertyName("pos");    //指定动画属性名
    m_animation->setDuration(3000);
    m_animation->setLoopCount(-1);
    m_animation->setStartValue(mp);  //设置动画起始位置在label控件当前的pos
    m_animation->setEndValue(QPoint(x0+1200,y0)); //设置动画结束位置
    m_animation->start();   //启动动画
}
