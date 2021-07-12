#ifndef TEACHER_H
#define TEACHER_H

#include "human.h"

class teacher : public human
{
public:
    teacher();
    teacher(QString,QString,int,int*);
    teacher(const teacher&);
    ~teacher();
    QString getInfo() override;
    void changeInfo(QString,QString,int,int*);
};

QVector <teacher> readTeach();
void rewriteTeach(QVector <teacher> &);

#endif // TEACHER_H
