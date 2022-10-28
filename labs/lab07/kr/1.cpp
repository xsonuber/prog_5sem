#include <iostream>
#include <windows.h>
using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
	void showtime()
	{
		if (hours < 10) cout << "0";
		cout << hours << ":";
		if (minutes < 10) cout << "0";
		cout << minutes << ":";
		if (seconds < 10) cout << "0";
		cout << seconds;
	}
};

Time inputtime()
{
	Time t;
	cout << "\nInput hours: ";
	cin >> t.hours;
	cout << "\nInput minutes: ";
	cin >> t.minutes;
	cout << "\nInput seconds: ";
	cin >> t.seconds;
	return t;
}

int sec(Time t) // function converts time to seconds
{
	return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time unsec(int s) // function converts seconds to time
{
	Time t;
	t.hours = (s / 3600) % 24;
	t.minutes = (s % 3600) / 60;
	t.seconds = (s % 3600) % 60;
	return t;
}

Time addtime(Time t1, Time t2) // addition of two times
{
	Time t;
	int sum = sec(t1) + sec(t2);
	t = unsec(sum);
	return t;
}

Time subttime(Time t1, Time t2) // subtraction of two times
{
	Time t;
	int sum = 0;
	if (sec(t1) >= sec(t2)) sum = sec(t1) - sec(t2);
	else sum = sec(t2) - sec(t1);
	t = unsec(sum);
	return t;
}


int main()
{
	Time t = inputtime();
	cout << "\nInputed time - ";
	t.showtime();
	int insec = sec(t);
	cout << "\nYour time in seconds: " << insec;

	Time t1 = inputtime();
	Time t2 = inputtime();
	cout << "\nadd operation time - ";
	addtime(t1, t2).showtime();
	cout << "\nsubtract operation time - ";
	subttime(t1, t2).showtime();
	return 0;
}