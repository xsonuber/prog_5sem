#include <iostream>
using namespace std;

float standart (float a)
{
    return pow(a, 1.0 / 3);
}

float formula (float a)
{
    float x;
    if (a == 1.0) { return 1.0; }
    else 
    { 
        x = (formula(a - 1.0));
        return ((1.0 / 3.0) * ((a / (x * x) + 2.0 * x))); 
    }
}

int main()
{
    float a;
    cout << "Input number: ";
    cin >> a;
    cout << "standart: " << standart(a) << endl;
    cout << "formula: " << formula(a);
}

