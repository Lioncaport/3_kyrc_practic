#ifndef TEACHDELETE_H
#define TEACHDELETE_H

#include "teacher.h"
#include <QWidget>

namespace Ui {
class TeachDelete;
}

class TeachDelete : public QWidget
{
    Q_OBJECT

public:
    explicit TeachDelete(QWidget *parent = nullptr);
    ~TeachDelete();
    QVector <teacher> Teach;

private slots:
    void on_btnDelete_clicked();

private:
    Ui::TeachDelete *ui;
};

#endif // TEACHDELETE_H
