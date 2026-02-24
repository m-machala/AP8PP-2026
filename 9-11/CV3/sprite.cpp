#include "sprite.h"

#define SPRITE_SIZE (50)

sprite::sprite(QWidget* p) {
    parent = p;

    QRect rect = parent->rect();
    x = rand() % rect.width();
    y = rand() % rect.height();

    kx = rand() % 10;
    ky = rand() % 10;

    start(10);
}

void sprite::draw(QPainter &painter)
{
    painter.drawEllipse(x, y, SPRITE_SIZE, SPRITE_SIZE);
}

void sprite::timerEvent(QTimerEvent *)
{
    QRect rect = parent->rect();

    if (x < 0 || x > rect.width() - SPRITE_SIZE) {
        kx *= -1;
    }

    if (y < 0 || y > rect.height() - SPRITE_SIZE) {
        ky *= -1;
    }

    x += kx;
    y += ky;

    parent->update();
}
