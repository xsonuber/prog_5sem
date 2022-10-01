#include <iostream>
using namespace std;

int Input(int&, int&);

int main()
{
    system("chcp 1251");
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    else { int s = a + b; cout << s; }
    return 0;
}

int Input(int& a, int& b)
{
    cout << "¬ведите a и b: ";
    cin >> a; cin >> b;

    if (a >= 0 && a % 2 == 0 && b >= 0 && b % 2 == 0) return true;
    else return false;
}