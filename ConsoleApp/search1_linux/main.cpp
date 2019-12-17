#include <iostream>
#include <stdio.h>
#include <signal.h>

using namespace std;

void    my_int2(int ret)
{
    printf("Не сломаешь!\n");
    printf("Введите номер символа:\n");
    ret = 0;
}

int check_count(int len)
{
    int con, i;
    string str;

    signal(SIGTSTP, my_int2);
    getline(cin, str);
    i = 0;
    if (!str.data()[i])
    {
        printf("Введите номер символа:\n");
        return (check_count(len));
    }
    con = atoi(str.data());
    if (!con || con > len || con < 0)
    {
        if (!con)                                                    //если ввели не число, а фигню
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
    printf("Введите строку:\n");
    ret = 0;
}

int main()
{
    int i, con;
    string str;

    i = 0;
    con = 0;                                                                  //ввод строки и символа
    signal(SIGTSTP, my_int);
    printf("Введите строку:\n");
    getline(cin, str);
    while (!str.data())
    {
        printf("Введите строку:\n");
        getline(cin, str);
    }
    while (str.data()[i])
        i++;
    printf("Введите номер символа:\n");
    con = check_count(i);
    i = 0;
    while (str.data()[i])
    {
        if (i + 1 == con)                                                 //если нашли совпадение
        {
            printf("Элемент #%i is %c\n", con, str.data()[i]);
            //system("pause");
            return (0);
        }
        i++;
    }
    return (0);
}
