#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NewDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void exchangeValue();

private slots:
    void on_pushButton_clicked();
    void exit();
    void showSth();
    void lineEditGetTem(QString str);
    void sendText();

private:
    Ui::MainWindow *ui;


signals:
    sendToDialog(QString);
};


#endif // MAINWINDOW_H
