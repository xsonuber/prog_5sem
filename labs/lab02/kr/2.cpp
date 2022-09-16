#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");

    string snils;
    cout << "������� �����: "; cin >> snils;

    if (snils.length() != 11) { cout << "False"; return 0; } // �������� �� ����� �����, ���� �� ����� 11, �� ��������� �����������

    for (int i = 2; i < 9; i++) { if (snils[i] == snils[i - 1] && snils[i] == snils[i - 2]) { cout << "False"; return 0; } } // �����������, ���� �� � ��������� ����� ����� 2-�� ������������� ����; ���� ����, ��������� �����������

    int sum = 0;
    int snilsi = 0;
    string symb = "a";
    for (int i = 8; i >= 0; i--) // ���� ������� ����� �� ������� �� �������; ������� �������� �����, ����� ��������� �� � int, ����� ���� ��������� � �����
    {
        symb = snils[i];
        snilsi = stoi(symb);
        sum = sum + (9 - i) * snilsi;
    }

    string sumstr = to_string(sum); // ��������� ������� ��������� �����

    if (sum == 100 || sum == 101) sumstr = "00"; // �������, ���� ����������� �������� ����� 100 ��� 101
    else if (sum > 101 && sum % 101 < 100) sumstr = to_string(sum % 101); // �������, ���� ����������� �������� ������ 101 � ������� �� ������� �� 101 ������ 100
    else if (sum > 101 && sum % 101 == 100) sumstr = "00"; // �������, ���� ����������� �������� ������ 101 � ������� �� ������� �� 101 ����� 100

    string kr = snils.substr(snils.length() - 2, 2); // �������� ��������� ��� ����� �� ���������� ������, ��� ��� ��� ����������� ��������, ������� ����� ����� �������� � ��������� � ��������� ����������� ���������

    if (sumstr == kr) cout << "True"; // ���������� ��������� � ��������� ����������� ��������
    else cout << "False";
    return 0;
}