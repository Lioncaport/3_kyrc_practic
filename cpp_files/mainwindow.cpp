#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "student.h"
#include "teacher.h"
#include "studadd.h"
#include "studchange.h"
#include "studdelete.h"
#include "studclassinfo.h"
#include "studreport.h"
#include "teachadd.h"
#include "teachchange.h"
#include "teachdelete.h"
#include "teachlessoninfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("School Helper");
    //setWindowIcon(QIcon("SH.ico"));
    QObject::connect(ui->action,&QAction::triggered,this,&MainWindow::showInfoByProgramm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInfoByProgramm()
{
    QMessageBox *msg = new QMessageBox();
    msg->setWindowTitle("О программе");
    msg->setText("           Учебная практика\n");
    msg->setText(msg->text()+"Вариант: 2\n");
    msg->setText(msg->text()+"Выполнил: Ткачев Игорь\n");
    msg->setText(msg->text()+"Группа: 8307\n");
    msg->setText(msg->text()+"Среда разработки: Qt Creactor\n");
    msg->setText(msg->text()+"Язык программирования: си++");
    msg->exec();
    delete msg;
}

void MainWindow::on_studShow_clicked()
{
    QVector <student> Stud;
    Stud = readStud();
    ui->table->setRowCount(Stud.size());
    ui->table->setColumnCount(12);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Name" << "Surname" << "Class" << "Letter" << "Math" << "Physics" << "Biology" << "Chemistry" << "Physculture" << "History" << "Geography" << "Literature");
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

void MainWindow::on_studAdd_clicked()
{
    StudAdd *sAdd = new StudAdd();
    sAdd->show();
}

void MainWindow::on_studChange_clicked()
{
    StudChange *sChange = new StudChange();
    sChange->show();
}

void MainWindow::on_studDelete_clicked()
{
    StudDelete *sDelete = new StudDelete();
    sDelete->show();
}

void MainWindow::on_studClassInfo_clicked()
{
    StudClassInfo *sClassInfo = new StudClassInfo();
    sClassInfo->show();
}

void MainWindow::on_studReport_clicked()
{
    StudReport *sReport = new StudReport();
    sReport->show();
}

void MainWindow::on_teachShow_clicked()
{
    QVector <teacher> Teach;
    Teach = readTeach();
    ui->table->setRowCount(Teach.size());
    ui->table->setColumnCount(11);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Name" << "Surname" << "Class" << "Math" << "Physics" << "Biology" << "Chemistry" << "Physculture" << "History" << "Geography" << "Literature");
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

void MainWindow::on_teachAdd_clicked()
{
    TeachAdd *tAdd = new TeachAdd();
    tAdd->show();
}

void MainWindow::on_teachChange_clicked()
{
    TeachChange *tChange = new TeachChange();
    tChange->show();
}

void MainWindow::on_teachDelete_clicked()
{
    TeachDelete *tDelete = new TeachDelete();
    tDelete->show();
}

void MainWindow::on_teachLessonInfo_clicked()
{
    TeachLessonInfo *tLessonInfo = new TeachLessonInfo();
    tLessonInfo->show();
}
