#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    double x, y;
    cout << "������� ���������� �����: ";
    cin >> x;
    cin >> y;
    if (x * x + y * y < 9 && y > 0)
    {
        cout << "������";
    }
    // "������"
    else if (x * x + y * y > 9 || y < 0)
    {
        cout << "�������";
    }
    // "�������"
    else
    {
        cout << "�� �������";
    }
    // "�� �������";
}

