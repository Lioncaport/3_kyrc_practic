#include "studclassinfo.h"
#include "ui_studclassinfo.h"
#include <QMessageBox>

StudClassInfo::StudClassInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudClassInfo)
{
    ui->setupUi(this);
    setWindowTitle("Students");
    setWindowIcon(QIcon("SH.jpg"));

    Stud = readStud();
}

StudClassInfo::~StudClassInfo()
{
    delete ui;
}

void StudClassInfo::showClass(student &Student)
{
    ui->table->setRowCount(ui->table->rowCount()+1);
    QTableWidgetItem *item1 = new QTableWidgetItem(Student.getName());
    ui->table->setItem(ui->table->rowCount()-1,0,item1);
    QTableWidgetItem *item2 = new QTableWidgetItem(Student.getSurname());
    ui->table->setItem(ui->table->rowCount()-1,1,item2);
    QTableWidgetItem *item3 = new QTableWidgetItem(QString().setNum(Student.getClass()));
    ui->table->setItem(ui->table->rowCount()-1,2,item3);
    QTableWidgetItem *item4 = new QTableWidgetItem(Student.getLetter());
    ui->table->setItem(ui->table->rowCount()-1,3,item4);
    for (int j=0;j<8;j++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(QString().setNum(*(Student.getLessons()+j)));
        ui->table->setItem(ui->table->rowCount()-1,4+j,item);
    }
}

void StudClassInfo::on_btnOk_clicked()
{
    ui->table->setRowCount(0);
    int Class = 0;
    QChar letter = '\0';
    Class = ui->lineclass->text().toInt();
    letter = ui->linelet->text()[0];
    if ((ui->lineclass->text()==""&&Class==0)||letter=='\0')
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Please, input all data");
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
    else
    {
        for (int i=0;i<Stud.size();i++)
        {
            if ((Class==Stud[i].getClass())&&(letter==Stud[i].getLetter())) showClass(Stud[i]);
        }
    }
}
