#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	cout << "What is your name? "; // ��������� ������
	// cin >> name; // � ���������� �������� ����� �� ������ (���), ����������� ������ ������ �����
	getline(cin, name); // � ���������� �������� ����� �� ������ (���), ����������� ��� �����
	cout << "Hello, " << name << "!\n"; // ��������� ����������� � ������ ��������� ������
}