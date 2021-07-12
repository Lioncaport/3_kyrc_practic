#ifndef TEACHLESSONINFO_H
#define TEACHLESSONINFO_H

#include "teacher.h"
#include <QWidget>

namespace Ui {
class TeachLessonInfo;
}

class TeachLessonInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TeachLessonInfo(QWidget *parent = nullptr);
    ~TeachLessonInfo();

private slots:
    void showLessonInfo();

private:
    Ui::TeachLessonInfo *ui;
};

#endif // TEACHLESSONINFO_H
