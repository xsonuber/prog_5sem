#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");

    ofstream out("array", ios::out | ios::binary);
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    out << "Исходный массив: ";
    for (int i : a) out << i << " "; 

    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    out << "\nОтсортированный массив: ";
    for (int i : a) out << i << " "; 

    out.close();

    ifstream in("array", ios::in | ios::binary);
    if (!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }

    cout << "Файл: \n";
    string reading;
    if (in.is_open())
    {
        while (getline(in, reading))
        {
            cout << reading << '\n';
        }
    }

    in.close();
    return 0;
}
