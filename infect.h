#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_infect.h"

class infect : public QMainWindow
{
    Q_OBJECT
public:
    infect(int ,int,QWidget* parent= Q_NULLPTR);
    //~infect();

private:
    Ui::infectClass ui;
    
};
