#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <cmath>

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) { }
	Point(int xcoord, int ycoord)
	{
		x = xcoord;
		y = ycoord;
	}

	double distance()
	{
		return sqrt(x * x + y * y);
	}
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
	bool operator< (Point&);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "(" << point.x << "; " << point.y << ")";
	return out;
}

bool Point::operator< (Point& p2)
{
	double d1 = this->distance();
	double d2 = p2.distance();

	if (d1 < d2) return true;
	return false;
}
int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для

	// класса Point

	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для

		// класса Point

	return 0;
}