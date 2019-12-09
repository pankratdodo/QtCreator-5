#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int flag;

    flag = 0;
    ui->setupUi(this);
    ui->label1->setText("+");
    ui->label_res->clear();
    ui->pushButton->setText("Результат суммы");
    ui->labelO1->setText("Слагаемое 1");
    ui->labelO2->setText("Слагаемое 2");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString s1;
    QString s2;
    bool flag;//для первого числа
    bool flag2;//для второго числа
    bool flag3;//для доп проверок
    bool flag4 = 0;//для проверки первого окна при корне
    bool checkmax1;
    bool checkmax2;
    bool checkmin1;
    bool checkmin2;
    double num1;
    double num2;

    s1.clear();
    s2.clear();
    flag3 = 0;
    s1.append((ui->lineEdit->text()));
    s2.append(ui->lineEdit_2->text());
    num1 = s1.toDouble(&flag);
    num2 = s2.toDouble(&flag2);
    checkmax1 = qIsInf(num1);
    checkmax2 = qIsInf(num2);
    checkmin1 = qIsInf(-num1);
    checkmin2 = qIsInf(-num2);
    //ПРОВЕРКА И ВЫВОД КОРНЯ..........................
    if (flag2 && !checkmax2)
    {
       if (ui->radioButtonKor->isChecked())
       {
           if (num2 <= 0)//проверка на отрицательный корень
           {
               ui->label_res->setText("Корень должен быть больше 0");
               flag3 = 1;
           }
           else
            num1 = sqrt(num2);
       }
    }
    //ОШИБКИ...........................................
    if ((checkmax1 && num1 > 0) || (checkmax2 && num2 > 0))
    {
        ui->label_res->clear();
        ui->label_res->setText("Превышен лимит максимального значения");
        flag4 = 1;
    }
    if ((checkmin1 && num1 < 0) || (checkmin2 && num2 < 0))
    {
        ui->label_res->clear();
        ui->label_res->setText("Превышен лимит минимального значения");
        flag4 = 1;
    }
    if (flag && !flag2 && !flag3 && !flag4 && !checkmax2)
    {
        ui->label_res->clear();
        ui->label_res->setText("Ошибка во второй строке");
    }
    if (flag2 && !flag && !flag3   && !flag4 && !checkmax2)
    {
        ui->label_res->clear();
        ui->label_res->setText("Ошибка в первой строке");
    }
    if (!flag && !flag2 && !flag3 && !flag4 && !checkmax2)
    {
        ui->label_res->clear();
        ui->label_res->setText("Ошибка в обоих строках");
    }
    //ОБРАБОТКА ВЫБОРА.................................
    if (flag2 && !checkmax2)
    {
        if (flag && !checkmax1 && ui->radioButtonPlus->isChecked())
            num1 = num1 + num2;
        if (flag && !checkmax1 && ui->radioButtonMin->isChecked())
            num1 = num1 - num2;
        if (flag && !checkmax1 && ui->radioButtonUmno->isChecked())
            num1 = num1 * num2;
        if (flag && !checkmax1 && ui->radioButtonDel->isChecked())
        {
            if (s2 == "0")//проверка на 0
            {
                ui->label_res->setText("На 0 делить нельзя!");
                flag3 = 1;
            }

            else
                num1 = num1 / num2;
        }

         if (flag && flag2 && !flag3)//вывод без ошибок
         {
            checkmax1 = qIsInf(num1);
            checkmin1 = qIsInf(-num1);
            if (checkmax1 && num1 > 0)
            {
                ui->label_res->clear();
                ui->label_res->setText("Превышен лимит максимального значения");
            }
            if (checkmin1 && num1 < 0)
            {
                ui->label_res->clear();
                ui->label_res->setText("Превышен лимит минимального значения");
            }
            else
            {
                s1.clear();
                s1.append(QString::number(num1, 'f',2));
                ui->label_res->setText(s1);
            }
         }
    }
}

void MainWindow::on_radioButtonPlus_clicked()
{
    ui->labelO1->setText("Слагаемое 1");
    ui->labelO2->setText("Слагаемое 2");
    ui->lineEdit->setVisible(true);
    ui->label_res->clear();
    ui->label1->setText("+");
    ui->pushButton->setText("Результат суммы");
}

void MainWindow::on_radioButtonMin_clicked()
{
    ui->labelO1->setText("Вычитаемое");
    ui->labelO2->setText("Вычитатель");
    ui->lineEdit->setVisible(true);
    ui->label_res->clear();
    ui->label1->setText("-");
    ui->pushButton->setText("Результат разности");
}

void MainWindow::on_radioButtonUmno_clicked()
{
    ui->labelO1->setText("Множитель 1");
    ui->labelO2->setText("Множитель 2");
    ui->lineEdit->setVisible(true);
    ui->label_res->clear();
    ui->label1->setText("*");
    ui->pushButton->setText("Результат произведения");
}

void MainWindow::on_radioButtonDel_clicked()
{
    ui->labelO1->setText("Делимое");
    ui->labelO2->setText("Делитель");
    ui->lineEdit->setVisible(true);
    ui->label_res->clear();
    ui->label1->setText("/");
    ui->pushButton->setText("Результат деления");
}

void MainWindow::on_radioButtonKor_clicked()
{
    ui->labelO1->clear();
    ui->labelO2->setText("Подкоренное выражение");
    ui->label_res->clear();
    ui->label1->setText("Корень");
    ui->pushButton->setText("Результат квадратного корня");
    ui->lineEdit->setVisible(false);
}
