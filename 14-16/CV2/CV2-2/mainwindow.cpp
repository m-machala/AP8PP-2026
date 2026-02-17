#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_counter1 = 0;
    m_timer1 = new QTimer(this);

    ui->counter1->setText(QString::number(m_counter1));
    ui->button1->setText("Start");

    connect(m_timer1, &QTimer::timeout, this, &MainWindow::onTimer1);



    m_counter2 = 0;
    m_timer2 = new QTimer(this);

    ui->counter2->setText(QString::number(m_counter2));
    ui->button2->setText("Start");

    connect(m_timer2, &QTimer::timeout, this, &MainWindow::onTimer2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_pressed()
{
    if(!m_timer1->isActive()) {
        m_timer1->start(1000);
        ui->button1->setText("Stop");
    }
    else {
        m_timer1->stop();
        ui->button1->setText("Start");
    }
}

void MainWindow::onTimer1()
{
    m_counter1++;
    ui->counter1->setText(QString::number(m_counter1));
}


void MainWindow::on_button2_pressed()
{
    if(!m_timer2->isActive()) {
        m_timer2->start(0);
        ui->button2->setText("Stop");
    }
    else {
        m_timer2->stop();
        ui->button2->setText("Start");
    }

    /*while(true) {
        m_counter2++;
        ui->counter2->setText(QString::number(m_counter2));
    }*/

    /*for(int i = 0; i < 100000; i++) {
        for(int j = 0; j < 100000; j++) {
            m_counter2++;
        }
    }
    ui->counter2->setText(QString::number(m_counter2));*/
}

void MainWindow::onTimer2()
{
    m_counter2++;
    ui->counter2->setText(QString::number(m_counter2));
}


