#include "mymainwindow.h"
#include "ui_mymainwindow.h"

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
        ui->textEdit1->setText(QString::fromStdString(filetext1));
        ui->textEdit2->setText(QString::fromStdString(filetext2));
    }
    else
    {
        QMessageBox::information(this," ","You have done all!!");
        writeback();
        ui->label->setText("");
        ui->label_2->setText("");
        ui->textEdit1->setText("");
        ui->textEdit2->setText("");
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
    filepairs.pop_back();//get last line two times
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

void myMainWindow::on_compare_clicked()
{
    QByteArray text1 = (ui->textEdit1->toPlainText()).toUtf8();
    QByteArray text2 = (ui->textEdit2->toPlainText()).toUtf8();
    QList<int> differenceList;
    int larger = 0;
    bool oneIsBig = false;
    bool twoIsBig = false;
    if(text1.length() > text2.length())
    {
        twoIsBig = false;
        oneIsBig = true;
        larger = text1.length();
    }

    if(text1.length() < text2.length())
    {
        twoIsBig = true;
        oneIsBig = false;
        larger = text2.length();
    }

    if(text1.length() == text2.length())
    {
        twoIsBig = false;
        oneIsBig = false;
        larger = text1.length();
    }

    if(oneIsBig == true)
    {
        for(int i = text2.length(); i < text1.length();i++)
        {
            text2.append(' ');
        }
    }
    if(twoIsBig == true)
    {
        for(int i = text1.length(); i < text2.length();i++)
        {
            text1.append(' ');
        }
    }

    ui->textEdit1->setText(text1);
    ui->textEdit2->setText(text2);

    for(int i = 0; i < larger; i++)
    {
        if(text1[i] != text2[i])
        {
            differenceList.append(i);
        }
    }

    QTextCursor cursorText1(ui->textEdit1->document());
    QTextCursor cursorText2(ui->textEdit2->document());
    m_txtBox1Color.setRgb(153,255,255);
    m_txtBox2Color.setRgb(255,255,153);

    QTextCharFormat backgroundClear, background1, background2;
    backgroundClear.clearBackground();
    background1.setBackground(m_txtBox1Color);
    background2.setBackground(m_txtBox2Color);

    cursorText1.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText1.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText1.setCharFormat(backgroundClear);
    cursorText2.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText2.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText2.setCharFormat(backgroundClear);

    for(int i = 0;i < differenceList.size();i++)
    {
        cursorText1.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText1.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText1.setCharFormat(background1);

        cursorText2.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText2.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText2.setCharFormat(background2);
    }
}
