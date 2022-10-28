
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251");

	ofstream out("text", ios::out | ios::binary);
	if (!out) {
		cout << "���� ������� ����������\n";
		return 1;
	}

	cout << "������� �������������. ��������� ���, ����� ��� ���� Enter: \n";
	string line = "";
	do {
		getline(cin, line);
		out << "\n";
		out << line;
	} while (line != "");

	out.close();

	ifstream in("text", ios::in | ios::binary);
	if (!in) {
		cout << "���� ������� ����������";
		return 1;
	}
	
	cout << "���� �������������: \n";
	string reading;
	if (in.is_open())
	{
		while (getline(in, reading))
		{
			cout << reading << '\n';
		}
	}

	in.close();
	return 0;
}