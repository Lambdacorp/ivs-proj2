/**
* @file mainwindow.h
*
* @brief Header file for main window
* @author Lambdacorp
* In this file there are
*/

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
    void calculating();
    void check_and_print(double A);
    void check_input_zero();
    void print_help_text(char sign);
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

    void on_actionBlack_and_white_triggered();

    void on_actionOriginal_triggered();

    void on_action_e_tina_triggered();

    void on_actionAngli_tina_triggered();

    void on_actionTextiik_triggered();

    void on_actionN_pov_da_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
