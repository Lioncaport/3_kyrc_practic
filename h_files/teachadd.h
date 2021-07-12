#ifndef TEACHADD_H
#define TEACHADD_H

#include "teacher.h"
#include <QWidget>

namespace Ui {
class TeachAdd;
}

class TeachAdd : public QWidget
{
    Q_OBJECT

public:
    explicit TeachAdd(QWidget *parent = nullptr);
    ~TeachAdd();
    QVector <teacher> Teach;
    void showTable();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::TeachAdd *ui;
};

#endif // TEACHADD_H
