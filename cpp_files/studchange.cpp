#include "studchange.h"
#include "ui_studchange.h"
#include <QMessageBox>

StudChange::StudChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudChange)
{
    ui->setupUi(this);
    setWindowTitle("Students");
    setWindowIcon(QIcon("SH.jpg"));
    ui->btnChange->setEnabled(false);

    Stud = readStud();
    showTable();
}

StudChange::~StudChange()
{
    delete ui;
}

void StudChange::showTable()
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

void StudChange::on_btnOk_clicked()
{
    int number = ui->linenumber->text().toInt();
    if (number<1||number>Stud.size())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect student's number");
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

void StudChange::on_btnChange_clicked()
{
    QString Name = "";
    QString Surname = "";
    int Class = 0;
    QChar letter = '\0';
    int lessons[8] = {0};
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

    if ((ui->lineclass->text()!=""&&Class<1)||Class>11)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect Class");
        msg->exec();
        delete msg;
    }
    else if ((ui->lineles0->text()!=""&&lessons[0]<2)||lessons[0]>5||(ui->lineles1->text()!=""&&lessons[1]<2)||lessons[1]>5||(ui->lineles2->text()!=""&&lessons[2]<2)||lessons[2]>5||(ui->lineles3->text()!=""&&lessons[3]<2)||lessons[3]>5||(ui->lineles4->text()!=""&&lessons[4]<2)||lessons[4]>5||(ui->lineles5->text()!=""&&lessons[5]<2)||lessons[5]>5||(ui->lineles6->text()!=""&&lessons[6]<2)||lessons[6]>5||(ui->lineles7->text()!=""&&lessons[7]<2)||lessons[7]>5)
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect Lessons");
        msg->exec();
        delete msg;
    }
    else
    {
        Stud[number-1].changeInfo(Name,Surname,Class,letter,lessons);
        showTable();
        rewriteStud(Stud);
        ui->btnChange->setEnabled(false);
        ui->linenumber->clear();
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
    }
}
