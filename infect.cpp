#include "infect.h"
#include <QIcon>

infect::infect(int x,int y,QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
}







//void infect::mousePressEvent(QMouseEvent* event)
//{
//    QString button;
//    if (event->button() == Qt::MouseButton::LeftButton) {
//        button = "左键";
//    }
//    else if (event->button() == Qt::MouseButton::RightButton) {
//        button = "右键";
//    }
//    else if (event->button() == Qt::MouseButton::MiddleButton) {
//        button = "滚轮";
//    }
//    QMessageBox::information(this, "test",
//        QString::asprintf("鼠标%s点击，位置(%d,%d)", button.toStdString().c_str(), event->pos().x(), event->pos().y()),
//        QMessageBox::StandardButton::Ok);
//}
