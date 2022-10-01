#include <iostream>
using namespace std;

double sum(int, int[]);
double avrg(int, int[]);
double sump(int, int[]);
double sumo(int, int[]);
double sumch(int, int[]);
double sumnch(int, int[]);
double max(int, int[]);
double maxi(int, int[]);
double min(int, int[]);
double mini(int, int[]);
double p(int, int[]);

int main()
{
    system("chcp 1251");

    double n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* mas = new int[n]; // динамический массив

    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    cout << "Сумма: " << sum(n, mas) << endl << "Среднее значение элементов: " << avrg(n, mas) << endl << "Сумма отрицательных элементов: " << sumo(n, mas) << ", сумма положительных элементов: " << sump(n, mas) << endl << "Сумма элементов с нечет. индексами: " << sumnch(n, mas) << ", сумма элементов с чет. индексами: " << sumch(n, mas) << endl;
    cout << "Макс. элемент: " << max(n, mas) << ", мин. элемент: " << min(n, mas) << ", произведение элементов между ними: " << p(n, mas);

    delete[] mas; // удаляем динамический массив

}

double sum(int n, int arr[]) // сумма элементов массива
{
    double s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}
double avrg(int n, int arr[]) // среднее элементов массива
{
    return sum(n, arr) / n;
}
double sump(int n, int arr[]) // сумма полож. элементов массива
{
    double sp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0) sp += arr[i];
    }
    return sp;
}
double sumo(int n, int arr[]) // сумма отриц. элементов массива
{
    double so = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0) so += arr[i];
    }
    return so;
}
double sumch(int n, int arr[]) // сумма элементов с четными индексами
{
    double sch = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) sch += arr[i];
    }
    return sch;
}
double sumnch(int n, int arr[]) // сумма элементов с нечетными индексами
{
    double snch = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0) snch += arr[i];
    }
    return snch;
}
double max(int n, int arr[]) // максимальный элемент массива
{
    int max = -100000000000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
double maxi(int n, int arr[]) // индекс макс. элемента
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max(n, arr)) maxi = i; 
    }
    return maxi;
}
double min(int n, int arr[]) // минимальный элемент массива
{
    int min = 100000000000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
double mini(int n, int arr[]) // индекс мин. элемента
{
    int mini = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min(n, arr)) mini = i;
    }
    return mini;
}
double p(int n, int arr[]) // произведение элементов между макс. и мин. элементами
{
    int st = mini(n, arr), f = maxi(n, arr);
    if (mini(n, arr) > maxi(n, arr)) { st = maxi(n, arr); f = mini(n, arr); }
    double p = 1;
    for (int i = st; i <= f; i++) p = p * arr[i];
    return p;
}