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
    cout << "������� ������ ������������ ���������� �����? (��������������� - 1 ��� ��������������� - 2)\n";
    cin >> tr;

    if (tr == 1)
    {
        double a;
        cout << "������� ������� ������������: ";
        cin >> a;

        cout << "�������: " << square(a);
    }

    else if (tr == 2)
    {
        double a, b, c;
        cout << "������� ������� ������������: ";
        cin >> a; cin >> b; cin >> c;

        if (a + b <= c || a + c <= b || b + c <= a) cout << "������������ �����������.";
        else cout << "�������: " << square(a, b, c);
    }

    else cout << "������������ ����� �� ������.";
    
    return 0;
}

