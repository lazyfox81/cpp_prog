#include <iostream>
using std::cout;
using std::endl;

// побитовые операции
int main()
{
    unsigned char var = 153;            //двоичная запись 10011001
    unsigned char not_var = ~var;       //результат 01100110 (число 102)  побитовое отрицание
    cout << int(var) << '\t' << int(not_var) << '\n';

    unsigned char mask = 0x11;          // число 00010001 (число 17)
    unsigned char res_1 = var & mask;   // результат 00010001 побитовое И
    unsigned char res_2 = var | mask;   // результат 10011001 побитовое ИЛИ
    unsigned char res_3 = var ^ mask;   // результат 10001000 побитовое исключающее ИЛИ
                                        //'0' если оба операнда равны '0' или '1'
    cout << int(var) << '\t' << int(res_1) << '\n';
    cout << int(var) << '\t' << int(res_2) << '\n';
    cout << int(var) << '\t' << int(res_3) << '\n';

    unsigned char flag = 3; // 00000011
    mask = 1; // 00000001
    if((flag & mask) == 1) cout << "Нулевой бит включен" << endl;
    else cout << "Нулевой бит выключен" << endl;

    flag = 4; // 00000100
    mask = 2; // 00000010
    flag |= mask; // включение первого бита (нумерация с хвоста и с нуля)
    cout << int(mask) << '\t' << int(flag) << '\n';

    flag = 3;//00000011
    mask = 2;//00000010
    flag &= ~mask;// отключение первого бита
    cout << int(mask) << '\t' << int(flag) << '\n';

    var = 1;
    var = var <<1; //00000010 – значение 2 побитовый сдвиг влево новый бит равен нулю
    cout << int(var) << endl;
    var <<= 1; //00000100 – значение 4
    cout << int(var) << endl;

    var = 1;
    var<<=3; //2^3=8
    cout << int(var) << endl;

    var = 128; //1000000
    var = var >> 1; //0100000 – значение 64; побитовый сдвиг вправо
    cout << int(var) << endl;
    var >>= 1; //0010000 – значение 32
    cout << int(var) << endl;
    return 0;
}

