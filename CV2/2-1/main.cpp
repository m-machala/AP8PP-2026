#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

void helloTimer() {
    qDebug() << "Hello from timer 1";
}

void helloTwo() {
    qDebug() << "Hello from timer 2";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &helloTimer);
    timer.start(1000);

    QTimer timer2;
    QObject::connect(&timer2, &QTimer::timeout, &helloTwo);
    timer2.start(500);


    return a.exec();
}
