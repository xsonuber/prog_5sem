#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

struct Roots // structure and function that prints roots
{
	double x1;
	double x2;
	void showroots()
	{
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}
};

bool check(double a, double b, double c) // discriminant checking function 
{
	if (b * b - 4 * a * c < 0) return false;
	else return true;
}

Roots solution(double a, double b, double c) // function that finds roots
{
	Roots r;
	r.x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	r.x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	return r;
}

int main()
{
	double a, b, c;
	cout << "Input a, b and c: ";
	cin >> a; cin >> b; cin >> c;

	if (check(a, b, c) == 0) { cout << "No roots."; return 0; } 

	Roots result = solution(a, b, c);
	cout << "Solution: ";
	result.showroots();

	return 0;
}