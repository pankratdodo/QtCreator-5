#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void    ArrayResize();
    void    FillTable();
    int     partition(int *a,int start,int end);
    void    CombSort(int *a, int n);
    void    Quicksort(int *a,int start,int end);
    void    BubbleSort(int *arr, int Elements, bool order);
    int     arrayUnique(int *arr, int Elements);
    int     find_mid(int *arr, int min, int max, int i);
    ~MainWindow();

private slots:
    void on__CreateButton_clicked();

    void on__Table_cellChanged(int row, int column);

    void on__RandomButton_clicked();

    void on__qSortButton_clicked();

    void on__CombSortButton_clicked();

    void on__sortRulePlus_clicked();

    void on__SortRuleMinus_clicked();

    void on__BubbleSortButton_clicked();

    void on__ClearButton_clicked();

    void on__DuplicatesButton_clicked();

    void on__FindMinMidMaxButton_clicked();

    void on__find_Btn_clicked();

private:
    Ui::MainWindow *ui;
    bool    shut_up = false;
    bool    ascending_order = true;
    bool    is_sorted = false;
    int     OldArrayLength = 0;
    int     ArrayLength = 0;
    int     *Array = nullptr;
    int     col;
    bool    MesQSort = false;
    bool    random = false;
    bool    is_ok = false;
};
#endif // MAINWINDOW_H
