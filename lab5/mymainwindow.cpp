#include "mymainwindow.h"
#include "ui_mymainwindow.h"
vector<string> filepairs;
vector<string> equalpairs;
vector<string> inequalpairs;
Judger tmpjudger;

myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    gothrough();
}

myMainWindow::~myMainWindow()
{
    delete ui;
}

void myMainWindow::getnext()
{
    string temp;
    string file1, file2;
    string filetext1, filetext2;
    int commapos = -2;
    if(!filepairs.empty())
    {
        temp = filepairs.back();
        filepairs.pop_back();
        commapos = temp.find(',');
        file1 = temp.substr(0, commapos);
        file2 = temp.substr(commapos + 1, temp.size());
        ui->label->setText(QString::fromStdString(file1));
        ui->label_2->setText(QString::fromStdString(file2));
        filetext1 = tmpjudger.ftos(file1);
        filetext2 = tmpjudger.ftos(file2);
        ui->textEdit->setText(QString::fromStdString(filetext1));
        ui->textEdit_2->setText(QString::fromStdString(filetext2));
    }
    else
    {
        QMessageBox::information(this," ","You have done all!!");
        writeback();
        ui->label->setText("");
        ui->label_2->setText("");
        ui->textEdit->setText("");
        ui->textEdit_2->setText("");
    }
}

void myMainWindow::gothrough()
{
    ifstream ifs("../lab5/output/equal.csv", ios::in);
    if(!ifs) 
    {
        cout<<"ERROR OPEN ../lab5/output/inequal.csv\n";
        return;
    }
    string temp;
    while(!ifs.eof())
    {
        ifs>>temp;
        if(temp != "file1,file2")
            filepairs.push_back(temp);
    }
    filepairs.pop_back();
    getnext();
}

void myMainWindow::writeback()
{
    ofstream ofs("../lab5/output/equal.csv", ios::out);
    if(!ofs) 
    {
        cout<<"ERROR OPEN ../lab5/output/equal.csv\n";
        return;
    }
    for(int i = 0; i != equalpairs.size(); ++i)
    {
        ofs<<equalpairs[i]<<"\n";
    }
    ofs.close();
    ofs.open("../lab5/output/inequal.csv", ios::out);
    if(!ofs) 
    {
        cout<<"ERROR OPEN ../lab5/output/inequal.csv\n";
        return;
    }
    for(int i = 0; i != inequalpairs.size(); ++i)
    {
        ofs<<inequalpairs[i]<<"\n";
    }
    ofs.close();
}

void myMainWindow::on_btnsame_clicked()
{
    string file1, file2;
    file1 = ui->label->text().toStdString();
    file2 = ui->label_2->text().toStdString();
    if(file1.compare("") != 0)
        equalpairs.push_back(file1+","+file2);
    getnext();
}

void myMainWindow::on_btndiff_clicked()
{
    string file1, file2;
    file1 = ui->label->text().toStdString();
    file2 = ui->label_2->text().toStdString();
    if(file1.compare("") != 0)
        inequalpairs.push_back(file1+","+file2);
    getnext();
}
