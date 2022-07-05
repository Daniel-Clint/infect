#pragma once
#ifndef UI_CENTRALWIDGET_H
#define UI_CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "rocks.h"

QT_BEGIN_NAMESPACE

class Ui_CentralWidgetClass
{
public:
    QGridLayout* gridLayout;
    QGroupBox* groupBox;
    QGridLayout* gridLayout_2;
    QSpinBox* spinBox_2;
    QLabel* label_2;
    QLabel* label;
    QSpinBox* spinBox;
    QPushButton* pushButton;
    QPushButton* clearButton;
    QWidget* widget;

    void setupUi(QWidget* CentralWidgetClass)
    {
        if (CentralWidgetClass->objectName().isEmpty())
            CentralWidgetClass->setObjectName(QString::fromUtf8("CentralWidgetClass"));
        CentralWidgetClass->resize(600, 400);
        CentralWidgetClass->setAutoFillBackground(false);
        gridLayout = new QGridLayout(CentralWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(CentralWidgetClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
            "color: rgb(255, 255, 0);\n"
            "}\n"
            "QLabel{\n"
            "color: rgb(255, 255, 0);\n"
            "}"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(1);

        gridLayout_2->addWidget(spinBox_2, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);

        gridLayout_2->addWidget(pushButton, 0, 4, 1, 1);

        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout_2->addWidget(clearButton, 0, 5, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        widget = new rocks(CentralWidgetClass);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_2->setBuddy(spinBox_2);
        label->setBuddy(spinBox);
#endif // QT_CONFIG(shortcut)

        retranslateUi(CentralWidgetClass);

        QMetaObject::connectSlotsByName(CentralWidgetClass);
    } // setupUi

    void retranslateUi(QWidget* CentralWidgetClass)
    {
        CentralWidgetClass->setWindowTitle(QCoreApplication::translate("CentralWidgetClass", "CentralWidget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CentralWidgetClass", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("CentralWidgetClass", "\345\210\227\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("CentralWidgetClass", "\350\241\214\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("CentralWidgetClass", "\344\274\240\346\237\223", nullptr));
        clearButton->setText(QCoreApplication::translate("CentralWidgetClass", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CentralWidgetClass : public Ui_CentralWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWIDGET_H
