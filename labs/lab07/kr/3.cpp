#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

using Tuple = tuple<double, double, string>; 

Tuple solution(double a, double b, double c) // function that defines flag and finds roots (if any)
{
	double x1, x2, d = b * b - 4 * a * c;
	string flag;
	if (d < 0) flag = "nr";
	else if (d == 0) { flag = "sr"; x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a); x2 = x1; }
	else { flag = "r"; x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a); x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a); }
	return make_tuple(x1, x2, flag);
}

void printroots(tuple<double, double, string> t) // function checks flag and prints solution 
{
	if (get<2>(t) == "nr") { cout << "No roots." << endl; }
	else if (get<2>(t) == "sr") { cout << "One root: " << "x = " << get<0>(t) << endl; }
	else { cout << "Roots: x1 = " << get<0>(t) << ", x2 = " << get<1>(t) << endl; }
}

int main()
{
	double a, b, c;
	cout << "Input a, b and c: ";
	cin >> a; cin >> b; cin >> c;
	auto result = solution(a, b, c);
	cout << "Solution:\n";
	printroots(result);
	return 0;
}