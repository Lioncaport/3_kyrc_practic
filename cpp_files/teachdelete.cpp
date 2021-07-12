#include "teachdelete.h"
#include "ui_teachdelete.h"
#include <QMessageBox>

TeachDelete::TeachDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachDelete)
{
    ui->setupUi(this);
    setWindowTitle("Teachers");
    setWindowIcon(QIcon("SH.jpg"));

    Teach = readTeach();
}

TeachDelete::~TeachDelete()
{
    delete ui;
}

void TeachDelete::on_btnDelete_clicked()
{
    int number = 0;
    number = ui->linenumber->text().toInt();
    if (ui->linenumber->text()=="")
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Please, input teacher's number");
        msg->exec();
        delete msg;
    }
    else if (number<1||number>Teach.size())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect teacher's number");
        msg->exec();
        delete msg;
    }
    else
    {
        ui->lineprev->setText(Teach[number-1].getInfo());
        Teach.erase(Teach.begin()+number-1);
        rewriteTeach(Teach);
        ui->linenumber->clear();
    }
}
