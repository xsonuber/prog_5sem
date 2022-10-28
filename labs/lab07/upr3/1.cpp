#include <iostream>
#include <windows.h>
using namespace std;

struct Distance
{
	int feet;
	double inches;
	void ShowDist()
	{
		cout << feet << "\'-" << inches << "\"\n";
	}
};

Distance AddDist(Distance arr[], int n)
{
	Distance d;
	d.feet = 0;
	d.inches = 0;
	for (int i = 0; i < n; i++)
	{
		d.feet += arr[i].feet;
		d.inches += arr[i].inches;
	}
	while (d.inches >= 12.0)
	{
		d.inches -= 12.0;
		d.feet++;
	}
	return d;
}

Distance InputDist()
{
	Distance d;
	cout << "\n¬ведите число футов: ";
	cin >> d.feet;
	cout << "¬ведите число дюймов: ";
	cin >> d.inches;
	return d;
}

int main()
{
	system("chcp 1251");
	// Distance d1 = InputDist();
	// Distance d2 = { 1, 6.25 };
	// Distance d3 = AddDist(d1, d2);
	// d1.ShowDist();
	// d2.ShowDist();
	// d3.ShowDist();

	int n;
	cout << "¬ведите размер массива рассто€ний ";
	cin >> n;
	Distance* masDist = new Distance[n];

	for (int i = 0; i < n; i++)
	{
		masDist[i] = InputDist();
	}

	for (int i = 0; i < n; i++)
	{
		masDist[i].ShowDist();
	}

	Distance d3 = AddDist(masDist, n);
	d3.ShowDist();
	delete[] masDist;
	return 0;
}