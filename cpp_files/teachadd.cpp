#include "teachadd.h"
#include "ui_teachadd.h"
#include <QMessageBox>

TeachAdd::TeachAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachAdd)
{
    ui->setupUi(this);
    setWindowTitle("Teachers");
    setWindowIcon(QIcon("SH.jpg"));

    Teach = readTeach();
    showTable();
}

TeachAdd::~TeachAdd()
{
    delete ui;
}

void TeachAdd::showTable()
{
    ui->table->setRowCount(Teach.size());
    for (int i=0;i<ui->table->rowCount();i++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem(Teach[i].getName());
            ui->table->setItem(i,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(Teach[i].getSurname());
            ui->table->setItem(i,1,item2);
            QTableWidgetItem *item3 = new QTableWidgetItem(QString().setNum(Teach[i].getClass()));
            ui->table->setItem(i,2,item3);
            for (int j=0;j<8;j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString().setNum(*(Teach[i].getLessons()+j)));
                ui->table->setItem(i,3+j,item);
            }
        }
}

void TeachAdd::on_btnAdd_clicked()
{
    int pos = 0;
    QString Name = "";
    QString Surname = "";
    int Class = 0;
    int lessons[8] = {0};
    pos = ui->linepos->text().toInt();
    Name = ui->linename->text();
    Surname = ui->linesurname->text();
    Class = ui->lineclass->text().toInt();
    lessons[0] = ui->lineles0->text().toInt();
    lessons[1] = ui->lineles1->text().toInt();
    lessons[2] = ui->lineles2->text().toInt();
    lessons[3] = ui->lineles3->text().toInt();
    lessons[4] = ui->lineles4->text().toInt();
    lessons[5] = ui->lineles5->text().toInt();
    lessons[6] = ui->lineles6->text().toInt();
    lessons[7] = ui->lineles7->text().toInt();
    if ((pos==0&&ui->linepos->text()=="")||Name==""||Surname==""||(Class==0&&ui->lineclass->text()=="")||(ui->lineles0->text()==""&&lessons[0]==0)||(ui->lineles1->text()==""&&lessons[1]==0)||(ui->lineles2->text()==""&&lessons[2]==0)||(ui->lineles3->text()==""&&lessons[3]==0)||(ui->lineles4->text()==""&&lessons[4]==0)||(ui->lineles5->text()==""&&lessons[5]==0)||(ui->lineles6->text()==""&&lessons[6]==0)||(ui->lineles7->text()==""&&lessons[7]==0))
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Please, input all data");
        msg->exec();
        delete msg;
    }
    else if (pos<1||pos>Teach.size()+1)
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
    else if (lessons[0]<0||lessons[0]>1||lessons[1]<0||lessons[1]>1||lessons[2]<0||lessons[2]>1||lessons[3]<0||lessons[3]>1||lessons[4]<0||lessons[4]>1||lessons[5]<0||lessons[5]>1||lessons[6]<0||lessons[6]>1||lessons[7]<0||lessons[7]>1)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect Lessons");
        msg->exec();
        delete msg;
    }
    else
    {
        teacher Teacher(Name,Surname,Class,lessons);
        Teach.insert(Teach.begin()+pos-1,Teacher);
        ui->lineprev->setText(Teach[pos-1].getInfo());
        ui->linepos->clear();
        ui->linename->clear();
        ui->linesurname->clear();
        ui->lineclass->clear();
        ui->lineles0->clear();
        ui->lineles1->clear();
        ui->lineles2->clear();
        ui->lineles3->clear();
        ui->lineles4->clear();
        ui->lineles5->clear();
        ui->lineles6->clear();
        ui->lineles7->clear();
        showTable();
        rewriteTeach(Teach);
    }
}
