#include <iostream>
using namespace std;

int* sort(int n, int* a)
{
    int min = 0; // ��� ������ ������������ ��������
    int buf = 0; // ��� ������ ����������
    for (int i = 0; i < n; i++)
    {
        min = i; // ����� ������� ������, ��� ������ � ����������� ���������
        // � ����� ������ �������� ����� ������ � ����������� ���������
        for (int j = i + 1; j < n; j++)
            min = (a[j] < a[min]) ? j : min;
        // ������������ ����� ��������, ������� ��� ������� � �������
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
    return a;
}

int main()
{
    system("chcp 1251");

    int N;
    cout << "������� ������ �������: ";
    cin >> N;

    int* a = new int[N];

    for (int i = 0; i < N; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    sort(N, a);

    for (int i = 0; i < N; i++)
        cout << a[i] << '\t';

    delete[] a;

    return 0;
}

