#include <stdio.h>

/*
    Копирование входного потока в выходной
    Пример использования: echo "This is a text." | ./a.out
    Или так: ./a.out < text.txt
*/

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
    return 0;
}
