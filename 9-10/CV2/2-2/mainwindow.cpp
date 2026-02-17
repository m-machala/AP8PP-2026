#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_counter = 0;
    ui->counter1->setText(QString::number(m_counter));
    ui->button1->setText("Start");

    m_counter = 0;
    ui->counter2->setText(QString::number(m_counter2));
    ui->pushButton->setText("Start");

    m_timer = new QTimer(this);
    m_timer2 = new QTimer(this);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::onTimer);
    connect(m_timer2, &QTimer::timeout, this, &MainWindow::onTimer2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimer() {
    m_counter++;
    ui->counter1->setText(QString::number(m_counter));
}

void MainWindow::onTimer2() {
    m_counter2++;
    ui->counter2->setText(QString::number(m_counter2));
}

void MainWindow::on_button1_pressed()
{
    if(!m_timer->isActive()) {
        m_timer->start(1000);
        ui->button1->setText("Pause");
    }
    else {
        m_timer->stop();
        ui->button1->setText("Start");
    }
    qDebug() << "button pressed";
}


void MainWindow::on_pushButton_pressed()
{
    if(!m_timer2->isActive()) {
        m_timer2->start(0);
        ui->pushButton->setText("Pause");
    }
    else {
        m_timer2->stop();
        ui->pushButton->setText("Start");
    }
    qDebug() << "button pressed";

    /*int testCounter = 0;
    while(testCounter < 1000000) {
        testCounter++;
    }*/

    /*while(true) {
        m_counter2++;
        ui->counter2->setText(QString::number(m_counter2));
    }*/
}

