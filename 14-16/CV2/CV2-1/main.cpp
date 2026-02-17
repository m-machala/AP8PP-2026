#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

void hello1() {
    qDebug() << "Hello from timer 1";
}

void hello2() {
    qDebug() << "Hello from timer 2";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer1;
    QObject::connect(&timer1, &QTimer::timeout, &hello1);
    timer1.start(1000);

    QTimer timer2;
    QObject::connect(&timer2, &QTimer::timeout, &hello2);
    timer2.start(500);


    return a.exec();
}
