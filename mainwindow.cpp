/**
* @file mainwindow.cpp
* @version
* @author
* @date
* @author{}
* @brief
* @
* @warning
* @bug
* @copyright GNU Public License.
* @author Lambdacorp
* In this file there are
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <QString>
#include "matematics.h"
#include <math.h>
#include "about.h"
#include "helpwindow.h"

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

//############ Globalne premenne ###############//
/**
* @brief num
*/
QString num = "0";

/**
* @brief valueA
*/
double valueA=0;

char operations='0'; // + - * / % ^ =
bool check_bodka=false;// ak sa bodka vymaze ..
bool check_result=false; // TODO delete it

QString textik = "0"; //
//############################################### //

matematics M;


void MainWindow::check_input_zero()
// pomocna funkcia sluzi na kontrolovanie nuly pri stlaceni tlacidla
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

// ############## Zaciatok Tlacidla 0-9 ##################//
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

void MainWindow::on_pushButton_4_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"4";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("4");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"5";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("5");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_6_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"6";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("6");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_7_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"7";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("7");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_8_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"8";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("8");
        ui->label->setText(textik);

    }
}

void MainWindow::on_pushButton_9_clicked()
{
    check_input_zero();

    if( num.length() <= 9)
    {
        num= num+"9";
        ui->lcdNumber->display(num);

        if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            textik="";

        textik.append("9");
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
// ############## Koniec Tlacidla 0-9 ##################//

// ############## Zaciatok Tlacidla '.', 'del', 'C'##################//
void MainWindow::on_pushButton_bodka_clicked()
{
    if (!check_bodka)
    {
        if (num == "")
        {
            num="0.";
            ui->lcdNumber->display(num);

            if (textik == QString("%1").arg(valueA, 0, 'g', 10))
            {
                textik="0.";
            }
            else
            {
                textik.append("0.");
            }

            ui->label->setText(textik);
        }
        else if( num.length() < 9)
        {
            num= num+".";
            ui->lcdNumber->display(num);

            textik.append(".");
            ui->label->setText(textik);
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

    operations='0';
    //rez.

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
    //TODO EROR delete 2. operacia
}
// ############## Koniec Tlacidla '.', 'del', 'C'##################//


//###########################################
void MainWindow::calculating()
{
    if(num != "")
    {
        double helpB=0;
        helpB=num.toDouble();

        switch( operations )
        {
            case '+' :
                valueA= M.plus(valueA, helpB);
                check_and_print(valueA);
                break;
            case '-' :
                valueA= M.minus(valueA, helpB);
                check_and_print(valueA);
                break;
            case '/' :
                valueA= M.div(valueA,helpB);
                check_and_print(valueA);
                break;
            case '*' :
                valueA=M.multiple(valueA,helpB);
                check_and_print(valueA);
                break;
            case '%' :
                valueA=M.modulo(valueA,helpB);
                check_and_print(valueA);
                break;

            case '^' :
                valueA=M.n_power(valueA,helpB);
                check_and_print(valueA);
                break;

            default:
                break;
        }
        valueA=num.toDouble();
        num="";
    }
}
void MainWindow::check_and_print(double A) // TODO osetrit double -desatinne cisla
{
    check_result=true;
    if( !std::isnan(A) && !std::isinf(A) )
    check_result=true;// TODO zbytocna premenna zatial vsade vymazat ked sa nevyuzije testovat chyby uvidi sa
    if( !std::isnan(A) && !std::isinf(A) )
    {
        num=QString("%1").arg(A, 0, 'g', 10);
        ui->lcdNumber->display(num);
        textik.append(" = ");                   //TODO somarina prepisujem si potom ' = ' za + ale funguje to dobre :)
        textik.append(num);                                                          // optimalizovat ked bude cas
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

void MainWindow::print_help_text(char sign)
{
    //if(!check_result)

        QString znamienko="  ";
        znamienko.insert(1,sign);

        int help=textik.length();

        //if ( help==0)
          //  textik.append("0");
        if ( textik[help-1] == ' ')
        {
            textik.replace(help-2,1,sign);
            ui->label->setText(textik);
        }
        else
        {
            textik.append(znamienko);
            ui->label->setText(textik);
        }

}

// ############## Zaciatok Tlacidla matematickych operacii ##################//
//                        + - * / % ^ ^n ! ln =                              //
void MainWindow::on_pushButton_plus_clicked() //ok
{
    calculating();
    operations='+';
    print_help_text(operations);
    check_result=false;
}


void MainWindow::on_pushButton_minus_clicked()//ok
{
    calculating();
    operations='-';
    print_help_text(operations);
    check_result=false;
}



void MainWindow::on_pushButton_div_clicked()//ok
{
    calculating();
    operations='/';
    print_help_text(operations);
    check_result=false;
}

void MainWindow::on_pushButton_multiple_clicked()//ok
{
    calculating();
    operations='*';
    print_help_text(operations);
    check_result=false;
}
//##############################################################################sqrt -rename modulo
void MainWindow::on_pushButton_sqrtt_clicked()//ok - funguje TODO MODULO
{
    calculating();
    operations='%';
    print_help_text(operations);
    check_result=false;
}

void MainWindow::on_pushButton_result_clicked() // TODO 2*=
{
    calculating();
    num="";
    //operations='=';
    check_result=false;
}

void MainWindow::on_pushButton_nty_clicked()//ok
{
    calculating();
    operations='^';
    print_help_text(operations);
    check_result=false;
}


void MainWindow::on_pushButton_power_clicked() //ok
{
    calculating();
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


void MainWindow::on_pushButton_not_clicked() //TODO ln LOGARITHM
{
    calculating();
    double helpB=0;

    if (num == "")
    {
        textik=QString("%1").arg(valueA, 0, 'g', 10);
        textik.prepend("ln ");

        valueA= M.logaritmus_ln(valueA);

        check_and_print(valueA);
    }
    else
    {
        helpB=num.toDouble();

        textik=QString("%1").arg(helpB, 0, 'g', 10);
        textik.prepend("ln ");

        valueA= M.logaritmus_ln(helpB);

        check_and_print(valueA);
    }
    num="";
    check_bodka=false;
}



/*
void MainWindow:: // TODO delete it
{
    calculating();

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
*/

void MainWindow::on_pushButton_factorial_clicked()//ok
{
    double helpB=0;

    calculating();

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


// ############## Koniec Tlacidla matematickych operacii ##################//


//TODO prerobit nefunguje dobre alebo zmazat
/*
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
*/

// ############## Zaciatok interakcia GUI ##################//

void MainWindow::on_exit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionBlack_and_white_triggered()
{
    ui->actionOriginal->setChecked(false);

    ui->pushButton_0->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_1->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_2->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_3->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_4->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_5->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_6->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_7->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_8->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_9->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");
    ui->pushButton_bodka->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(200, 200, 200));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 255, 255), stop:0.857955 rgb(140, 140, 140));\n }");

    ui->pushButton_result->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 236, 16), stop:0.857955 rgb(255, 255, 0));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(234, 216, 14), stop:0.857955 rgb(245, 245, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(216, 199, 13), stop:0.857955 rgb(245, 245, 0));\n }");

    ui->pushButton_div->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_factorial->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_minus->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_multiple->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_not->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_nty->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_plus->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_power->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");
    ui->pushButton_sqrtt->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\"; 	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(235, 235, 235));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(205, 205, 205));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(240, 240, 240), stop:0.857955 rgb(135, 135, 135));\n }");

    ui->pushButton_clear->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(107, 0, 0), stop:0.857955 rgb(130, 0, 0));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(140, 0, 0), stop:0.857955 rgb(190, 0, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(190, 0, 0), stop:0.857955 rgb(240, 0, 0));\n }");
    ui->pushButton_delete->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(233, 233, 233);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(107, 0, 0), stop:0.857955 rgb(130, 0, 0));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(140, 0, 0), stop:0.857955 rgb(190, 0, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(233, 233, 233);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(190, 0, 0), stop:0.857955 rgb(240, 0, 0));\n }");

    ui->frame->setStyleSheet("background-color: rgb(253, 253, 253);");

    ui->lcdNumber->setStyleSheet("border:0px;\ncolor: rgb(0, 0, 0);\n");
    ui->radioButton->setStyleSheet("color: rgb(0,0,0)");

    ui->frame_2->setStyleSheet("background-color: rgb(242, 242, 242);");
    ui->frame_3->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->frame_6->setStyleSheet("background-color: rgb(242, 242, 242);");
}

void MainWindow::on_actionOriginal_triggered()
{
    ui->actionBlack_and_white->setChecked(false);

    ui->pushButton_0->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_1->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_2->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_3->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_4->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_5->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_6->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_7->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_8->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_9->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");
    ui->pushButton_bodka->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(15, 15, 15));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(25, 25, 25));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(0, 0, 0), stop:0.857955 rgb(60, 60, 60));\n }");

    ui->pushButton_result->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(255, 236, 16), stop:0.857955 rgb(255, 255, 0));\n  color: rgb(0, 0, 0);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(234, 216, 14), stop:0.857955 rgb(245, 245, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(216, 199, 13), stop:0.857955 rgb(245, 245, 0));\n }");

    ui->pushButton_div->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_factorial->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_minus->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_multiple->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_not->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_nty->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_plus->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_power->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");
    ui->pushButton_sqrtt->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(30, 30, 30));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(50, 50, 50));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(15, 15, 15), stop:0.857955 rgb(120, 120, 120));\n }");

    ui->pushButton_clear->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(107, 0, 0), stop:0.857955 rgb(130, 0, 0));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(140, 0, 0), stop:0.857955 rgb(190, 0, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(190, 0, 0), stop:0.857955 rgb(240, 0, 0));\n }");
    ui->pushButton_delete->setStyleSheet("QPushButton\n{\n  border: 1px solid rgb(22, 22, 22);\n  font: 12pt \"Gill Sans MT\";	\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(107, 0, 0), stop:0.857955 rgb(130, 0, 0));\n  color: rgb(230, 230, 230);\n}\n\nQPushButton:hover\n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(140, 0, 0), stop:0.857955 rgb(190, 0, 0));\n}\n\nQPushButton:pressed \n{\n  border: 1px solid rgb(22, 22, 22);\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgb(190, 0, 0), stop:0.857955 rgb(240, 0, 0));\n }");

    ui->frame->setStyleSheet("background-color: rgb(2,2,2)");

    ui->lcdNumber->setStyleSheet("border:0px;\ncolor: rgb(255, 255, 255);\n");
    ui->radioButton->setStyleSheet("color: rgb(255,255,255)");

    ui->frame_2->setStyleSheet("background-color: rgb(13, 13, 13);");
    ui->frame_3->setStyleSheet("background-color: rgb(0, 0, 0);");
    ui->frame_6->setStyleSheet("background-color: rgb(13, 13, 13);");



}

void MainWindow::on_action_e_tina_triggered()
{
    ui->actionAngli_tina->setChecked(false);
    ui->label->setText("Průběh výpočtu");
    ui->actionN_pov_da->setText("Nápověda");
    ui->actionTextiik->setText("O kalkulačce");
    ui->exit->setText("Ukončit");

    ui->actionOriginal->setText("Tmavé");
    ui->actionBlack_and_white->setText("Světlé");

    ui->setting->setTitle("Nastavení");
    ui->setting_set->setTitle("Barevné schéma");
    ui->setting_jazyk->setTitle("Jazyk");
}

void MainWindow::on_actionAngli_tina_triggered()
{
    ui->action_e_tina->setChecked(false);
    ui->label->setText("Calculation process");
    ui->actionN_pov_da->setText("Help");
    ui->actionTextiik->setText("About");
    ui->exit->setText("Exit");

    ui->actionOriginal->setText("Dark");
    ui->actionBlack_and_white->setText("Light");

    ui->setting->setTitle("Settings");
    ui->setting_set->setTitle("Color scheme");
    ui->setting_jazyk->setTitle("Language");
}

void MainWindow::on_actionTextiik_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_actionN_pov_da_triggered()
{
    HelpWindow help;
    help.setModal(true);
    help.exec();
}
