#ifndef NEWDIALOG_H
#define NEWDIALOG_H
#include <QDialog>

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
    void findClicked();
    void close();

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
