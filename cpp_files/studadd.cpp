#include "studadd.h"
#include "ui_studadd.h"
#include <QMessageBox>

StudAdd::StudAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudAdd)
{
    ui->setupUi(this);
    setWindowTitle("Students");
    setWindowIcon(QIcon("SH.jpg"));

    Stud = readStud();
    showTable();
}

StudAdd::~StudAdd()
{
    delete ui;
}

void StudAdd::showTable()
{
    ui->table->setRowCount(Stud.size());
    for (int i=0;i<ui->table->rowCount();i++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem(Stud[i].getName());
            ui->table->setItem(i,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(Stud[i].getSurname());
            ui->table->setItem(i,1,item2);
            QTableWidgetItem *item3 = new QTableWidgetItem(QString().setNum(Stud[i].getClass()));
            ui->table->setItem(i,2,item3);
            QTableWidgetItem *item4 = new QTableWidgetItem(Stud[i].getLetter());
            ui->table->setItem(i,3,item4);
            for (int j=0;j<8;j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString().setNum(*(Stud[i].getLessons()+j)));
                ui->table->setItem(i,4+j,item);
            }
        }
}

void StudAdd::on_btnAdd_clicked()
{
    int pos = 0;
    QString Name = "";
    QString Surname = "";
    int Class = 0;
    QChar letter = '\0';
    int lessons[8] = {0};
    pos = ui->linepos->text().toInt();
    Name = ui->linename->text();
    Surname = ui->linesurname->text();
    Class = ui->lineclass->text().toInt();
    letter = ui->linelet->text()[0];
    lessons[0] = ui->lineles0->text().toInt();
    lessons[1] = ui->lineles1->text().toInt();
    lessons[2] = ui->lineles2->text().toInt();
    lessons[3] = ui->lineles3->text().toInt();
    lessons[4] = ui->lineles4->text().toInt();
    lessons[5] = ui->lineles5->text().toInt();
    lessons[6] = ui->lineles6->text().toInt();
    lessons[7] = ui->lineles7->text().toInt();
    if ((pos==0&&ui->linepos->text()=="")||Name==""||Surname==""||(Class==0&&ui->lineclass->text()=="")||letter=='\0'||(ui->lineles0->text()==""&&lessons[0]==0)||(ui->lineles1->text()==""&&lessons[1]==0)||(ui->lineles2->text()==""&&lessons[2]==0)||(ui->lineles3->text()==""&&lessons[3]==0)||(ui->lineles4->text()==""&&lessons[4]==0)||(ui->lineles5->text()==""&&lessons[5]==0)||(ui->lineles6->text()==""&&lessons[6]==0)||(ui->lineles7->text()==""&&lessons[7]==0))
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Please, input all data");
        msg->exec();
        delete msg;
    }
    else if (pos<1||pos>Stud.size()+1)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect position");
        msg->exec();
        delete msg;
    }
    else if (Class<1||Class>11)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect Class");
        msg->exec();
        delete msg;
    }
    else if (lessons[0]<2||lessons[0]>5||lessons[1]<2||lessons[1]>5||lessons[2]<2||lessons[2]>5||lessons[3]<2||lessons[3]>5||lessons[4]<2||lessons[4]>5||lessons[5]<2||lessons[5]>5||lessons[6]<2||lessons[6]>5||lessons[7]<2||lessons[7]>5)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect Lessons");
        msg->exec();
        delete msg;
    }
    else
    {
        student Student(Name,Surname,Class,letter,lessons);
        Stud.insert(Stud.begin()+pos-1,Student);
        ui->lineprev->setText(Stud[pos-1].getInfo());
        ui->linepos->clear();
        ui->linename->clear();
        ui->linesurname->clear();
        ui->lineclass->clear();
        ui->linelet->clear();
        ui->lineles0->clear();
        ui->lineles1->clear();
        ui->lineles2->clear();
        ui->lineles3->clear();
        ui->lineles4->clear();
        ui->lineles5->clear();
        ui->lineles6->clear();
        ui->lineles7->clear();
        showTable();
        rewriteStud(Stud);
    }
}
