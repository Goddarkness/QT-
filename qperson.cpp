#include "qperson.h"

Qperson::Qperson(QString name,QObject *parent) : QObject(parent)
{
  mname = name;
}

unsigned Qperson::Age()
{
    return mage;
}

void Qperson::setAge(unsigned value)
{
    mage = value;
    emit (ageChanged (mage));
}

void Qperson::incAge()
{
    mage++;
    emit (ageChanged (mage));
}
