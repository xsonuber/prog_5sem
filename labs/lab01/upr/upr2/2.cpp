#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251");
	string name;
	cout << "������� ���� ���\n";
	double a, b;
	cout << "������� a � b:\n";
	cin >> a; // ���� � ���������� �������� a
	cin >> name;
	cin >> b; // ���� � ���������� �������� b
	double x = a / b; // ���������� �������� x
	// int x = a / b; // ���������� �������� x
	cout.precision(3);
	cout << sizeof(a / b) << ends << sizeof(x) << endl; // ������ ������ ���������� ������
	cout << "\nx = " << x << endl; // ����� ���������� �������� �� �����
	cout << "������, " << name << "!\n"; // ����� ����������� �� �����
	return 0;

}