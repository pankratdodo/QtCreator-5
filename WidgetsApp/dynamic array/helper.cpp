#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

void MainWindow::ArrayResize()//при изменении размера массива
{
    if (!Array)
    {
        Array = new int[ArrayLength];
        for (int i = 0; i < ArrayLength; i++)
            Array[i] = 0;
        return;
    }
    int *NewArray = new int[ArrayLength];
    int i = -1;
    while (++i < OldArrayLength && i < ArrayLength)
        NewArray[i] = Array[i];
    delete [] Array;
    Array = NewArray;
}

void MainWindow::FillTable()//проверка массива на пустоту
{
    for (int i = 0; i < ArrayLength; i++)
    {
         if (ui->_Table->item(0, i) == nullptr)
         {
             QMessageBox::warning(this, "Error", "Элементы массива должны быть числом");
             return ;
         }
         ui->_Table->item(0, i)->setText(QString::number(Array[i]));
    }
}

int MainWindow::arrayUnique(int *arr, int Elements)//тело удаления дубликатов
{
    int count = 1;
    int temp = arr[0];
    for ( int i = 1; i < Elements; i++)
    {
        if(arr[i] != temp)
        {
            for (int j = i + 1; j < Elements; j++)
                if (arr[i] == arr[j])
                {
                    arr[j] = temp;
                }
            count++;
        }
    }
    count = 0;
    for (int i = 1; i < Elements; i++)
    {
        if (arr[i] != arr[0])
            arr[++count] = arr[i];
    }
    return (++count);
}

int MainWindow::find_mid(int *arr, int min, int max, int i) //поиск среднего значения
{
        int avg_diff = INT_MAX;
        int ret;

        while (--i >= 0)
        {
            if (abs((int)((max + min) / 2) - arr[i]) < avg_diff)
            {
                avg_diff = abs((int)((max + min) / 2) - arr[i]);
                ret = arr[i];
            }
        }
        return (ret);
}

void MainWindow::on__Table_cellChanged(int row, int column)     //при изменении элемента массива
{
    bool isOk;

    if (is_ok)
        return ;
    col = column;
    ui->_Table->item(row, column)->text().toInt(&isOk);
    if (!isOk && !shut_up)
    {
        QMessageBox::warning(this, "Error", "Элемент должен быть числом");
        ui->_Table->item(row, column)->setText("0");
        return;
    }
    is_sorted = 0;
    ui->_findTable->clearContents();
    ui->_findTable->clear();
    ui->_findTable->setRowCount(0);
    ui->_findTable->setColumnCount(0);
    ui->_label_res->clear();
    if (!shut_up)
        Array[column] = ui->_Table->item(row, column)->text().toInt();
}
