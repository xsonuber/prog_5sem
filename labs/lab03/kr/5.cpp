#include <iostream>
#include <string>
using namespace std;

string binary(int num)
{
    num = num / 2;

    if (num == 1) return to_string(num % 2); // ������� �� 1 � ������� �� �������
    else return binary(num) + to_string(num % 2); // ��������
}

int main()
{
    system("chcp 1251");

    int num;
    cout << "������� �����: ";
    cin >> num;

    num = num * 2;

    cout << "���������: " << binary(num);
}
