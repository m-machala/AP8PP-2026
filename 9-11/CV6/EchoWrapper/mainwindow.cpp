#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&echo, &QProcess::readyReadStandardOutput, this, &MainWindow::readyToRead);
    connect(&echo, &QProcess::stateChanged, this, &MainWindow::statusChanged);
    connect(&echo, &QProcess::errorOccurred, this, &MainWindow::processErrorOccured);
    connect(&echo, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &MainWindow::processFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    switch(echo.state()) {
    case QProcess::NotRunning:
        echo.setWorkingDirectory(QCoreApplication::applicationDirPath());
        echo.start("./Echo.exe");
        break;

    case QProcess::Running:
    case QProcess::Starting:
        echo.kill();
        break;

    default:
        break;
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    echo.write(QString(ui->lineEdit->text() + "\n").toLocal8Bit());
}

void MainWindow::readyToRead()
{
    ui->plainTextEdit->appendPlainText(echo.readAllStandardOutput());
}

void MainWindow::statusChanged(QProcess::ProcessState state)
{
    switch(state) {
    case QProcess::NotRunning:
        ui->pushButton->setText("Start Echo");
        break;

    case QProcess::Running:
    case QProcess::Starting:
        ui->pushButton->setText("Close Echo");
        break;

    default:
        break;
    }
}

void MainWindow::processFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(ui->actionTrack_errors->isChecked()) {
        switch(exitStatus) {
        case QProcess::CrashExit:
            QMessageBox::critical(this, QString("Echo Wrapper"), QString("Echo has crashed."));
            break;


        case QProcess::NormalExit:
            QMessageBox::warning(this, QString("Echo Wrapper"), QString("Echo process has exited with return value %1.").arg(exitCode));
            break;
        }
    }
}

void MainWindow::processErrorOccured(QProcess::ProcessError error)
{
    if(ui->actionTrack_errors->isChecked()) {
        QMessageBox::critical(this, QString("Echo Wrapper"), QString("Error %1 has occured.").arg(error));
    }
}

