#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "judger.h"
#include <QMainWindow>
#include<QLabel>
#include<QString>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class myMainWindow; }
QT_END_NAMESPACE

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = nullptr);
    ~myMainWindow();
    void changelabel(QLabel* label, QString str);
    void gothrough();

private:
    Ui::myMainWindow *ui;
};
#endif // MYMAINWINDOW_H
