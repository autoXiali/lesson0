#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenu"
#include "QMessageBox"
#include "NewDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *menu=new QMenu("menu");
    QAction *about=menu->addAction("about");
    QAction *exit=menu->addAction("exit");
    ui->menuBar->addMenu(menu);
    ui->menuBar->setDefaultUp(true);
    connect(about,SIGNAL(triggered()),this,SLOT(showSth()));
    connect(exit,SIGNAL(triggered()),this,SLOT(exit()));

    NewDialog *myDialog = new NewDialog();
    QObject::connect(ui->pushButton,SIGNAL(clicked()), myDialog, SLOT(show()));
    QObject::connect(myDialog,SIGNAL(sendString(QString)), this, SLOT(lineEditGetTem(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    exchangeValue();
}

//void MainWindow::exchangeValue(){
//    ui->label->setText(ui->textEdit->toPlainText());
//}

void MainWindow::showSth(){
    QMessageBox::about(NULL,"about us","all right reserved");
}
void MainWindow::exit(){
    QApplication* app;
    app->exit(0);
}
void MainWindow::lineEditGetTem(QString str){
    ui->label->setText(str);
}
