#include "NewDialog.h"
#include "mainwindow.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCheckBox>

NewDialog::NewDialog(QWidget *parent):
    QDialog(parent)

 {
    MainWindow *mw = new MainWindow(this);
    //创建了一个带有快捷键ALT+W的标签
      QLabel *label = new QLabel(tr("edit &sth:"));

      QLineEdit *lineEdit = new QLineEdit;

      //设置编辑器作为标签的伙伴。按下标签的快捷键时，lineEdit会接受焦点。
      label->setBuddy(lineEdit);

//      QCheckBox *caseCheckBox = new QCheckBox(tr("Match &case"));

//      QCheckBox *backwardCheckBox = new QCheckBox(tr("Search &backward"));

      //Alt+F快捷键会激活Find按钮
      QPushButton *findButton = new QPushButton(tr("&Find"));

      //将Find按钮作为对话框的默认按钮。默认按钮就是当用户按下Enter键时能够按下对应的按钮
      findButton->setDefault(true);
      //将Find按钮禁止
      findButton->setEnabled(true);

      QPushButton *closeButton = new QPushButton(tr("Close"));

      //当lineEdit里面的内容发生变化时，会调用本类的enableFindButton函数。
//      QObject::connect(lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(enableFindButton(const QString &)));

      //当点击Find按钮时，会调用本类的findClicked方法.
      QObject::connect(findButton,SIGNAL(clicked()),this,SLOT(findClicked()));

      //当点击Close按钮时，会调用本类或者父类的close方法
      QObject::connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

      //水平布局  加入部件label  lineEdit
      QHBoxLayout *topLeftLayout = new QHBoxLayout;
      topLeftLayout->addWidget(label);
      topLeftLayout->addWidget(lineEdit);

      //垂直布局  加入水平布局里所有的控件，接着加入caseCheckBox
      QVBoxLayout *leftLayout = new QVBoxLayout;
      leftLayout->addLayout(topLeftLayout);
//      leftLayout->addWidget(caseCheckBox);

      //垂直布局 加入两个按钮部件
      QVBoxLayout *rightLayout = new QVBoxLayout;
      rightLayout->addWidget(findButton);
      rightLayout->addWidget(closeButton);
      //实现布局器的空白控件分配
      rightLayout->addStretch();

      //水平布局 加入之前布局的所有控件
      QHBoxLayout *mainLayout = new QHBoxLayout;
      mainLayout->addLayout(leftLayout);
      mainLayout->addLayout(rightLayout);
      //实现该控件的布局
      setLayout(mainLayout);

      setWindowTitle("Find");
      setFixedHeight(sizeHint().height());
}
NewDialog::~NewDialog(){
    delete ui;
}
NewDialog::close(){

}
NewDialog::findClicked(){

}
