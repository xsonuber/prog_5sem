#include <iostream>
#include <string>
#include "time.h"
using namespace std;
int main()
{
    int hours, minutes, seconds;
    cout << "Hours: "; cin >> hours;
    cout << "Minutes: "; cin >> minutes;
    cout << "Seconds: "; cin >> seconds;
    Time time1 = Time(hours, minutes, seconds);
    Time const time2 = Time(45, 1, 87);
    Time const time3 = Time(5, 0, 12);
    Time time4 = Time().add(time2, time3);
    cout << "\nInputed time: ";
    time1.show_time();
    cout << "\nResult time: ";
    time4.show_time();
    return 0;

}