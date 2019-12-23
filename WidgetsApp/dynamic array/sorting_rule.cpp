#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//быстрая сортировка

int MainWindow::partition(int *a,int start,int end)//тело быстрой сортировки
{
    int pivot=a[end];
    int P_index=start;
    int i,t;

    for(i = start; i < end; i++)
    {
        if (i == 7000 && MesQSort == false )
        {
            MesQSort = true;
            if ((QMessageBox::question(this, "Долгаа", "Работает очень долго, уверены, что хотите продолжить?", QMessageBox::Yes|QMessageBox::No)) == QMessageBox::No)
                return(0);
        }
        if (ascending_order)
        {
            if(a[i] <= pivot)
            {
                t = a[i];
                a[i] = a[P_index];
                a[P_index] = t;
                P_index++;
            }
        }
        else
            if(a[i] > pivot)
            {
                t = a[i];
                a[i] = a[P_index];
                a[P_index] = t;
                P_index++;
            }
     }
      t = a[end];
      a[end] = a[P_index];
      a[P_index] = t;

     return P_index;
}

void MainWindow::Quicksort(int *a,int start,int end)
{
    if(start < end)
    {
         int P_index = partition(a, start, end);
         Quicksort(a,start,P_index-1);
         Quicksort(a,P_index+1,end);
    }
}

//сортировка расчесткой

int getNextGap(int gap)//вспомогательная функция для расчетски
{

    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void swap(int *i, int *j)//меняем значения местами
{
    int t = *i;
    *i = *j;
    *j = t;
}

void MainWindow::CombSort(int *a, int n)
{
    int gap = n;
    bool swapped = true;
    bool mes = false;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (i == 7000 && mes == false )
            {
                mes = true;
                if ((QMessageBox::question(this, "Долгаа", "Работает очень долго, уверены, что хотите продолжить?", QMessageBox::Yes|QMessageBox::No)) == QMessageBox::No)
                    return;
            }
            if (ascending_order)//по возрастанию
            {
                if (a[i] > a[i + gap])
                {
                    swap(&a[i], &a[i + gap]);
                    swapped = true;
                }
            }
            else//по убыванию
                if (a[i] <= a[i + gap])
                {
                    swap(&a[i], &a[i + gap]);
                    swapped = true;
                }
        }
    }
}

//сортировка пузырьком

void MainWindow::BubbleSort(int *arr, int Elements, bool order)//тело сортировки пузырьком
{
    int temp;
    bool mes = false;

    for (int i = 0; i < Elements - 1; i++)
        for (int j = 0; j < Elements - i - 1; j++)
        {
            if (i == 7000 && mes == false )
            {
                mes = true;
                if ((QMessageBox::question(this, "Долгаа", "Работает очень долго, уверены, что хотите продолжить?", QMessageBox::Yes|QMessageBox::No)) == QMessageBox::No)
                    return;
            }
            if (order)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else if (arr[j] <= arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}
