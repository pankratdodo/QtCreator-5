#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <limits.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->_BubbleSortButton->setEnabled(false);
    ui->_qSortButton->setEnabled(false);
    ui->_CombSortButton->setEnabled(false);
    ui->_ClearButton->setEnabled(false);
    ui->_FindMinMidMaxButton->setEnabled(false);
    ui->_DuplicatesButton->setEnabled(false);
    ui->_find_Btn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on__BubbleSortButton_clicked()
{
    shut_up = true;
    BubbleSort(Array, ArrayLength, ascending_order);
    FillTable();
    is_sorted = true;
    shut_up = false;
}

void MainWindow::on__CreateButton_clicked()
{
    bool isOk;
                                                                                //создание массива в таблице
    OldArrayLength = ArrayLength;
    ArrayLength = ui->_ArrLen->text().toInt(&isOk);
    if (!ArrayLength)
    {
        QMessageBox::warning(this, "Error", "Длинна массива может быть значением от 1 до 10000");
        return;
    }
    ui->_Table->setRowCount(1);
    if (ArrayLength == OldArrayLength)
        return ;
    if (!isOk || ArrayLength <= 0 || ArrayLength > 10000)
    {
        QMessageBox::warning(this, "Error", "Длинна массива может быть значением от 1 до 10000");
        return;
    }
    is_sorted = false;
    ui->_Table->setColumnCount(ArrayLength);
    ArrayResize();
    ui->_BubbleSortButton->setEnabled(true);
    ui->_qSortButton->setEnabled(true);
    ui->_CombSortButton->setEnabled(true);
    ui->_ClearButton->setEnabled(true);
    ui->_RandomButton->setEnabled(true);
    ui->_FindMinMidMaxButton->setEnabled(true);
    ui->_DuplicatesButton->setEnabled(true);
    ui->_find_Btn->setEnabled(true);
}

void MainWindow::on__RandomButton_clicked()                                     //рандомное заполнение массива
{
    QTableWidgetItem *itm;

    shut_up = true;
    random = true;
    is_ok = true;
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = rand();
        if (ui->_Table->item(0, i) == nullptr)
        {
            itm = new QTableWidgetItem();
            ui->_Table->setItem(0, i, itm);
        }
        ui->_Table->item(0, i)->setText(QString::number(Array[i]));
    }
    is_sorted = false;
    shut_up = false;
    is_ok = false;
    ui->_MaxText->clear();
    ui->_MinText->clear();
    ui->_MidText->clear();
}

void MainWindow::on__qSortButton_clicked()
{
    shut_up = true;
    is_ok = true;

    Quicksort(Array, 0, ArrayLength - 1);
    FillTable();
    is_sorted = true;
    is_ok = false;
    shut_up = false;
}

void MainWindow::on__CombSortButton_clicked()
{
    shut_up = true;
    is_ok = true;

    CombSort(Array, ArrayLength);
    FillTable();
    is_sorted = true;
    is_ok = false;
    shut_up = false;
}

void MainWindow::on__sortRulePlus_clicked()
{
    ascending_order = true;
}

void MainWindow::on__SortRuleMinus_clicked()
{
    ascending_order = false;
}

void MainWindow::on__ClearButton_clicked()                                      //очистка
{
    QMessageBox::StandardButton replay;

    replay = QMessageBox::question(this, "Очистка", "Уверены, что хотите очистить все?", QMessageBox::Yes|QMessageBox::No);
    if (replay == QMessageBox::Yes)
    {
    is_sorted = false;
    random = false;
    is_ok = false;
    ui->_RandomButton->setEnabled(false);
    ui->_MaxText->clear();
    ui->_MidText->clear();
    ui->_MinText->clear();
    ArrayLength = 0;
    ui->_Table->clearContents();
    ui->_Table->clear();
    ui->_Table->setRowCount(0);
    ui->_Table->setColumnCount(0);
    ArrayResize();
    ui->_ArrLen->clear();
    ui->_BubbleSortButton->setEnabled(false);
    ui->_qSortButton->setEnabled(false);
    ui->_CombSortButton->setEnabled(false);
    ui->_ClearButton->setEnabled(false);
    ui->_FindMinMidMaxButton->setEnabled(false);
    ui->_DuplicatesButton->setEnabled(false);
    ui->_find_Btn->setEnabled(false);
    ui->_findTable->clearContents();
    ui->_findTable->clear();
    ui->_findTable->setRowCount(0);
    ui->_findTable->setColumnCount(0);
    ArrayResize();
    ui->_find_Field->clear();
    ui->_label_res->clear();
    }
    else
        return;
}

void MainWindow::on__DuplicatesButton_clicked()                                  //дубликаты
{
    shut_up = true;
    is_ok = true;
    if (!is_sorted)
    {
        QMessageBox::warning(this, "Error", "Осортируйте массив");
        return;
    }
    ArrayLength = arrayUnique(Array, ArrayLength);
    ui->_Table->setColumnCount(ArrayLength);
    FillTable();
    ui->_findTable->clearContents();
    ui->_findTable->clear();
    ui->_findTable->setRowCount(0);
    ui->_findTable->setColumnCount(0);
    ui->_label_res->clear();
    shut_up = false;
    is_ok = false;
}

void MainWindow::on__FindMinMidMaxButton_clicked()                                  //поиск минимума и максимума
{
    int min = INT_MAX;
    int max = INT_MIN;
    int avg = INT_MAX;
    int i = 1;

    while(i < ArrayLength)
    {
        if (ui->_Table->item(0, i) == nullptr)
        {
            QMessageBox::warning(this, "Error","Есть пустые элементы");
            return ;
        }
        i++;
    }
    if (ArrayLength == 0)
        return;
    if (ArrayLength == 1)
    {
        ui->_MaxText->setText(QString::number(Array[0]));
        ui->_MidText->setText(QString::number(Array[0]));
        ui->_MinText->setText(QString::number(Array[0]));
        return ;
    }
    if (ArrayLength == 2)
    {
        int min;
        int max;

        if (Array[0] < Array[1])
        {
            min = Array[0];
            max = Array[1];
        }
        else
        {
            min = Array[1];
            max = Array[0];
        }
        ui->_MaxText->setText(QString::number(max));
        ui->_MidText->setText(QString::number(max));
        ui->_MinText->setText(QString::number(min));
        return;
    }
    if (is_sorted)
    {
        if (ascending_order)
        {
            min = Array[0];
            max = Array[ArrayLength - 1];
        }
        else
        {
            max = Array[0];
            min = Array[ArrayLength - 1];
        }
    }
    else
        for (int i = 0; i < ArrayLength; i++)
        {
            if (Array[i] < min)
                min = Array[i];
            if (Array[i] > max)
                max = Array[i];
        }
    avg = find_mid(Array, min, max, ArrayLength);
    ui->_MaxText->setText(QString::number(max));
    ui->_MidText->setText(QString::number(avg));
    ui->_MinText->setText(QString::number(min));
}


void MainWindow::on__find_Btn_clicked()                                                     //поиск числа
{
    bool flag;
    QTableWidgetItem *itm;
    int i = 1;

    ui->_findTable->clearContents();
    ui->_findTable->clear();
    ui->_findTable->setRowCount(0);
    ui->_findTable->setColumnCount(0);
    ui->_find_Field->text().toInt(&flag, 10);
    if (!flag)
    {
        QMessageBox::warning(this, "Error", "Найти можно только число");
        return ;
    }
    while(i < ArrayLength)
    {
        if (ui->_Table->item(0, i) == nullptr)
        {
            QMessageBox::warning(this, "Error","Есть пустые элементы");
            return ;
        }
        i++;
    }
    int *tempArr = new int[ArrayLength];
    int count = 0;
    if (is_sorted)
    {
        int last_found = 0, mid = 0, tmp1 = 0, tmp2 = ArrayLength - 1;
        while (tmp1 <= tmp2)
        {
            mid = (tmp1 + tmp2)/2;
            if (Array[mid] == ui->_find_Field->text().toInt())
            {
                for (int i = tmp1; i <= tmp2; i++)
                {
                    if(Array[i] == ui->_find_Field->text().toInt())
                    {
                        last_found = i;
                        tempArr[count] = last_found + 1;
                        count++;
                    }
                }
                break;
            }
            else
            {
                if (Array[mid] > ui->_find_Field->text().toInt())
                    tmp2 = mid - 1;
                else
                    tmp1 = mid + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < ArrayLength; i++)
        {
            if (Array[i] == ui->_find_Field->text().toInt())
            {
                tempArr[count] = i + 1;
                count++;
            }
        }
    }
    if (count != 0)
    {
        ui->_label_res->setText(QString(tr("Найдено элементов: %1").arg(count)));
        ui->_findTable->setRowCount(1);
        ui->_findTable->setColumnCount(count);
        ui->_findTable->horizontalHeader()->hide();
        ui->_findTable->verticalHeader()->hide();
        for (int i = 0; i < count; i++)
        {

            if (ui->_findTable->item(0, i) == nullptr)
            {
                ui->_findTable->setColumnWidth(i, 30);
                itm = new QTableWidgetItem(tr("%1").arg(tempArr[i]));
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
                ui->_findTable->setItem(0, i, itm);

            }
            else
                ui->_findTable->item(0, i)->setText(tr("%1").arg(tempArr[i]));
        }
    }
    else
        ui->_label_res->setText("Элементов не найдено");
    delete [] tempArr;
}
