#include "teachchange.h"
#include "ui_teachchange.h"
#include <QMessageBox>

TeachChange::TeachChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachChange)
{
    ui->setupUi(this);
    setWindowTitle("Teachers");
    setWindowIcon(QIcon("SH.jpg"));
    ui->btnChange->setEnabled(false);

    Teach = readTeach();
    showTable();
}

TeachChange::~TeachChange()
{
    delete ui;
}

void TeachChange::showTable()
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


void TeachChange::on_btnOk_clicked()
{
    int number = ui->linenumber->text().toInt();
    if (number<1||number>Teach.size())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect teacher's number");
        msg->exec();
        delete msg;
    }
    else
    {
        this->number=number;
        ui->btnChange->setEnabled(true);
        ui->table->selectRow(number-1);
    }
}

void TeachChange::on_btnChange_clicked()
{
    QString Name = "";
    QString Surname = "";
    int Class = 0;
    int lessons[8] = {0};
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

    if ((ui->lineclass->text()!=""&&Class<1)||Class>11)
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
        if (ui->lineles0->text()=="") lessons[0]=-1;
        if (ui->lineles1->text()=="") lessons[1]=-1;
        if (ui->lineles2->text()=="") lessons[2]=-1;
        if (ui->lineles3->text()=="") lessons[3]=-1;
        if (ui->lineles4->text()=="") lessons[4]=-1;
        if (ui->lineles5->text()=="") lessons[5]=-1;
        if (ui->lineles6->text()=="") lessons[6]=-1;
        if (ui->lineles7->text()=="") lessons[7]=-1;
        Teach[number-1].changeInfo(Name,Surname,Class,lessons);
        showTable();
        rewriteTeach(Teach);
        ui->btnChange->setEnabled(false);
        ui->linenumber->clear();
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
    }
}
