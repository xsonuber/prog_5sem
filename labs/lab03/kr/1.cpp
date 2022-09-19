#include <iostream>
#include <string>
using namespace std;

bool snilscheck(string snils)
{
    string newsnils;
    for (int i = 0; i < snils.length(); i++) // ��������� �� �������, ������, ������ ������� � ��������� � ���������� ����� ������� 11
    {
        if (snils[i] != '-' && snils[i] != ' ' && snils[i] != '0' && snils[i] != '1' && snils[i] != '2' && snils[i] != '3' && snils[i] != '4' && snils[i] != '5' && snils[i] != '6' && snils[i] != '7' && snils[i] != '8' && snils[i] != '9')
        { 
            return false; 
        }
        else if (snils[i] == '0' || snils[i] == '1' || snils[i] == '2' || snils[i] == '3' || snils[i] == '4' || snils[i] == '5' || snils[i] == '6' || snils[i] == '7' || snils[i] == '8' || snils[i] == '9')
        {
            newsnils = newsnils + snils[i];
        }
    }

    if (newsnils.length() != 11) { return false; } // �������� �� ����� �����, ���� �� ����� 11, �� ��������� �����������

    for (int i = 2; i < newsnils.length() - 2; i++) { if (newsnils[i] == newsnils[i - 1] && newsnils[i] == newsnils[i - 2]) { return false; } } // �����������, ���� �� � ��������� ����� ����� 2-�� ������������� ����; ���� ����, ��������� �����������

    int sum = 0;
    int snilsi = 0;
    string symb = "a";
    for (int i = newsnils.length() - 2; i >= 0; i--) // ���� ������� ����� �� ������� �� �������; ������� �������� �����, ����� ��������� �� � int, ����� ���� ��������� � �����
    {
        symb = newsnils[i];
        snilsi = stoi(symb);
        sum = sum + (9 - i) * snilsi;
    }

    string sumstr = to_string(sum); // ��������� ������� ��������� �����

    if (sum == 100 || sum == 101) sumstr = "00"; // �������, ���� ����������� �������� ����� 100 ��� 101
    else if (sum > 101 && sum % 101 < 100) sumstr = to_string(sum % 101); // �������, ���� ����������� �������� ������ 101 � ������� �� ������� �� 101 ������ 100
    else if (sum > 101 && sum % 101 == 100) sumstr = "00"; // �������, ���� ����������� �������� ������ 101 � ������� �� ������� �� 101 ����� 100

    string kr = newsnils.substr(newsnils.length() - 2, 2); // �������� ��������� ��� ����� �� ���������� ������, ��� ��� ��� ����������� ��������, ������� ����� ����� �������� � ��������� � ��������� ����������� ���������

    if (sumstr == kr) return true; // ���������� ��������� � ��������� ����������� ��������
    return false;
}

int main()
{
    system("chcp 1251");

    string snils;
    cout << "������� �����: "; getline(cin, snils);

    bool result = snilscheck(snils);
    if (result == 1) cout << "True";
    else cout << "False";
}