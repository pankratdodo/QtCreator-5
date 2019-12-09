#include <QCoreApplication>
#include <QTextStream>
#include <QTextCodec>
#include <iostream>
#include <QTextStream>
#include <signal.h>

using namespace std;

int check_count(int len)
{
    bool ok;
    int con;
    QString str2;
    QTextStream std(stdin);

    str2 = std.readLine();
    if ((str2.isEmpty()))
    {
        printf("Введите номер символа:\n");
        return (check_count(len));
    }
    con = str2.toInt(&ok);
    if (!ok || con > len || con < 0)
    {
        if (!ok)                                                    //если ввели не число, а фигню
            printf("Введите число, а не строку:\n");
        else if (con > len)                                         //если число больше, чем элементов в массиве
            printf("Введите число меньше:\n");
        else                                                        //если ввели отрицательное число
            printf("Введите положительное число:\n");
        return (check_count(len));
    }
    return (con);
}

void    my_int(int ret)
{
    printf("Не сломаешь!\n");
    ret = 0;
}

int main()
{
    int i, con, len;
    QString str1;
    QTextStream s(stdin);

    i = 0;
    con = 0;
                                                                       //ввод строки и символа
    printf("Введите строку:\n");
    signal(SIGTSTP, my_int);
    str1 = s.readLine();
    while (str1.isEmpty())
    {
        printf("Введите строку:\n");
        str1 = s.readLine();
    }
    len = str1.length();
    printf("Введите номер символа:\n");
    con = check_count(len);
    while (!(str1[i].isNull()))
    {
        if (i + 1 == con)                                             //если нашли совпадение
        {
            printf("Элемент #%i is %c\n", con, str1.toLocal8Bit().data()[i]);
            system("pause");
            return (0);
        }
        i++;
    }
    return (0);
}
