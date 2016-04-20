/**
* @file about.ccp
* @version 2.4
* @date 19.04.2016
* @author Lambdacorp
* @copyright ©Lambdacorp
* @brief ..todo
*/
#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}
