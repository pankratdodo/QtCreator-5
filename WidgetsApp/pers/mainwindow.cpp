#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

static QString name;
static QString result;
static int power = 0;
static int lovk = 0;
static int mind = 0;
static int luck = 0;
static int life = 0;
static int mana = 0;
static int atack = 0;
static int protect = 0;
static int res = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    res = 20;
    ui->lineEditRes->setText("20");
    ui->lineEditPow->setValidator(new QIntValidator(0, 10, this));
    ui->lineEditMind->setValidator(new QIntValidator(0, 10, this));
    ui->lineEditLovk->setValidator(new QIntValidator(0, 10, this));
    ui->lineEditLuck->setValidator(new QIntValidator(0, 10, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Vivod(QString a)
{
    if (lovk && mind && luck && power && res == 0)
    {
        life = (8 * power + 2 * luck) / 10;
        a = QString::number(life);
        ui->lineEditLife->setText(a);
        mana = (8 * mind + lovk / 2 + 8 * luck / 2) / 10;
        a = QString::number(mana);
        ui->lineEditMana->setText(a);
        atack = (5 * power + 2 * lovk + 3 * luck) / 10;
        a = QString::number(atack);
        ui->lineEditAtack->setText(a);
        protect = (7 * power + 2 * lovk / 2 + luck / 2) / 10;
        a = QString::number(protect);
        ui->lineEditProtect->setText(a);
    }
}

void MainWindow::ochistka()
{
    ui->lineEditLife->clear();
    ui->lineEditMana->clear();
    ui->lineEditAtack->clear();
    ui->lineEditProtect->clear();
    mana = 0;
    atack = 0;
    protect = 0;
    life = 0;
}

void MainWindow::on_lineEditName_textEdited(const QString &arg1)
{
    ui->labelName->setStyleSheet(QString("color:#030303;"));
    name.clear();
    name.append(ui->lineEditName->text());
    if (name.length() == 0)
             ui->labelName->setStyleSheet(QString("color:#030303;"));
    else if (name.length() > 20 || name.length() < 3)
        ui->labelName->setStyleSheet(QString("color:#eb4034;"));
    ui->lineEditName->setTabOrder(ui->lineEditName, ui->lineEditPow);
}

void MainWindow::on_pushButtonRes_clicked()
{
    QString lifee;
    QString manaa;
    QString attack;
    QString protectt;
    char buf[2];

    if (name == nullptr || name.length() < 3)
    {
        QMessageBox::critical(this, "Error", "Введите имя длиннее");
        ui->labelName->setStyleSheet(QString("color:#eb4034;"));
        return ;
    }
    else if (name.length() > 20)
    {
        QMessageBox::critical(this, "Error", "Введите имя короче");
        ui->labelName->setStyleSheet(QString("color:#eb4034;"));
        return ;
    }
    if (res > 0)
    {
        QMessageBox::critical(this, "Error", "Очки характеристик не израсходованы");
        return ;
    }
    if (res < 0)
    {
        QMessageBox::critical(this, "Error", "Очки характеристик должны быть равны 0");
        return ;
    }
    if (!life || !mana || !atack || !protect)
    {
        QMessageBox::critical(this, "Error", "Введите характеристики");
        return ;
    }
    lifee = QString::number(life);
    manaa = QString::number(mana);
    attack = QString::number(atack);
    protectt = QString::number(protect);
    if (lovk >= 8 && power >= 8 && (mind >= 1 || luck >= 1))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Ловкий войн по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Ловкая воительница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (mind >= 8 && power >= 8)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Умный войн по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Умная воительница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (luck >= 8 && power >= 8 && mind >= 1 && mind < 4)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Везучий войн по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Везучая воительница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if ((lovk == 10 && mind == 10) ||(lovk >= 8 && mind >= 8 && power == 4) || (lovk >= 8 && mind >= 8 && luck == 4))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Проворный маг по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Проворная волшебница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (power > 7 && luck > 7)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Живучий войн по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Живучая воительница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (lovk >= 8 && luck >= 8)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Талантливый разбойник по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Талантливая разбойница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (luck >= 7 && mind >= 6)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Талантливый маг по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Талантливая Волшебница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (lovk == 5 && mind == 5 && luck == 5 && power == 5)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Монах с идеальными характеристиками по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Монахия с идеальными характеристиками по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (lovk >= 5 && power >= 5 && (mind >= 3 || luck >= 3))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Отшельник по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Отшельница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (luck > mind && lovk >= 3 && power >= 3)
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Везучий отшельник по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Везучая отшельница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (mind >= 6 && mind > power && mind > lovk && mind > luck && (lovk >= 3 || power >= 3))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Маг по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Волшебница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (luck >= 6 && luck > power && luck > mind && luck > lovk && (mind >= 3 || power >= 3))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Везучий аферист по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Везучая аферистка по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (power >= 6 && power > luck && power > mind && power > lovk && (mind >= 3 || luck >= 3))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Воитель по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Воительница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else if (lovk >= 6 && lovk > luck && lovk > mind && lovk > power && (mind >=3 || luck >= 3))
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Везучий разбойник по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Везучая разбойница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
    else
    {
        if (ui->radioButtonMale->isChecked())
            QMessageBox::information(this, "Result", "Гибкий маг по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
        else
             QMessageBox::information(this, "Result", "Гибкая волшебница по имени " + name + "\nЖизнь - " + itoa(life, buf ,10) + "\nМана - " + itoa(mana, buf, 10) + "\nЗащита - " + itoa(protect, buf, 10) + "\nАтака - " + itoa(atack, buf, 10));
    }
}

void MainWindow::on_lineEditPow_textEdited(const QString &arg1)
{
    bool ok;

    ochistka();
    ui->labelPower->setStyleSheet(QString("color:#030303;"));
    power = 0;
    QValidator *validator = new QIntValidator(1, 10, this);
    QLineEdit *edit = new QLineEdit(this);
    result = QString::number(res);
    edit->setValidator(validator);
    ui->lineEditRes->setText(result);
    power = arg1.toInt(&ok, 10);
    res = 20 - (power + lovk + mind + luck);
    if (res < 0 || (power && lovk && mind && luck && res != 0))
        ui->labelRes->setStyleSheet(QString("color:#eb4034;"));
    else
        ui->labelRes->setStyleSheet(QString("color:#030303;"));
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    Vivod(arg1);
}

void MainWindow::on_lineEditLovk_textEdited(const QString &arg1)
{
    bool ok;

    ochistka();
    ui->labelLovk->setStyleSheet(QString("color:#030303;"));
    lovk = 0;
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    lovk = arg1.toInt(&ok, 10);
    res = 20 - (power + lovk + mind + luck);
    if (res < 0 || (power && lovk && mind && luck && res != 0))
        ui->labelRes->setStyleSheet(QString("color:#eb4034;"));
    else
        ui->labelRes->setStyleSheet(QString("color:#030303;"));
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    ui->lineEditLovk->setTabOrder(ui->lineEditLovk, ui->lineEditMind);
     Vivod(arg1);
}

void MainWindow::on_lineEditMind_textEdited(const QString &arg1)
{
    bool ok;

    ochistka();
    ui->labelRes->setStyleSheet(QString("color:#030303;"));
    mind = 0;
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    mind = arg1.toInt(&ok, 10);
    res = 20 - (power + lovk + mind + luck);
    if (res < 0 || (power && lovk && mind && luck && res != 0))
        ui->labelRes->setStyleSheet(QString("color:#eb4034;"));
    else
        ui->labelRes->setStyleSheet(QString("color:#030303;"));
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    ui->lineEditMind->setTabOrder(ui->lineEditMind, ui->lineEditLuck);
    Vivod(arg1);
}

void MainWindow::on_lineEditLuck_textEdited(const QString &arg1)
{
    bool ok;

    ochistka();
    ui->labelLuck->setStyleSheet(QString("color:#030303;"));
    luck = 0;
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    luck = arg1.toInt(&ok, 10);
    res = 20 - (power + lovk + mind + luck);
    if (res < 0 || (power && lovk && mind && luck && res != 0))
        ui->labelRes->setStyleSheet(QString("color:#eb4034;"));
    else
        ui->labelRes->setStyleSheet(QString("color:#030303;"));
    result = QString::number(res);
    ui->lineEditRes->setText(result);
    ui->lineEditLuck->setTabOrder(ui->lineEditLuck, ui->lineEditName);
    Vivod(arg1);
}
