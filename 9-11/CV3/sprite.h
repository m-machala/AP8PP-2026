#ifndef SPRITE_H
#define SPRITE_H

#include <QTimer>
#include <QWidget>
#include <QPainter>

class sprite : public QTimer
{
    Q_OBJECT
public:
    sprite(QWidget* p);

public slots:
    void draw(QPainter &painter);

protected:
    QWidget* parent = NULL;
    int x = 0;
    int y = 0;
    float kx = 1;
    float ky = 1;

    virtual void timerEvent(QTimerEvent *);
};

typedef std::shared_ptr<sprite> SpritePtr;

#endif // SPRITE_H
