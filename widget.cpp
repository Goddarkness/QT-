#include "widget.h"
#include "ui_widget.h"
#include "qperson.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinboy->setProperty("isboy",true);
    ui->spingirl->setProperty("isboy",false);

    boy = new Qperson ("诚哥 ");
    boy->setProperty("score",85);
    boy->setProperty("age",8);
    boy->setProperty("sex","boy");
    connect(boy ,&Qperson::ageChanged,this,&Widget::on_agechanged);

    girl = new Qperson ("世界 ");
    girl->setProperty("score",85);
    girl->setProperty("age",8);
    girl->setProperty("sex","girl");
    connect(girl ,&Qperson::ageChanged,this,&Widget::on_agechanged);
    connect(ui->spinboy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valuechanged(int)));
    connect(ui->spingirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valuechanged(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_boyageInc_clicked()
{
    boy->incAge();
}

void Widget::on_girlageInc_clicked()
{
    girl->incAge();
}

void Widget::on_information_clicked()
{

}

void Widget::on_spin_valuechanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinbox = qobject_cast<QSpinBox*>(sender());
    if(spinbox->property("isboy").toBool())
        boy->setAge(spinbox->value());
    else
        girl->setAge(spinbox->value());

}

void Widget::on_agechanged(unsigned value)
{
    Q_UNUSED(value);
    Qperson *aperson = qobject_cast<Qperson *>(sender());
    QString aname = aperson->property("name").toString();
    QString asex = aperson->property("sex").toString();
    unsigned aage = aperson->Age();
    ui->TextEdit->appendPlainText(aname+","+asex+QString::asprintf(",年龄是%d",aage));
}
