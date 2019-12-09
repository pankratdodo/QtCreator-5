#include <QCoreApplication>
#include <stdio.h>
#include <QTextStream>

char check_c(char *c)
{
    char count;

    if (c[1])
    {
        printf("Введите только один символ:\n");//если ввели много символов
        scanf("%s", c);
        return (check_c(c));
    }
    count = c[0];
    return (count);
}

char check_count()
{
    int len;
    char *con;
    QString str2;
    QTextStream std(stdin);

    str2 = std.readLine();
    if ((str2.isEmpty()))
    {
        printf("Введите символ для поиска:\n");
        return (check_count());
    }
    len = str2.length();
    con = str2.toLocal8Bit().data();
    if (len > 1)
    {
        printf("Введите символ, а не строку:\n");
        return (check_count());
    }
    return (con[0]);
}

void    my_int(int ret)
{
    printf("Не сломаешь!\n");
    ret = 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char c;
    int i;
    bool flag;
    QString str1;
    QTextStream s(stdin);

    i = 0;
    flag = 0;
    printf("Введите строку:\n");
    signal(SIGTSTP, my_int);
    str1 = s.readLine();
    while (str1.isEmpty())
    {
        printf("Введите строку:\n");
        str1 = s.readLine();
    }
    printf("Введите символ для поиска:\n");                            //ввод символа для поиска
    c = check_count();                                                 //проверка на корректность символа
    while (!(str1[i].isNull()))
    {
        if (c == str1.toLocal8Bit().data()[i])                         //если нашли совпадение
        {
            printf("Символ %c находится под номером %d\n", c, i + 1);
            flag = 1;
        }
        i++;
    }
    if (!flag)                                                         //если такого символа нет
        printf("Символа в строке нет\n");
    system("pause");
    return (0);
}
