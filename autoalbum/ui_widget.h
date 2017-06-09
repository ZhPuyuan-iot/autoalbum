/********************************************************************************
** Form generated from reading ui file 'widget.ui'
**
** Created: Tue May 23 19:12:12 2017
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_play;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(688, 396);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_play = new QPushButton(Widget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(450, 340, 91, 41));
        pushButton_play->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 14pt \"URW Palladio L\";\n"
"border:2px groove gray;\n"
"border-radius:10px 10px;\n"
"padding:2px 4px;"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 120, 361, 131));
        label->setStyleSheet(QString::fromUtf8("margin:o auto;\n"
"color: rgb(255, 255, 255);\n"
"font: italic 18pt \"URW Bookman L\";"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 340, 92, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 14pt \"URW Palladio L\";\n"
"border:2px groove gray;\n"
"border-radius:10px 10px;\n"
"padding:2px 4px;"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 340, 92, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 14pt \"URW Palladio L\";\n"
"border:2px groove gray;\n"
"border-radius:10px 10px;\n"
"padding:2px 4px;"));
        label->raise();
        pushButton_play->raise();
        pushButton_2->raise();
        pushButton->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        pushButton_play->setText(QApplication::translate("Widget", "play", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "NOTHING TO SHOW", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "next", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "previous", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Widget);
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
