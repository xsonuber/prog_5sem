#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int check(string);
string op(string, string, string);

int main()
{
	string str;
	cout << "Enter command (choose flag -s or -p): ";
	getline(cin, str);

	if (check(str) == -1) { cout << "Error!"; return 0; } // проверка ввода пользователя на количество аргументов

	string arr[4];
	int j = 0;
	for (int i = 0; i < str.length(); i++) // перевод введенной строки в массив из четырех элементов
	{
		if (str[i] != ' ') arr[j] += str[i];
		else j++;
	}

	if (arr[0] != "prog" && arr[0] != "Prog") { cout << "Error!"; return 0; } // проверка первого аргумента; он должен быть "prog" или "Prog"

	cout << "Result: " << op(arr[1], arr[2], arr[3]);

}

int check(string str) // функция проверки на кол-во аргументов
{
	int spaces = 0;
	for (int i = 0; i < str.length(); i++) { if (str[i] == ' ') spaces++; }

	if (spaces != 3 || (spaces == 3 && str[str.length() - 1] == ' ')) return -1;
	else return 1;
}

string op(string f, string x, string y) // функция, которая проверяет флаг и считает результат
{
	int xi = stoi(x);
	int yi = stoi(y);
	if (f == "-s") return to_string(xi + yi);
	else if (f == "-p") return to_string(xi * yi);
	else return "incorrect flag";
}
