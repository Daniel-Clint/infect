#pragma once

#include <QWidget>
#include "ui_rocks.h"
#include <QVector>

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
	
private:
	int X=1, Y=1;
	QVector<bool> states;
	
	Ui::rocksClass ui;
};
