#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <readline/readline.h>
#include <QTextStream>

using namespace std;

int ft_strchr(char *str, char c)//проверка строки
{
    int i;

    i = 0;
    while (str[i])
       i++ ;
    if (i > 1)//если символов больше 1
        return (0);
    if (str[0] == c)
        return (1);
    return (0);
}

void    my_int(int ret)
{
    printf("\nНе сломешь!");
    ret = 0;
}

double vvod()
{
    QString n;
    double num;
    QTextStream s(stdin);
    bool ok;
    while (true)
    {
        signal(SIGTSTP, my_int);
        printf("\nВведи число: ");
        n = s.readLine();
        num = n.toDouble(&ok);
        if (ok)
            break ;
        else
        {
            printf("\nЭто не число");
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
    return (num);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Russian");

    double n, m;
    char *str;
    QTextStream s(stdin);
    QString c;

    //ввод элементов
    printf("Привет, это мой калькулятор!\n");
    n = vvod();
    m = vvod();
    while (true)
    {
        signal(SIGTSTP, my_int);
        printf("\nВыбери операцию: \n+ \n- \n* \n/ \nнажми 's' если хочешь изменить числа\nнажми 'c' если хочешь очистить консоль\nнажми 'e' если хочешь выйти\n");
        c = s.readLine();
        if ((str = c.toLocal8Bit().data()))
        {
            if (ft_strchr(str, '+'))
                printf("\n%.5f + %.5f = %.5f\n\n", n, m, n + m);
            else if (ft_strchr(str, '-'))
                printf("\n%.5f - %.5f = %.5f\n\n", n, m, n - m);
            else if (ft_strchr(str, '*'))
                printf("\n%.5f * %.5f = %.5f\n\n", n, m, n * m);
            else if (ft_strchr(str, '/'))
                printf("\n%.5f / %.5f = %.5f\n\n", n, m, n / m);
            else if (ft_strchr(str, 's'))//поменять числа
            {
                n = vvod();
                m = vvod();
            }
            else if (ft_strchr(str, 'c'))//очистка экрана
                system("cls");
            else if (ft_strchr(str, 'e'))//выход из программы
            {
                printf("\nПокеда!\n");
                break ;
            }
            else//если ввели не операцию
                printf("\nЭто не операция\n\n");
        }
        else
            printf("\nЭто не операция\n\n");
     }
    system("pause");
    return (0);
}
