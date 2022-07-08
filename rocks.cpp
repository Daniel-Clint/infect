#include "rocks.h"
#include"CentralWidget_patch.h"
#include <QPainter>
#include <QtMath>
#include<QMouseEvent>
#include<time.h>


rocks::rocks(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    states.insert(0, X * Y, false);
    connect(timer, &QTimer::timeout, this, &rocks::on_clock);
    srand(time(NULL));
}

rocks::~rocks()
{
    delete timer;
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
    
    //线
    QPen pen;
    pen.setWidth(3);//宽
    //pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(QPen(QColor(119, 33, 68, 80)));

    //画笔
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
    next.clear();
    next.insert(0, X * Y, false);

    update();
}

void rocks::setY(int y)
{
    Y = y;
    states.clear();
    states.insert(0, X * Y, false);
    next.clear();
    next.insert(0, X * Y, false);

    update();
}

void rocks::rocks_clear()
{
    states.clear();
    states.insert(0, X * Y, false);
    next.clear();
    next.insert(0, X * Y, false);
    update();
}

void rocks::mousePressEvent(QMouseEvent* event)
{
    if (timer->isActive())return;
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

void rocks::start_infecting()
{
    timer->start(50);
}

void rocks::pause_infecting()
{
    timer->stop();
}

void rocks::on_clock()
{
    int carrier=0;
    int up, down, left, right;
    
    for (int i = 0; i < X * Y; i++)
    {
        next[i] = false;
    }

    for (int i = 0; i < X * Y; i++)//获取下一次变化
    {
        carrier = 0;
        if (i % X == i)//最上面一排
            up = X * (Y - 1) + i;
        else
            up = i - X;
        if (i % X == 0)//最左边一列
            left = i + X - 1;
        else
            left = i - 1;
        if (i % X == (X - 1))//最右边一列
            right = i - X + 1;
        else
            right = i + 1;
        if (i / X == (Y - 1))//最下面一排
            down = i - X * (Y - 1);
        else
            down = i + X;

        if (states[up])
            carrier++;
        if (states[left])
            carrier++;
        if (states[right])
            carrier++;
        if (states[down])
            carrier++;

        for (int j = 0; j < carrier; j++)
        {
            if (rand() % 20==1)
            {
                next[i] = true;
                break;
            }
        }

        if (states[i])next[i] = true;
    }

    states = next;
    update();
}
