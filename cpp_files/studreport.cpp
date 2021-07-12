#include "studreport.h"
#include "ui_studreport.h"
#include <QMessageBox>
#include <QIcon>

StudReport::StudReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudReport)
{
    ui->setupUi(this);
    setWindowTitle("Students");
    setWindowIcon(QIcon("SH.jpg"));

    int cnt2=0;
    int cnt5=0;
    QVector <student> Stud;
    Stud = readStud();
    for (int i=0;i<Stud.size();i++)
    {
        bool key=true;
        for (int j=0;j<8;j++) key=key&&(2!=*(Stud[i].getLessons()+j));
        if (!key) ui->editTwo->setText(ui->editTwo->toPlainText()+QString().setNum(++cnt2)+") "+Stud[i].getName()+" "+Stud[i].getSurname()+" "+QString().setNum(Stud[i].getClass())+" "+Stud[i].getLetter()+"\n");
        key=true;
        for (int j=0;j<8;j++) key=key&&(5==*(Stud[i].getLessons()+j));
        if (key) ui->editFive->setText(ui->editFive->toPlainText()+QString().setNum(++cnt5)+") "+Stud[i].getName()+" "+Stud[i].getSurname()+" "+QString().setNum(Stud[i].getClass())+" "+Stud[i].getLetter()+"\n");
    }
    ui->line2->setText(QString().setNum(cnt2));
    ui->line5->setText(QString().setNum(cnt5));
}

StudReport::~StudReport()
{
    delete ui;
}
