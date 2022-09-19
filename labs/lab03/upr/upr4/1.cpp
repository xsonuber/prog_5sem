#include <iostream>
using namespace std;

int addNumders(int n) // с "-" знак чередуетс€
{
    if (n == 1) return 1; // выход из рекурсии
    else return (n + addNumders(n - 1));
}

int addNumders(int k, int l) 
{
    if (l == k) return k;
    else return (l + addNumders(k, l - 1));
}

int main()
{
    system("chcp 1251");
    int n;
    cout << "¬ведите положительное число: ";
    cin >> n;
    int r = addNumders(n);
    cout << "–езультат: " << r << endl;

    int k, l;
    cout << "¬ведите интервал: ";
    cin >> k; cin >> l;
    int r2 = addNumders(k, l);
    cout << "–езультат: " << r2;

}
