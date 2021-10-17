#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qperson.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
 private:
    Qperson *boy;
    Qperson *girl;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void on_boyageInc_clicked();
    void on_girlageInc_clicked();
    void on_information_clicked();
    void on_spin_valuechanged( int arg1);
    void on_agechanged( unsigned value);

};

#endif // WIDGET_H
