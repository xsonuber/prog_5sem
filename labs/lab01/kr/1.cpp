#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	system("chcp 1251");
	double S, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
	cout << "¬ведите координаты первой вершины:\n";
	cin >> x1;
	cin >> y1;
	cout << "¬ведите координаты второй вершины:\n";
	cin >> x2;
	cin >> y2;
	cout << "¬ведите координаты третьей вершины:\n";
	cin >> x3;
	cin >> y3;
	cout << "¬ведите координаты четвертой вершины:\n";
	cin >> x4;
	cin >> y4;
	cout << "¬ведите координаты п€той вершины:\n";
	cin >> x5;
	cin >> y5;

	S = abs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5) / 2;
	cout << "ѕлощадь п€тиугольника: " << S;
	return 0;
}