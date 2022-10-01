#include <iostream>
#include<cmath>
using namespace std;

int Myroot(double, double, double, double&, double&);

int main()
{
    system("chcp 1251");
    cout.precision(3);

    double x1 = 0, x2 = 0, a, b, c;
    cout << "������� ������������ ��������� ����� ������ (a, b � c): ";
    cin >> a; cin >> b; cin >> c;

    int res = Myroot(a, b, c, x1, x2);
    if (res == -1) cout << "������ �� ����������.";
    else if (res == 0) cout << "������ ��������� ����: x1 = x2 = " << x1;
    else if (res == 1) cout << "����� ���������: x1 = " << x1 << ", x2 = " << x2;
}

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    double d = b * b - 4 * a * c; // ������������
    if (d < 0) return -1; // ���� ������ ���, ���������� -1
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a); // ��������� �����
        x2 = (-b - sqrt(d)) / (2 * a);
        if (x1 == x2) return 0; // ���� �����, ���������� 0 �� �������
        else return 1; // ���� ���, ���������� 1
    }
}