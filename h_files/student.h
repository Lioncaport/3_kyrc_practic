#ifndef STUDENT_H
#define STUDENT_H

#include "human.h"

class student : public human
{
public:
    student();
    student(QString,QString,int,QChar,int*);
    student(const student&);
    ~student();
    QString getInfo() override;
    void changeInfo(QString,QString,int,QChar,int*);
    QChar getLetter();
private:
    QChar letter;
};

QVector <student> readStud();
void rewriteStud(QVector <student> &);

#endif // STUDENT_H
