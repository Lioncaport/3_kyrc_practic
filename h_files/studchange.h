#ifndef STUDCHANGE_H
#define STUDCHANGE_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StudChange;
}

class StudChange : public QWidget
{
    Q_OBJECT

public:
    explicit StudChange(QWidget *parent = nullptr);
    ~StudChange();
    QVector <student> Stud;
    void showTable();

private slots:
    void on_btnOk_clicked();
    void on_btnChange_clicked();

private:
    int number;
    Ui::StudChange *ui;
};

#endif // STUDCHANGE_H
