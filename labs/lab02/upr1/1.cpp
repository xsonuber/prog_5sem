#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    double x, y;
    cout << "Введите координаты точки: ";
    cin >> x;
    cin >> y;
    if (x * x + y * y < 9 && y > 0)
    {
        cout << "внутри";
    }
    // "внутри"
    else if (x * x + y * y > 9 || y < 0)
    {
        cout << "снаружи";
    }
    // "снаружи"
    else
    {
        cout << "на границе";
    }
    // "на границе";
}

