#include "rgb.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

RGB::RGB(QWidget *parent) : QWidget(parent)
{
    r = 0;
    g = 0;
    b= 0;
    a= 255;
}
void RGB::paintEvent(QPaintEvent *event){
        QPainter painter(this);
        QBrush brush;
        QPen pen;

        brush.setColor(QColor(r,g,b,a));
        brush.setStyle(Qt::SolidPattern);
        pen.setColor(QColor(0,0,0));
        pen.setWidth(2);

        painter.setBrush(brush);
        painter.setPen(pen);

        //painter.drawRect(0,0,width(),height());
        painter.drawEllipse(25,2,20,20);

}

void RGB::setR(int _r){
    r = _r;
    repaint();
}

void RGB::setG(int _g){
    g = _g;
    repaint();
}

void RGB::setB(int _b){
    b = _b;
    repaint();
}

void RGB::setA(int _a)
{
    a = _a;
    repaint();
}
