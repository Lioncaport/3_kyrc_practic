#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

class human
{
public:
    human();
    ~human();
    virtual QString getInfo()=0;
    QString getName();
    QString getSurname();
    int getClass();
    int *getLessons();
protected:
    QString name;
    QString surname;
    int Class;
    int *lessons;
};

#endif // HUMAN_H
