#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "judger.h"
#include <QMainWindow>
#include<QLabel>
#include<QString>
#include<QVector>
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

private:
    Ui::myMainWindow *ui;
};
#endif // MYMAINWINDOW_H
