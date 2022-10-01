#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");

    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    double s = 0, sp = 0, so = 0, snch = 0, sch = 0, p = 1;
    int max = -100000000000, min = 100000000000, maxi = 0, mini = 0, st = mini, f = maxi;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
        if (mas[i] > 0) sp += mas[i];
        else so += mas[i];
        if (i % 2 == 0) sch += mas[i];
        else snch += mas[i];

        if (mas[i] > max) { max = mas[i]; maxi = i; }
        if (mas[i] < min) { min = mas[i]; mini = i; }
    }

    double avrg = s / 10;

    if (mini > maxi) { st = maxi; f = mini; }

    for (int i = st; i <= f; i++) p = p * mas[i];

    cout << "Сумма: " << s << endl << "Среднее значение элементов: " << avrg << endl << "Сумма отрицательных элементов: " << so << ", сумма положительных элементов: " << sp << endl << "Сумма элементов с нечет. индексами: " << snch << ", сумма элементов с чет. индексами: " << sch << endl;
    cout << "Макс. элемент: " << max << ", мин. элемент: " << min << ", произведение элементов между ними: " << p;

}
