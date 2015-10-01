#include <stdio.h>

/* исследование свойств символов и преобазование типов */
int main()
{
    int c;

    printf("введите символ: ");
    while ((c = getchar()) != EOF) {
        if (c == '\n') continue;    /*если выполнено условие, то след. итерация*/
        printf("вы ввели символ: ");
        printf("\nсимвол в виде целого числа: %d", c);
        printf("\nсимвол в виде double: %.2f", (double) c);
        /* спецификация %x выводит тип unsigned int без знака 0x */
        printf("\nсимвол в виде шестнадцатеричного числа: 0x%x", (unsigned int) c);
        printf("\nсимвол в виде восьмеричного числа: 0%o\n\n", (unsigned int) c);
        printf("введите символ: ");
   }
   return 0;
}
