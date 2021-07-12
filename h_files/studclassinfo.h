#ifndef STUDCLASSINFO_H
#define STUDCLASSINFO_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StudClassInfo;
}

class StudClassInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StudClassInfo(QWidget *parent = nullptr);
    ~StudClassInfo();
    QVector <student> Stud;
    void showClass(student &);

private slots:
    void on_btnOk_clicked();

private:
    Ui::StudClassInfo *ui;
};

#endif // STUDCLASSINFO_H
