#include "Triangle.h"
#include <string>
#include <iostream>
using namespace std;

Triangle::Triangle(Dot* dot1, Dot* dot2, Dot* dot3)
{
	Triangle::set_dot1(dot1);
	Triangle::set_dot2(dot2);
	Triangle::set_dot3(dot3);
}

void Triangle::set_dot1(Dot* d1)
{
	dot_1 = d1;
}

Dot Triangle::get_dot1()
{
	return *dot_1;
}

void Triangle::set_dot2(Dot* d2)
{
	dot_2 = d2;
}

Dot Triangle::get_dot2()
{
	return *dot_2;
}

void Triangle::set_dot3(Dot* d3)
{
	dot_3 = d3;
}

Dot Triangle::get_dot3()
{
	return *dot_3;
}

void Triangle::show_sides()
{
	cout << "First side: " << dot_1->distanceTo(*dot_2) << endl;
	cout << "Second side: " << dot_2->distanceTo(*dot_3) << endl;
	cout << "Third side: " << dot_3->distanceTo(*dot_1) << endl;
}

double Triangle::per()
{
	return dot_1->distanceTo(*dot_2) + dot_2->distanceTo(*dot_3) + dot_3->distanceTo(*dot_1);
}

double Triangle::sq()
{
	double p = per() / 2;
	double s1 = dot_1->distanceTo(*dot_2);
	double s2 = dot_2->distanceTo(*dot_3);
	double s3 = dot_3->distanceTo(*dot_1);

	return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}