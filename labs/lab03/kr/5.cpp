#include <iostream>
#include <string>
using namespace std;

string binary(int num)
{
    num = num / 2;

    if (num == 1) return to_string(num % 2); // доходим до 1 и выходим из функции
    else return binary(num) + to_string(num % 2); // рекурсия
}

int main()
{
    system("chcp 1251");

    int num;
    cout << "Ââåäèòå ÷èñëî: ";
    cin >> num;

    num = num * 2;

    cout << "Ðåçóëüòàò: " << binary(num);
}
