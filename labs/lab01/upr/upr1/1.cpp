#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	cout << "What is your name? "; // выводится вопрос
	// cin >> name; // с клавиатуры вводится ответ на вопрос (имя), сохраняется только первое слово
	getline(cin, name); // с клавиатуры вводится ответ на вопрос (имя), сохраняются все слова
	cout << "Hello, " << name << "!\n"; // выводится приветствие с раннее введенным именем
}