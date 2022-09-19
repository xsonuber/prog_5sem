#include <iostream>
#include <string>
using namespace std;

bool snilscheck(string snils)
{
    string newsnils;
    for (int i = 0; i < snils.length(); i++) // проверяем на пробелы, дефисы, другие символы и переводим в нормальный номер длинной 11
    {
        if (snils[i] != '-' && snils[i] != ' ' && snils[i] != '0' && snils[i] != '1' && snils[i] != '2' && snils[i] != '3' && snils[i] != '4' && snils[i] != '5' && snils[i] != '6' && snils[i] != '7' && snils[i] != '8' && snils[i] != '9')
        { 
            return false; 
        }
        else if (snils[i] == '0' || snils[i] == '1' || snils[i] == '2' || snils[i] == '3' || snils[i] == '4' || snils[i] == '5' || snils[i] == '6' || snils[i] == '7' || snils[i] == '8' || snils[i] == '9')
        {
            newsnils = newsnils + snils[i];
        }
    }

    if (newsnils.length() != 11) { return false; } // проверка на длину СНИЛС, если не равно 11, то программа завершается

    for (int i = 2; i < newsnils.length() - 2; i++) { if (newsnils[i] == newsnils[i - 1] && newsnils[i] == newsnils[i - 2]) { return false; } } // проверяется, есть ли в введенном СНИЛС более 2-ух повторяющихся цифр; если есть, программа завершается

    int sum = 0;
    int snilsi = 0;
    string symb = "a";
    for (int i = newsnils.length() - 2; i >= 0; i--) // цикл считает сумму по правилу из задания; сначала отделяем цифру, потом переводим ее в int, после чего учитываем в сумме
    {
        symb = newsnils[i];
        snilsi = stoi(symb);
        sum = sum + (9 - i) * snilsi;
    }

    string sumstr = to_string(sum); // строковый вариант найденной суммы

    if (sum == 100 || sum == 101) sumstr = "00"; // условие, если контрольное значение равно 100 или 101
    else if (sum > 101 && sum % 101 < 100) sumstr = to_string(sum % 101); // условие, если контрольное значение больше 101 и остаток от деления на 101 меньше 100
    else if (sum > 101 && sum % 101 == 100) sumstr = "00"; // условие, если контрольное значение больше 101 и остаток от деления на 101 равен 100

    string kr = newsnils.substr(newsnils.length() - 2, 2); // отделяем последние две цифры от введенного СНИЛСа, так как это контрольное значение, которое нужно потом сравнить с найденным в программе контрольным значением

    if (sumstr == kr) return true; // сравниваем введенное и найденное контрольные значения
    return false;
}

int main()
{
    system("chcp 1251");

    string snils;
    cout << "Введите СНИЛС: "; getline(cin, snils);

    bool result = snilscheck(snils);
    if (result == 1) cout << "True";
    else cout << "False";
}