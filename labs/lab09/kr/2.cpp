#include <iostream>
#include <string>
using namespace std;

class Time {
public:

    class wrongformat {
    public:
        int h, m, s;
        wrongformat(int hours, int minutes, int seconds)
        {
            h = hours;
            m = minutes;
            s = seconds;
        }
    };

    Time()
    {
        Time::hours = 0;
        Time::minutes = 0;
        Time::seconds = 0;
    }
    Time(int hours, int minutes, int seconds)
    {
        if (seconds < 0 || minutes < 0 || hours < 0) throw wrongformat(hours, minutes, seconds);
        if (seconds >= 60) { minutes += (seconds / 60); seconds = seconds % 60; }
        if (minutes >= 60) { hours += (minutes / 60); minutes = minutes % 60; }
        if (hours >= 24) hours = hours % 24;
        Time::set_hours(hours);
        Time::set_minutes(minutes);
        Time::set_seconds(seconds);
    }

    void set_hours(int time_hours)
    {
        Time::hours = time_hours;
    }
    int get_hours() const
    {
        return Time::hours;
    }
    void set_minutes(int time_minutes)
    {
        Time::minutes = time_minutes;
    }
    int get_minutes() const
    {
        return Time::minutes;
    }
    void set_seconds(int time_seconds)
    {
        Time::seconds = time_seconds;
    }
    int get_seconds() const
    {
        return Time::seconds;
    }
    void show_time() const
    {
        if (hours <= 9) cout << "0" << hours << ":";
        else cout << hours << ":";
        if (minutes <= 9) cout << "0" << minutes << ":";
        else cout << minutes << ":";
        if (seconds <= 9) cout << "0" << seconds << endl;
        else cout << seconds << endl;
    }

    Time add(Time time1, Time time2)
    {
        Time time_result = Time(time1.get_hours() + time2.get_hours(), time1.get_minutes() + time2.get_minutes(), time1.get_seconds() + time2.get_seconds());
        return time_result;
    }
private:
    int hours, minutes, seconds;
};

int main()
{
    int hours, minutes, seconds;
    cout << "Hours: "; cin >> hours;
    cout << "Minutes: "; cin >> minutes;
    cout << "Seconds: "; cin >> seconds;
    try
    {
        Time time1 = Time(hours, minutes, seconds);
        Time const time2 = Time(45, 1, 87);
        Time const time3 = Time(5, 0, 12);
        Time time4 = Time().add(time2, time3);
        cout << "\nInputed time: ";
        time1.show_time();
        cout << "\nResult time: ";
        time4.show_time();
    }
    catch (Time::wrongformat& wr)
    {
        cout << "Some of the inputed values are less than 0.";
        return 1;
    }


    return 0;


}