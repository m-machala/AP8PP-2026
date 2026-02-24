#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_triggered()
{
    SpritePtr spr = SpritePtr(new sprite(this));
    sprites.append(spr);

    connect(this, &MainWindow::draw, spr.get(), &sprite::draw);
}

void MainWindow::on_actionRemove_triggered()
{
    sprites.removeFirst();
    update();
}

void MainWindow::on_actionRemove_all_triggered()
{
    sprites.clear();
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(QColor(Qt::gray)));

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(Qt::white)));

    emit draw(painter);
}
