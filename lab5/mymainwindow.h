#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "judger.h"
#include <QMainWindow>
#include<QLabel>
#include<QString>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class myMainWindow; }
QT_END_NAMESPACE

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = nullptr);
    ~myMainWindow();
    void gothrough();
    void getnext();
    void writeback();

private slots:
    void on_btnsame_clicked();

    void on_btndiff_clicked();

    void on_compare_clicked();

private:
    Ui::myMainWindow *ui;
    QColor m_txtBox1Color, m_txtBox2Color;
    vector<string> filepairs;
    vector<string> equalpairs;
    vector<string> inequalpairs;
    Judger tmpjudger;
};
#endif // MYMAINWINDOW_H
