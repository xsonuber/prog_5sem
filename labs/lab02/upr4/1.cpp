#include <iostream>
using namespace std;
int main()
{
    system("chcp 1251");
    int k, m, s = 0;
    cout << "¬ведите границы интервалов: ";
    cin >> k; cin >> m;
    for (int i = 1; i <= 100; i++)
    {
        if ((i > k) && (i < m))
            continue;
        s += i;
    }
    cout << "—умма: " << s;
    return 0;
}
