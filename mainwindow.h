#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void aaa();
    void check_and_print(double A);
    void check_input_zero();
    ~MainWindow();



private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_0_clicked();


    void on_pushButton_delete_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_bodka_clicked();


    void on_pushButton_result_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_power_clicked();

    void on_pushButton_sqrtt_clicked();







    void on_exit_triggered();

    void on_pushButton_factorial_clicked();

    void on_pushButton_nty_clicked();

    void on_pushButton_not_clicked();

    void on_pushButton_multiple_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
