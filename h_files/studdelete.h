#ifndef STUDDELETE_H
#define STUDDELETE_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StudDelete;
}

class StudDelete : public QWidget
{
    Q_OBJECT

public:
    explicit StudDelete(QWidget *parent = nullptr);
    ~StudDelete();
    QVector <student> Stud;

private slots:
    void on_btnDelete_clicked();

private:
    Ui::StudDelete *ui;
};

#endif // STUDDELETE_H
