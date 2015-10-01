#include <stdio.h>
#include <math.h>

long power(int base, int pow);
long binary(int num);

/*программа переводит десятичные числа в двоичные */
int main()
{
    int a;
    long c;

    scanf("%d",&a);
    c = binary(a);
    printf("%d\t%ld\n", a, c);
    return 0;
}

/* binary: преобразовывает десятичные числа в двоичные */
long binary(int num)
{
    int i, b;
    long c = 0;
    for (i = 0; num > 0; i++)
    {
        b = num % 2;                    /* остаток от деления на 2; либо 1, либо 0 */
        printf("%d\t%d\t", b, num);
        num = (num-b)/2;                /* целая часть деления на 2 */
        c += b * power(10, i);           /* заполняем сначала младший бит, а потом старшие */
        /* printf("%d\t%ld\n", num, c); */
    }
    return c;
}

/* power: возводит base в степень pow для int */
long power(int base, int pow)
{
    long p;

    for (p = 1; pow > 0; --pow)
        p *= base;
    return p;
}
