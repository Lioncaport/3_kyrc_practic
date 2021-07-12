#include "teachlessoninfo.h"
#include "ui_teachlessoninfo.h"
#include <QMessageBox>

TeachLessonInfo::TeachLessonInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachLessonInfo)
{
    ui->setupUi(this);
    setWindowTitle("Teachers");
    setWindowIcon(QIcon("SH.jpg"));

    connect(ui->checkBox0,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox1,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox2,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox3,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox4,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox5,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox6,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
    connect(ui->checkBox7,&QCheckBox::clicked,this,&TeachLessonInfo::showLessonInfo);
}

TeachLessonInfo::~TeachLessonInfo()
{
    delete ui;
}

void TeachLessonInfo::showLessonInfo()
{
    ui->textEdit->clear();
    bool mas[8]={0};
    mas[0]=ui->checkBox0->isChecked();
    mas[1]=ui->checkBox1->isChecked();
    mas[2]=ui->checkBox2->isChecked();
    mas[3]=ui->checkBox3->isChecked();
    mas[4]=ui->checkBox4->isChecked();
    mas[5]=ui->checkBox5->isChecked();
    mas[6]=ui->checkBox6->isChecked();
    mas[7]=ui->checkBox7->isChecked();
    QVector <teacher> Teach = readTeach();
    for (int i=0;i<Teach.size();i++)
    {
        bool key = false;
        for (int j=0;j<8;j++)
            if (mas[j]==true)
            {
                if (*(Teach[i].getLessons()+j)==1) key=true;
                else
                {
                    key=false;
                    j=8;
                }
            }
        if (key) ui->textEdit->setText(QString().setNum(i+1)+") "+Teach[i].getName()+" "+Teach[i].getSurname());
    }
}
