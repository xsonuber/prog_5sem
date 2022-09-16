#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251");
	string name;
	cout << "Введите свое имя\n";
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a
	cin >> name;
	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	// int x = a / b; // вычисление значения x
	cout.precision(3);
	cout << sizeof(a / b) << ends << sizeof(x) << endl; // расчет объема занимаемой памяти
	cout << "\nx = " << x << endl; // вывод результата подсчета на экран
	cout << "Привет, " << name << "!\n"; // вывод приветствия на экран
	return 0;

}