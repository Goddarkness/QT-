#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class Qperson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","Arxibye")
    Q_CLASSINFO("company","IBM")
    Q_CLASSINFO("version","1.0")
    Q_PROPERTY(unsigned Age READ Age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER mname)
    Q_PROPERTY(int score MEMBER mscore)
public:
    explicit Qperson(QString name,QObject *parent = nullptr);
    unsigned Age();
    void setAge( unsigned value);
    void incAge();
private:
    unsigned mage = 10;
    QString mname;
    int mscore = 80;


signals:
    ageChanged( unsigned value);

public slots:
};

#endif // QPERSON_H
