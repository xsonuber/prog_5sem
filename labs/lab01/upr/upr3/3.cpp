#include <iostream>
#include<cmath>
using namespace std; 

int main()
{
	system("chcp 1251");
	double P, p, a, S;
	cout << "Введите периметр:\n";
	cin >> P;
	p = P / 2;
	a = P / 3;
	S = sqrt(p*pow((p - a), 3));
	cout.precision(3);
	cout << "Сторона Площадь\n";
	cout << a << " " << S;
	return 0;
}