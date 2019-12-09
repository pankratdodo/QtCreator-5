#include "mainwindow.h"
#include "ui_mainwindow.h"

int    vivod_res(int ind1, int ind2, int oper)
{
    if (oper == 0)
    {
        if (ind1 == 0 || ind2 == 0)
            return (0);
        if (ind1 == 1 && ind2 == 1)
            return (1);
    }
    if (oper == 1)
    {
        if (ind1 == 1 || ind2 == 1)
            return (1);
        else
            return (0);
    }
    if (oper == 2)
    {
        if (ind2 == 0)
            return (1);
        else
            return (0);
    }
    if (oper == 3)
    {
        if (ind1 == 1 && ind2 == 0)
            return (0);
        else
            return (1);
    }
    if (oper == 4)
    {
        if (ind1 == ind2)
            return (1);
        else
            return (0);
    }
    return (0);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxNum1->addItem("False");
    ui->comboBoxNum1->addItem("True");
    ui->comboBoxNum2->addItem("False");
    ui->comboBoxNum2->addItem("True");
    ui->comboBoxOper->addItem("Конъюнкция");
    ui->comboBoxOper->addItem("Дизъюнкция");
    ui->comboBoxOper->addItem("Инверсия");
    ui->comboBoxOper->addItem("Импликация");
    ui->comboBoxOper->addItem("Эквивалентность");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBoxNum1_activated(int index)
{
    int oper;
    int n2;
    int res;
    QPalette m;

    ui->comboBoxNum1->setVisible(true);
    ui->labelO1->setText("Значение первой переменной");
    ui->labelO2->setText("Значение второй переменной");
    n2 = ui->comboBoxNum2->currentIndex();
    oper = ui->comboBoxOper->currentIndex();
    if (oper == 2)
    {
        ui->comboBoxNum1->setVisible(false);
        ui->labelO1->clear();
        ui->labelO2->setText("Значение переменной");
    }
    res = vivod_res(index, n2, oper);
    if (res == 0)
    {
        m.setColor(QPalette::Window, Qt::red);
        this->setPalette(m);
    }
    else
    {
        m.setColor(QPalette::Window, Qt::green);
        this->setPalette(m);
    }
}

void MainWindow::on_comboBoxOper_currentIndexChanged(int index)
{
    int n1;
    int n2;
    int res;
    QString s1;
    QPalette m;

    ui->comboBoxNum1->setVisible(true);
    ui->labelO1->setText("Значение первой переменной");
    ui->labelO2->setText("Значение второй переменной");
    if (index == 2)
    {
        ui->labelO1->clear();
        ui->labelO2->setText("Значение переменной");
        ui->comboBoxNum1->setVisible(false);
        n1 = 5;
    }
    n2 = ui->comboBoxNum2->currentIndex();
    n1 = ui->comboBoxNum1->currentIndex();
    res = vivod_res(n1, n2, index);
    if (res == 0)
    {
        m.setColor(QPalette::Window, Qt::red);
        this->setPalette(m);
    }
    else
        m.setColor(QPalette::Window, Qt::green);
        this->setPalette(m);
}

void MainWindow::on_comboBoxNum2_currentIndexChanged(int index)
{
    int oper;
    int n1;
    int res;
    QString s1;
    QPalette m;

    ui->comboBoxNum1->setVisible(true);
    ui->labelO1->setText("Значение первой переменной");
    ui->labelO2->setText("Значение второй переменной");
    n1 = ui->comboBoxNum1->currentIndex();
    oper = ui->comboBoxOper->currentIndex();
    if (oper == 2)
    {
        ui->comboBoxNum1->setVisible(false);
        ui->labelO1->clear();
        ui->labelO2->setText("Значение переменной");
    }
    res = vivod_res(n1, index, oper);
    if (res == 0)
    {
        m.setColor(QPalette::Window, Qt::red);
        this->setPalette(m);
    }
    else
        m.setColor(QPalette::Window, Qt::green);
        this->setPalette(m);
}
