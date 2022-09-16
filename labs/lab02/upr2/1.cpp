#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x, x1, x2, y;
    cout << "x1 = "; cin >> x1;
    cout << "x2 = "; cin >> x2;
    cout << "\tx\tsin(x)\n"; // печать заголовка таблицы вывода значений функции
    x = x1; // левая граница
    do
    {
        y = sin(x);
        cout << "\t" << x << "\t" << y << endl; // вывод значений x и y
        x = x + 0.01; // выводим с шагом 0.01
    } while (x <= x2); // постусловие, цикл работает до границы x2
    return 0;
}
