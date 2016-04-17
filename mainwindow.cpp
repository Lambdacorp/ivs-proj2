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
bool check_result=false;

QString textik = "0";

matematics M;


void MainWindow::check_input_zero()
{
    if (num == "0")
    {
        num="";
        if(textik.length()>4)
        {
            if(textik.at(textik.length()-2)==' ')
            {
                textik.remove(textik.length()-1,1);
            }
        }
    }
    if(textik=="0")
    {
        textik="";
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"1";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("1");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"2";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("2");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"3";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("3");
        ui->label->setText(textik);

    }

}


void MainWindow::on_pushButton_0_clicked()
{
    check_input_zero();


    if( num.length() <= 9)
    {
        num= num+"0";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("0");
        ui->label->setText(textik);

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
    textik="0";
    ui->label->setText(textik);
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
        textik.remove(textik.length()-1,1);
        textik.append("0");
        ui->label->setText(textik);

    }
    else
    {
        if( num.at(index) == '.' )
            check_bodka=false;

        num=num.remove(index,1);
        ui->lcdNumber->display(num);

        if (textik.length()== index+1 || textik.length()== index+4)
        {
            textik.remove(index,1);
            ui->label->setText(textik);
        }
        else
        {
            textik.remove(textik.length()-1,1);
            ui->label->setText(textik);
        }
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
    check_result=true;
    if( !std::isnan(A) && !std::isinf(A) )
    {
        num=QString("%1").arg(A, 0, 'g', 10);
        ui->lcdNumber->display(num);
        textik.append(" = ");
        textik.append(num);
        ui->label->setText(textik);
        textik=num;
    }
    else
    {
        ui->lcdNumber->display("Err");
        valueA=0;
        ui->label->setText("Err");
        textik="";
    }
}

void MainWindow::on_pushButton_plus_clicked() //ok TODO
{
                                         //############################################
    if(!check_result)
    {
        QString znamienko=" + ";
        int help=textik.length();
        if ( help==0)
            textik.append("0");
        if ( textik[help-1] == ' ')
        {
            textik.replace(help-3,3,znamienko);
            ui->label->setText(textik);
        }
        else
        {
            textik.append(znamienko);
            ui->label->setText(textik);
        }
    }

    aaa();

    check_plus=true;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
    check_result=false;
}


void MainWindow::on_pushButton_minus_clicked()//ok
{
    aaa();

    QString znamienko=" - ";
    int help=textik.length();
    if (textik[help-1] == ' ')
    {
        textik.replace(help-3,3,znamienko);
        ui->label->setText(textik);
    }
    else
    {
        textik.append(znamienko);
        ui->label->setText(textik);
    }

    check_plus=false;
    check_minus=true;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
    check_result=false;
}



void MainWindow::on_pushButton_div_clicked()//ok
{
    aaa();

    QString znamienko=" / ";
    int help=textik.length();
    if (textik[help-1] == ' ')
    {
        textik.replace(help-3,3,znamienko);
        ui->label->setText(textik);
    }
    else
    {
        textik.append(znamienko);
        ui->label->setText(textik);
    }

    check_plus=false;
    check_minus=false;
    check_div=true;
    check_bodka=false;
    check_nty=false;
    check_multiple=false;
    check_result=false;
}

void MainWindow::on_pushButton_multiple_clicked()//ok
{
    aaa();
    QString znamienko=" * ";
    int help=textik.length();
    if (textik[help-1] == ' ')
    {
        textik.replace(help-3,3,znamienko);
        ui->label->setText(textik);
    }
    else
    {
        textik.append(znamienko);
        ui->label->setText(textik);
    }

    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=false;
    check_multiple=true;
    check_result=false;
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
    check_result=false;
}




void MainWindow::on_pushButton_power_clicked() //ok
{
//    aaa();

    double helpB=0;

    if (num == "")
    {
        textik=QString("%1").arg(valueA, 0, 'g', 10);
        textik.append(" ^2");

        valueA= M.power(valueA);

        check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();

        textik=QString("%1").arg(helpB, 0, 'g', 10);
        textik.append(" ^2");

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

void MainWindow::on_pushButton_factorial_clicked()//ok
{
    double helpB=0;

//    aaa();

    if (num == "" )
    {
        textik=QString("%1").arg(valueA, 0, 'g', 10);
        textik.append(" !");

        valueA=M.fact(valueA);

        check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();

        textik=QString("%1").arg(helpB, 0, 'g', 10);
        textik.append(" !");
        valueA=M.fact(helpB);

        check_and_print(valueA);
    }

    num="";
    check_bodka=false;
}



void MainWindow::on_pushButton_nty_clicked()//ok
{
    aaa();

    QString znamienko=" ^";
    int help=textik.length();
    if (textik[help-1] == ' ')
    {
        textik.replace(help-3,3,znamienko);
        ui->label->setText(textik);
    }
    else
    {
        textik.append(znamienko);
        ui->label->setText(textik);
    }

    check_plus=false;
    check_minus=false;
    check_div=false;
    check_bodka=false;
    check_nty=true;
    check_multiple=false;
    check_result=false;

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

