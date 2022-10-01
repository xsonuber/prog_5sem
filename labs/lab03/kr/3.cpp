#include <iostream>
using namespace std;

double square(double a)
{
    double p = a * 3 / 2;
    return sqrt(p * pow((p - a), 3));
}

double square(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a)* (p - b) * (p - c));
}

int main()
{
    system("chcp 1251");
    cout.precision(3);
    int tr;
    cout << "Площадь какого треугольника необходимо найти? (равностороннего - 1 или разностороннего - 2)\n";
    cin >> tr;

    if (tr == 1)
    {
        double a;
        cout << "Ââĺäčňĺ ńňîđîíó ňđĺóăîëüíčęŕ: ";
        cin >> a;

        cout << "Ďëîůŕäü: " << square(a);
    }

    else if (tr == 2)
    {
        double a, b, c;
        cout << "Ââĺäčňĺ ńňîđîíű ňđĺóăîëüíčęŕ: ";
        cin >> a; cin >> b; cin >> c;

        if (a + b <= c || a + c <= b || b + c <= a) cout << "Íĺęîđđĺęňíűé ňđĺóăîëüíčę.";
        else cout << "Ďëîůŕäü: " << square(a, b, c);
    }

    else cout << "Íĺęîđđĺęňíűé îňâĺň íŕ âîďđîń.";
    
    return 0;
}

