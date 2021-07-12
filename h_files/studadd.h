#ifndef STUDADD_H
#define STUDADD_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StudAdd;
}

class StudAdd : public QWidget
{
    Q_OBJECT

public:
    explicit StudAdd(QWidget *parent = nullptr);
    ~StudAdd();
    QVector <student> Stud;
    void showTable();

private:
    Ui::StudAdd *ui;

private slots:
    void on_btnAdd_clicked();
};

#endif // STUDADD_H
