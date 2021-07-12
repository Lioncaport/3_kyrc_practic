#include "studdelete.h"
#include "ui_studdelete.h"
#include <QMessageBox>

StudDelete::StudDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudDelete)
{
    ui->setupUi(this);
    setWindowTitle("Students");
    setWindowIcon(QIcon("SH.jpg"));

    Stud = readStud();
}

StudDelete::~StudDelete()
{
    delete ui;
}

void StudDelete::on_btnDelete_clicked()
{
    int number = 0;
    number = ui->linenumber->text().toInt();
    if (ui->linenumber->text()=="")
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Please, input student's number");
        msg->exec();
        delete msg;
    }
    else if (number<1||number>Stud.size())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error!!!");
        msg->setText("Incorrect student's number");
        msg->exec();
        delete msg;
    }
    else
    {
        ui->lineprev->setText(Stud[number-1].getInfo());
        Stud.erase(Stud.begin()+number-1);
        rewriteStud(Stud);
        ui->linenumber->clear();
    }
}
