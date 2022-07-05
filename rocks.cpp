#include "rocks.h"
#include"CentralWidget_patch.h"
#include <QPainter>
#include <QtMath>
#include<QMouseEvent>
rocks::rocks(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    states.insert(0, X * Y, false);
}

rocks::~rocks()
{
}

void rocks::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    in_rect(painter);
}

void rocks::in_rect(QPainter& painter)
{
    int W = this->width();
    int H = this->height();
    int PE = 0.9 * qMin(W / X, H / Y);
    PE = qMin(100, PE);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    
    //Ïß
    QPen pen;
    pen.setWidth(3);//¿í
    //pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(QPen(QColor(119, 33, 68, 80)));

    //»­±Ê
    QBrush brush;
    //brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    
    int px = W / 2 - X * PE / 2;
    int py = H / 2 - Y * PE / 2;

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            QRect rect(px + i * PE, py + j * PE, PE, PE);

            if(!states[j * X + i])
                painter.setBrush(QBrush(QColor(2, 11, 16, 80)));
            else
                painter.setBrush(QBrush(QColor(255, 0, 0, 80)));

            painter.drawRect(rect);
        }
    }
}

void rocks::setX(int x)
{
    X = x;
    states.clear();
    states.insert(0, X * Y, false);
    update();
}

void rocks::setY(int y)
{
    Y = y;
    states.clear();
    states.insert(0, X * Y, false);
    update();
}

void rocks::mousePressEvent(QMouseEvent* event)
{
    int W = this->width();
    int H = this->height();
    int PE = 0.9 * qMin(W / X, H / Y);
    PE = qMin(100, PE);

    int px = W / 2 - X * PE / 2;
    int py = H / 2 - Y * PE / 2;

    int item_x = qFloor((event->pos().x() - px) / (double)PE);
    int item_y = qFloor((event->pos().y() - py) / (double)PE);

    if ((item_x >= X || item_x < 0 )|| (item_y >= Y || item_y < 0))
    {
        return;
    }
    else 
    {
        int posit = item_y * X + item_x;

        if (posit >= 0 && posit < states.size()) 
        {
            states[posit] = !states[posit];
        }
        update();
    }
    
}