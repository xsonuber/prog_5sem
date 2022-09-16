#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");

    string snils;
    cout << "Введите СНИЛС: "; cin >> snils;

    if (snils.length() != 11) { cout << "False"; return 0; } // проверка на длину СНИЛС, если не равно 11, то программа завершается

    for (int i = 2; i < 9; i++) { if (snils[i] == snils[i - 1] && snils[i] == snils[i - 2]) { cout << "False"; return 0; } } // проверяется, есть ли в введенном СНИЛС более 2-ух повторяющихся цифр; если есть, программа завершается

    int sum = 0;
    int snilsi = 0;
    string symb = "a";
    for (int i = 8; i >= 0; i--) // цикл считает сумму по правилу из задания; сначала отделяем цифру, потом переводим ее в int, после чего учитываем в сумме
    {
        symb = snils[i];
        snilsi = stoi(symb);
        sum = sum + (9 - i) * snilsi;
    }

    string sumstr = to_string(sum); // строковый вариант найденной суммы

    if (sum == 100 || sum == 101) sumstr = "00"; // условие, если контрольное значение равно 100 или 101
    else if (sum > 101 && sum % 101 < 100) sumstr = to_string(sum % 101); // условие, если контрольное значение больше 101 и остаток от деления на 101 меньше 100
    else if (sum > 101 && sum % 101 == 100) sumstr = "00"; // условие, если контрольное значение больше 101 и остаток от деления на 101 равен 100

    string kr = snils.substr(snils.length() - 2, 2); // отделяем последние две цифры от введенного СНИЛСа, так как это контрольное значение, которое нужно потом сравнить с найденным в программе контрольным значением

    if (sumstr == kr) cout << "True"; // сравниваем введенное и найденное контрольные значения
    else cout << "False";
    return 0;
}