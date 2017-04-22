#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exchangeValue();
}

void MainWindow::exchangeValue(){
    QString labelValue = getLabelValue();
    ui->textEdit->setText(labelValue);
}

QString MainWindow::getLabelValue(){
    QString labelValue = ui->label->text();
    return labelValue;
}
