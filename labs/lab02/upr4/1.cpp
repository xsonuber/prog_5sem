#include <iostream>
using namespace std;
int main()
{
    system("chcp 1251");
    int k, m, s = 0;
    cout << "������� ������� ����������: ";
    cin >> k; cin >> m;
    for (int i = 1; i <= 100; i++)
    {
        if ((i > k) && (i < m))
            continue;
        s += i;
    }
    cout << "�����: " << s;
    return 0;
}
