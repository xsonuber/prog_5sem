#include <iostream>
#include<cmath>
using namespace std;

int Myroot(double, double, double, double&, double&);

int main()
{
    system("chcp 1251");
    cout.precision(3);

    double x1 = 0, x2 = 0, a, b, c;
    cout << "Введите коэффициенты уравнения через пробел (a, b и c): ";
    cin >> a; cin >> b; cin >> c;

    int res = Myroot(a, b, c, x1, x2);
    if (res == -1) cout << "Корней не существует.";
    else if (res == 0) cout << "Корень уравнения один: x1 = x2 = " << x1;
    else if (res == 1) cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2;
}

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    double d = b * b - 4 * a * c; // дискриминант
    if (d < 0) return -1; // если корней нет, возвращаем -1
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a); // вычисляем корни
        x2 = (-b - sqrt(d)) / (2 * a);
        if (x1 == x2) return 0; // если равны, возвращаем 0 по условию
        else return 1; // если нет, возвращаем 1
    }
}