#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void showInfoByProgramm();
    void on_studShow_clicked();
    void on_studAdd_clicked();
    void on_studChange_clicked();
    void on_studDelete_clicked();
    void on_studClassInfo_clicked();
    void on_studReport_clicked();
    void on_teachShow_clicked();
    void on_teachAdd_clicked();
    void on_teachChange_clicked();
    void on_teachDelete_clicked();
    void on_teachLessonInfo_clicked();
};

#endif // MAINWINDOW_H
