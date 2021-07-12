#include "student.h"
#include <QFile>
#include <QTextStream>

student::student(): human(), letter('\0')
{}
student::student(QString name, QString surname, int Class, QChar letter, int *lessons)
{
    this->name=name;
    this->surname=surname;
    this->Class=Class;
    this->letter=letter;
    this->lessons=new int[8];
    for (int i=0;i<8;i++) this->lessons[i]=lessons[i];
}
student::student(const student &stud)
{
    name=stud.name;
    surname=stud.surname;
    Class=stud.Class;
    letter=stud.letter;
    lessons=new int[8];
    for (int i=0;i<8;i++) lessons[i]=stud.lessons[i];
}
student::~student()
{
    delete []lessons;
}
QString student::getInfo()
{
    QString str=name+" "+surname+" "+QString().setNum(Class)+" "+letter;
    for (int i=0;i<8;i++) str=str+" "+QString().setNum(lessons[i]);
    return str;
}
void student::changeInfo(QString name,QString surname,int Class,QChar letter,int* lessons)
{
    if (name!="") this->name=name;
    if (surname!="") this->surname=surname;
    if (Class!=0) this->Class=Class;
    if (letter!='\0') this->letter=letter;
    for (int i=0;i<8;i++)
    {
        if (lessons[i]!=0) this->lessons[i]=lessons[i];
    }
}
QChar student::getLetter()
{
    return letter;
}

QVector <student> readStud()
{
    QVector <student> Stud;
    QString Name;
    QString Surname;
    int Class;
    QChar letter;
    int lessons[8];
    QFile file("Stud.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        in >> Name;
        in >> Surname;
        in >> Class;
        in >> letter;
        in >> letter;
        for (int i=0; i<8; i++) in >> lessons[i];
        student Student(Name,Surname,Class,letter,lessons);
        Stud.push_back(Student);
    }
    file.close();
    return Stud;
}

void rewriteStud(QVector <student> &Stud)
{
    QFile file("Stud.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream in(&file);
    for (int i=0;i<Stud.size()-1;i++)
    {
        in << Stud[i].getInfo();
        in << "\n";
    }
    if (Stud.size()!=0) in << Stud[Stud.size()-1].getInfo();
    file.close();
}
