#pragma once

#include <QWidget>
#include "ui_rocks.h"
#include <QVector>
#include<Qtimer.h>

class rocks : public QWidget
{
	Q_OBJECT

public:
	rocks(QWidget *parent = nullptr);
	~rocks();
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event);
	void in_rect(QPainter&);
	void setX(int x);
	void setY(int y);
	void rocks_clear();
	void start_infecting();
	void pause_infecting();
	
private slots:
	void on_clock();

private:
	int X=1, Y=1;
	QVector<bool> states;
	QVector<bool> next;
	QTimer* timer = new QTimer(this);
	Ui::rocksClass ui;
};
