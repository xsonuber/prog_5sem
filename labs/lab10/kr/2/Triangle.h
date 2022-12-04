#pragma once
#include "Dot.h"
class Triangle
{
public:
	Triangle();


	void set_dot1(Dot);
	Dot get_dot1();


	void set_dot2(Dot);
	Dot get_dot2();


	void set_dot3(Dot);
	Dot get_dot3();

	void show_sides();
	double per();
	double sq();

private:
	Dot dot_1;
	Dot dot_2;
	Dot dot_3;
};

