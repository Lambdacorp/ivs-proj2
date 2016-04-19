/**
*  @mainpage Vitajte na stránke Dokumentácie projekt 2 - Kalkulacka.
* @file main.cpp
*
* @brief Main file
* @author Lambdacorp
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
