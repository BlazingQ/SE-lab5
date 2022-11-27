#include "mywidget.h"
#include "ui_mywidget.h"
#include<qpushbutton.h>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    QPushButton* btn = new QPushButton;
    btn->setParent(this);
    btn->setText("first button");

    QPushButton* btn2 = new QPushButton("button 2", this);
    btn2->move(100,100);
    resize(600, 400); 
    
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
}



myWidget::~myWidget()
{
    delete ui;
}

