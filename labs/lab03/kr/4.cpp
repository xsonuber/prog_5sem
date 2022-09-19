#include <iostream>
using namespace std;

int func(int n)
{
    if (n <= 0) return 0;
    else return (5 * n + func(n - 1)); 
}

int main()
{
    system("chcp 1251");
    int n;
    cout << "¬ведите число: ";
    cin >> n;

    cout << "–езультат: " << func(n);
}
