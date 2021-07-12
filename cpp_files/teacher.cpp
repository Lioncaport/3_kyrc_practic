#include "teacher.h"
#include <QFile>
#include <QTextStream>

teacher::teacher(): human()
{}
teacher::teacher(QString name, QString surname, int Class, int *lessons)
{
    this->name=name;
    this->surname=surname;
    this->Class=Class;
    this->lessons=new int[8];
    for (int i=0;i<8;i++) this->lessons[i]=lessons[i];
}
teacher::teacher(const teacher &teach)
{
    name=teach.name;
    surname=teach.surname;
    Class=teach.Class;
    lessons=new int[8];
    for (int i=0;i<8;i++) lessons[i]=teach.lessons[i];
}
teacher::~teacher()
{
    delete []lessons;
}
QString teacher::getInfo()
{
    QString str=name+" "+surname+" "+QString().setNum(Class);
    for (int i=0;i<8;i++) str=str+" "+QString().setNum(lessons[i]);
    return str;
}
void teacher::changeInfo(QString name,QString surname,int Class,int* lessons)
{
    if (name!="") this->name=name;
    if (surname!="") this->surname=surname;
    if (Class!=0) this->Class=Class;
    for (int i=0;i<8;i++)
    {
        if (lessons[i]!=-1) this->lessons[i]=lessons[i];
    }
}

QVector <teacher> readTeach()
{
    QVector <teacher> Teach;
    QString Name;
    QString Surname;
    int Class;
    int lessons[8];
    QFile file("Teach.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        in >> Name;
        in >> Surname;
        in >> Class;
        for (int i=0; i<8; i++) in >> lessons[i];
        teacher Teacher(Name,Surname,Class,lessons);
        Teach.push_back(Teacher);
    }
    file.close();
    return Teach;
}

void rewriteTeach(QVector <teacher> &Teach)
{
    QFile file("Teach.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream in(&file);
    for (int i=0;i<Teach.size()-1;i++)
    {
        in << Teach[i].getInfo();
        in << "\n";
    }
    if (Teach.size()!=0) in << Teach[Teach.size()-1].getInfo();
    file.close();
}
