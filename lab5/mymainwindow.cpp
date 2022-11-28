#include "mymainwindow.h"
#include "ui_mymainwindow.h"

void changelabel(QLabel* label, QString str)
{
    label->setText(str);
}

/*void gothrough()
{
    vector<string, string> filepairs;
    ifstream ifs("../lab5/output/", ios::in);
}*/

myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
{
    ui->setupUi(this);

}

myMainWindow::~myMainWindow()
{
    delete ui;
}

