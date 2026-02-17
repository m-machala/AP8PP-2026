#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTimer();
    void onTimer2();

    void on_button1_pressed();
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;

    QTimer *m_timer;
    QTimer *m_timer2;

    int m_counter;
    int m_counter2;

};
#endif // MAINWINDOW_H
