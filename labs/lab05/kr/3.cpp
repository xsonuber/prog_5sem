#include <iostream>
using namespace std;

int t(int, int, int[]);

int main()
{
	int n, x;
	cout << "Size of array: ";
	cin >> n;
	cout << "x: "; // элемент, который будем искать
	cin >> x;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]=";
		cin >> arr[i];
	}

	int j = -1;
	for (int i = 0; i < n; i++) // находим начальный индекс элемента, чтобы пока не запускать функцию и не смещать элемент
	{
		if (arr[i] == x) j = i;
	}

	if (j == -1) { cout << "Can't find x."; return 0; } // проверяем, что элемент вообще есть в массиве

	while (j >= 0) // обращаемся к тому же элементу несколько раз, чтобы проверить работу функции; останавливаемся, когда элемент оказывается в начале массива
	{
		cout << "x = " << x << " has index " << t(x, n, arr) << "." << endl;
		j--;
	}

	cout << "End.";
	return 0;
}

int t(int x, int n, int arr[]) // функция принимает искомый элемент, размер массива и сам массив
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			if (i == 0) return i;
			else
			{
				temp = arr[i - 1];
				arr[i - 1] = x;
				arr[i] = temp;
				return i;
			}
		}
	}
}