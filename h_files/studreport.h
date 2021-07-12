#ifndef STUDREPORT_H
#define STUDREPORT_H

#include "student.h"
#include <QWidget>

namespace Ui {
class StudReport;
}

class StudReport : public QWidget
{
    Q_OBJECT

public:
    explicit StudReport(QWidget *parent = nullptr);
    ~StudReport();

private:
    Ui::StudReport *ui;
};

#endif // STUDREPORT_H
