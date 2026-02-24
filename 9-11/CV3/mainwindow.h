#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "sprite.h"

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

signals:
    void draw(QPainter &painter);

private slots:
    void on_actionAdd_triggered();
    void on_actionRemove_triggered();
    void on_actionRemove_all_triggered();

private:
    Ui::MainWindow *ui;
    QList<SpritePtr> sprites;

protected:
    virtual void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
