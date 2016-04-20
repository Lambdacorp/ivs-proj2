/**
* @mainpage Welcome to page
* @file main.cpp
* @version 2.4
* @date 19.04.2016
* @author Lambdacorp
* @copyright ©Lambdacorp
* @brief Main file
*
* Main file with main function
*/

#include "mainwindow.h"
#include <QApplication>

/**
* @brief Main function
* @param arcg number of arguments, argv array of arguments
*
* POPIS
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
