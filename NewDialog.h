#ifndef NEWDIALOG_H
#define NEWDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
    class NewDialog;
}


class NewDialog : public QDialog
{
    Q_OBJECT
public:
    NewDialog(QWidget* parent=0);
    ~NewDialog();

private slots:
    void doSth();
    void showLabel(QString str);

private:
    Ui::NewDialog *ui;
    QLabel *label=new QLabel("dialog");
    QLineEdit *lineEdit = new QLineEdit;

signals:
    sendToMain(QString);
};

#endif // NEWDIALOG_H
