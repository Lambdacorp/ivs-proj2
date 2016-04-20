/**
* @file helpwindow.h
* @version 2.4
* @date 19.04.2016
* @author Lambdacorp
* @copyright ©Lambdacorp
* @brief header file for help window
*/

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
