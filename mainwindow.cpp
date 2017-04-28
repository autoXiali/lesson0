#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenu"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *menu=new QMenu("menu");
    QAction *about=menu->addAction("about");
    QAction *exit=menu->addAction("exit");
    ui->menuBar->addMenu(menu);
    ui->menuBar->setCornerWidget(NULL,Qt::TopLeftCorner);
    ui->menuBar->setDefaultUp(true);
    connect(about,SIGNAL(triggered()),this,SLOT(showSth()));
    connect(exit,SIGNAL(triggered()),this,SLOT(exit()));
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
    ui->label->setText(ui->textEdit->toPlainText());

}

void MainWindow::showSth(){
    QMessageBox::about(NULL,"about us","all right reserved");
}
void MainWindow::exit(){
    QApplication* app;
    app->exit(0);
}
