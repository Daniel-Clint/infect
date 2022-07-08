#pragma once

#include <QWidget>
#include "CentralWidget_patch.h"

#include <QMouseEvent>
#include<QPaintEvent>
#include<Qpainter>

class CentralWidget : public QWidget
{
	Q_OBJECT

public:
	CentralWidget(QWidget *parent = nullptr);
	~CentralWidget();


protected:
	//void mousePressEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;

private slots:
	void on_pushButton_toggled(bool checked);
	void on_clearButton_clicked();
	void on_spinBox_valueChanged(int value);
	void on_spinBox_2_valueChanged(int value);

private:
	Ui::CentralWidgetClass ui;
};
