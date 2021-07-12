#include "human.h"

human::human(): name(""),surname(""),Class(0)
{
    lessons=new int[8];
    for (int i=0;i<8;i++) lessons[i]=0;
}
human::~human()
{
    delete []lessons;
}
QString human::getName()
{
    return name;
}
QString human::getSurname()
{
    return surname;
}
int human::getClass()
{
    return Class;
}
int* human::getLessons()
{
    return lessons;
}
