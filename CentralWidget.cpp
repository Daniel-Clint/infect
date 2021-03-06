#include "CentralWidget.h"
#include "rocks.h"
#include <QMessageBox>
#include<time.h>

CentralWidget::CentralWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CentralWidget::~CentralWidget()
{}

void CentralWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(this->geometry(), QColor(0, 0, 0, 100));
}

void CentralWidget::on_pushButton_toggled(bool checked)
{
    ui.pushButton->setText(checked ? "停止" : "传染");
    ui.clearButton->setEnabled(!checked);
    ui.spinBox->setEnabled(!checked);
    ui.spinBox_2->setEnabled(!checked);
    if (checked) 
    {
        //运行状态
        ((rocks*)(ui.widget))->start_infecting();
    }
    else 
    {
        //暂停状态
        ((rocks*)(ui.widget))->pause_infecting();
    }
}

void CentralWidget::on_clearButton_clicked()
{
    ((rocks*)(ui.widget))->rocks_clear();
}

void CentralWidget::on_spinBox_valueChanged(int value)
{
    ((rocks*)(ui.widget))->setX(value);
}

void CentralWidget::on_spinBox_2_valueChanged(int value)
{
    ((rocks*)(ui.widget))->setY(value);
}
