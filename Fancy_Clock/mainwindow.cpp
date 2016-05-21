#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include<QSettings>
#include "preference.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)  //constructor
{
    ui->setupUi(this);


    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|windowFlags());

    connect(this,&MainWindow::customContextMenuRequested,this,&MainWindow::showContextMenu);


    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::updateTime);
    timer->start(1000);

    updateTime();

    QSettings sts;
    restoreGeometry(sts.value("MainGeometry").toByteArray());
    restoreState(sts.value("MainState").toByteArray());
}

MainWindow::~MainWindow()  //destructor
{
    delete ui;
}

void MainWindow::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeText = currentTime.toString("hh:mm");
    if(currentTime.second()%2==0)
    {
        currentTimeText[2]='\0';
    }
    ui->lcdNumber->display(currentTimeText);
}

void MainWindow::showContextMenu(const QPoint &pos)  //slot
{
    QMenu contextMenu;
    contextMenu.addAction(QString("Preference"),this,SLOT(showPreference()));
    contextMenu.addAction(QString("Exit"),this,SLOT(close()));

    contextMenu.exec(mapToGlobal(pos)); //mapping to global position
}

void MainWindow::mouseReleaseEvent(QMouseEvent*e)
{
    if(e->button()==Qt::RightButton)
    {
        emit customContextMenuRequested(e->pos()); //signal
    }
    else
    {
        QMainWindow::mouseReleaseEvent(e);
    }
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    m_mousePos = e->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPos()-m_mousePos);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QSettings sts;
    sts.setValue("MainGeometry",saveGeometry());
    sts.setValue("MainState",saveState());
    e->accept();

}

void MainWindow::setColour()
{
    QSettings sts;
    int i = sts.value("Colour").toInt();

    QPalette c;
    switch(i){
    case 0:
        c.setColor(QPalette::Foreground,Qt::black);
        break;
    case 1:
        c.setColor(QPalette::Foreground,Qt::white);
        break;
    case 2:
        c.setColor(QPalette::Foreground,Qt::green);
        break;
    case 3:
        c.setColor(QPalette::Foreground,Qt::red);
        break;
    }
    ui->lcdNumber->setPalette(c);
    this->update();
}

void MainWindow::showPreference()
{
    Preference *pre = new Preference(this);
    pre->exec();
    setColour();
}


