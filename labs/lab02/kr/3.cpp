#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");

    int n, c10 = 0, c5 = 0, c2 = 0, c1 = 0, t = 0; // ���������� ����������, n - �����, ������� �������� � ����������, c10 - ���������� ����� � 10 ������, c5 - � 5 ������, c2 - � 2 �����, c1 - � 1 �����, t - ��������� ����������, ����� �� �������� n
    cout << "������� �����, ����������� ������ ��������: ";
    cin >> n;
    t = n;

    while (t != 0) // ���� � ������ ����������, ������� ����� ����������� ��������� ����� ����� � 10 ������, ������ � 5 � �.�.
    {
        if (t >= 10) { c10++; t = t - 10; }
        else if (t >= 5) { c5++; t = t - 5; }
        else if (t >= 2) { c2++; t = t - 2; }
        else if (t == 1) { c1++; t = t - 1; }
    }

    cout << "����������� ����� ������ 10 - " << c10 << ", ������ 5 - " << c5 << ", ������ 2 - " << c2 << ", ������ 1 - " << c1 << ".";
}