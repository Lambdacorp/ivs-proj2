#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <QString>
#include "matematics.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
* @brief num
*/
QString num = "0";

/**
* @brief valueA
*/
double valueA=0;

//double valueB=0;


bool check_plus=false;
bool check_minus=false;
bool check_div=false;
bool check_nty=false;
bool check_multiple=false;
bool check_bodka=false;// ak sa bodka vymaze ..

matematics M;



void MainWindow::on_pushButton_1_clicked()
{
    if (num == "0")
        num="";

    if( num.length() <= 9)
    {
        num= num+"1";
        ui->lcdNumber->display(num);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (num == "0")
        num="";

    if( num.length() <= 9)
    {
        num= num+"2";
        ui->lcdNumber->display(num);

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (num == "0")
        num="";

    if( num.length() <= 9)
    {
        num= num+"3";
        ui->lcdNumber->display(num);

    }
}

void MainWindow::on_pushButton_0_clicked()
{
    if (num == "0")
        num="";

    else if( num.length() <= 9)
    {
        num= num+"0";
        ui->lcdNumber->display(num);

    }
}

void MainWindow::on_pushButton_bodka_clicked()
{
    if (!check_bodka)
    {
        if (num == "")
        {
            num="0.";
            ui->lcdNumber->display(num);
        }
        else if( num.length() < 9)
        {
            num= num+".";
            ui->lcdNumber->display(num);
        }

        check_bodka=true;
    }

}


void MainWindow::on_pushButton_clear_clicked()
{
    num="0";
    ui->lcdNumber->display(num);
    valueA=0;

    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
}

void MainWindow::on_pushButton_delete_clicked()
{
    int index= num.length()-1;
    if (index<=0)
    {
        num="0";
        ui->lcdNumber->display(num);
    }
    else
    {
        if( num.at(index) == '.' )
            check_bodka=false;

        num=num.remove(index,1);
        ui->lcdNumber->display(num);
    }
}

//###########################################
void MainWindow::aaa() // tODO rename ... case
{


    if(num != "")
    {
        {
            double helpB=0;
            helpB=num.toDouble();

            if (check_plus)
            {
                valueA= M.plus(valueA, helpB);

                check_and_print(valueA);

            }

            if (check_minus)
            {
                valueA= M.minus(valueA, helpB);

                check_and_print(valueA);
            }

            if (check_div)
            {
                valueA= M.div(valueA,helpB);

                check_and_print(valueA);
            }

            if (check_multiple)
            {
                valueA=M.multiple(valueA,helpB);

                check_and_print(valueA);
            }

            if (check_nty)
            {
                valueA=M.n_power(valueA,helpB);

                check_and_print(valueA);
            }
        }


        valueA=num.toDouble();
        num="";
    }
}

void MainWindow::check_and_print(double A) // TODO osetrit double -desatinne cisla
{
    if( !std::isnan(A) && !std::isinf(A) )
    {
        num=QString("%1").arg(A, 0, 'g', 10);
        ui->lcdNumber->display(num);
    }
    else
    {
        ui->lcdNumber->display("Err");
        valueA=0;
    }
}

void MainWindow::on_pushButton_plus_clicked() // TODO
{
    aaa();

    check_plus=true;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
}


void MainWindow::on_pushButton_minus_clicked()
{
    aaa();

    check_plus=false;
    check_minus=true;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
}



void MainWindow::on_pushButton_div_clicked()
{
    aaa();

    check_plus=false;
    check_minus=false;
    check_div=true;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;

}

void MainWindow::on_pushButton_multiple_clicked()
{
    aaa();

    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=true;
}


void MainWindow::on_pushButton_result_clicked() // TODO 2*=
{
    aaa();
    num="";
    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
}




void MainWindow::on_pushButton_power_clicked()
{
//    aaa();
    double helpB=0;
    if (num == "")
    {
            valueA= M.power(valueA);

            check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();
        valueA= M.power(helpB);

        check_and_print(valueA);
    }

    num="";
    check_bodka=false;
}





void MainWindow::on_pushButton_sqrtt_clicked()
{
//    aaa();

    double helpB=0;
    if (num == "")
    {
        valueA=sqrt(valueA);

        check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();
        valueA=sqrt(helpB);

        check_and_print(valueA);
    }

    num="";
    check_bodka=false;
}

void MainWindow::on_pushButton_factorial_clicked()
{
    double helpB=0;

//    aaa();

    if (num == "" )
    {
        valueA=M.fact(valueA);

        check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();
        valueA=M.fact(helpB);

        check_and_print(valueA);
    }

    num="";
    check_bodka=false;
}



void MainWindow::on_pushButton_nty_clicked()
{
    aaa();

    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=true;
    check_multiple=false;

}





void MainWindow::on_exit_triggered()
{
    qApp->quit();
}

//TODO prerobit nefunguje dobre
void MainWindow::on_pushButton_not_clicked()
{
        if( num.at(num.length()-1) == '.' )
        {
            num=num.remove(num.length()-1,1);
            check_bodka=false;
        }

    if( num == "-" )
    {
        num="0";
        ui->lcdNumber->display(num);
    }
    else if( num == "" )
    {
        num="-";
        ui->lcdNumber->display(num);
    }
    else if( num == "0" )
    {
        num="-";
        ui->lcdNumber->display(num);
    }
    else
    {
        valueA=num.toDouble();
        valueA=valueA*-1;
        num=QString("%1").arg(valueA, 0, 'g', 9);
        ui->lcdNumber->display(num);
    }

}

