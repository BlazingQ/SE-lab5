/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *compare;
    QPushButton *btnsame;
    QPushButton *btndiff;
    QMenuBar *menubar;
    QMenu *menumain_win;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QString::fromUtf8("myMainWindow"));
        myMainWindow->resize(800, 600);
        centralwidget = new QWidget(myMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 40, 661, 451));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));

        horizontalLayout->addWidget(listView);

        listView_2 = new QListView(widget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        horizontalLayout->addWidget(listView_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        compare = new QPushButton(widget);
        compare->setObjectName(QString::fromUtf8("compare"));

        horizontalLayout_3->addWidget(compare);

        btnsame = new QPushButton(widget);
        btnsame->setObjectName(QString::fromUtf8("btnsame"));

        horizontalLayout_3->addWidget(btnsame);

        btndiff = new QPushButton(widget);
        btndiff->setObjectName(QString::fromUtf8("btndiff"));

        horizontalLayout_3->addWidget(btndiff);


        verticalLayout->addLayout(horizontalLayout_3);

        myMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menumain_win = new QMenu(menubar);
        menumain_win->setObjectName(QString::fromUtf8("menumain_win"));
        myMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(myMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myMainWindow->setStatusBar(statusbar);

        menubar->addAction(menumain_win->menuAction());

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QApplication::translate("myMainWindow", "myMainWindow", nullptr));
        label->setText(QApplication::translate("myMainWindow", "filename1", nullptr));
        label_2->setText(QApplication::translate("myMainWindow", "filename2", nullptr));
        compare->setText(QApplication::translate("myMainWindow", "compare", nullptr));
        btnsame->setText(QApplication::translate("myMainWindow", "same", nullptr));
        btndiff->setText(QApplication::translate("myMainWindow", "different", nullptr));
        menumain_win->setTitle(QApplication::translate("myMainWindow", "main win", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
