#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main()
{
    system("chcp 1251");

    int m, n;
    cout << "¬ведите числа: ";
    cin >> m; cin >> n;
    int r = gcd(m, n);
    cout << "–езультат: " << r;

}
