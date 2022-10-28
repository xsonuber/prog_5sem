#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

using Tuple = tuple<string, int, double>;
using Tuple2 = tuple<double, bool>;

void printTupleOfThree(Tuple t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}

void printTupleOfTwo(Tuple2 t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ")" << endl;
}
Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

Tuple change_int_t(Tuple t)
{
	get<0>(t) = 'a';
	get<1>(t) = 10;
	get<2>(t) = 10.01;

	return t;
}

Tuple2 newt(Tuple t)
{
	bool check = false;
	if (get<0>(t) == "a") check = true;
	return make_tuple(get<2>(t) * 10, check);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	printTupleOfThree(t0);
	auto t1 = funtup(v1[1], v2[1], v3[1]);
	printTupleOfThree(t1);
	auto tchanged = change_int_t(t0);
	printTupleOfThree(tchanged);
	auto newtuple = newt(t0);
	printTupleOfTwo(newtuple);
	return 0;
}