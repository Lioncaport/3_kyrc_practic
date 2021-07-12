#ifndef TEACHCHANGE_H
#define TEACHCHANGE_H

#include "teacher.h"
#include <QWidget>

namespace Ui {
class TeachChange;
}

class TeachChange : public QWidget
{
    Q_OBJECT

public:
    explicit TeachChange(QWidget *parent = nullptr);
    ~TeachChange();
    QVector <teacher> Teach;
    void showTable();

private slots:
    void on_btnOk_clicked();
    void on_btnChange_clicked();

private:
    int number;
    Ui::TeachChange *ui;
};

#endif // TEACHCHANGE_H
