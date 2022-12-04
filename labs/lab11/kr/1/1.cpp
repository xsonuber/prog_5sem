#include <iostream>
using namespace std;

class Time
{
private:
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) { }
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
        if (seconds >= 60) { minutes += seconds / 60;  seconds = seconds % 60; }
        if (minutes >= 60) { hours += minutes / 60; minutes = minutes % 60;  }
        if (hours >= 24) { hours = hours % 24; }
    }

    Time(float hs)
    {
        hours = (hs * 10) / 10;
        minutes = ((hs - hours) * 60) / 10;
        seconds = (((hs - hours) * 60) * 60) / 10;
    }

    operator float() const
    {
        float t = (hours * 3600 + minutes * 60 + seconds) / 3600;
        return t;
    }

    void get_time()
    {
        cout << "\nInput hours: ";
        cin >> hours;
        cout << "\nInput minutes: ";
        cin >> minutes;
        cout << "\nInput seconds: ";
        cin >> seconds;

    }

    void show_time()
    {
        if (hours <= 9) cout << "0" << hours << ":";
        else cout << hours << ":";
        
        if (minutes <= 9) cout << "0" << minutes << ":";
        else cout << minutes << ":";

        if (seconds <= 9) cout << "0" << seconds << endl;
        else cout << seconds << endl;
    }

    Time operator+ (const Time&) const;
    Time operator+ (const double&) const;
    Time operator- (const Time&) const;
    bool operator> (const Time&) const;
    bool operator< (const Time&) const;
    bool operator== (const Time&) const;
    friend std::ostream& operator<< (std::ostream& out, const Time& time);
};

std::ostream& operator<< (std::ostream& out, const Time& time)
{
    Time t = Time(time.hours, time.minutes, time.seconds);

    if (t.hours <= 9) out << "0" << t.hours << ":";
    else out << t.hours << ":";

    if (t.minutes <= 9) out << "0" << t.minutes << ":";
    else out << t.minutes << ":";

    if (t.seconds <= 9) out << "0" << t.seconds;
    else out << t.seconds;

    return out;
}

Time Time::operator+ (const Time& t2) const
{
    int h = hours + t2.hours;
    int m = minutes + t2.minutes;
    int s = seconds + t2.seconds;

    return Time(h, m, s);
}

Time Time::operator+ (const double& t2) const
{
    Time time2 = Time(t2);

    int h = hours + time2.hours;
    int m = minutes + time2.minutes;
    int s = seconds + time2.seconds;

    return Time(h, m, s);
}

Time Time::operator- (const Time& t2) const
{
    int h = hours - t2.hours;
    int m;
    int s;

    if (minutes < t2.minutes) { m = minutes + 60 - t2.minutes; h--; }
    else m = minutes - t2.minutes;
    if (seconds < t2.seconds) { s = seconds + 60 - t2.seconds; m--; }
    else s = seconds - t2.seconds;

    return Time(h, m, s);
}

bool Time::operator> (const Time& t2) const
{
    double time1 = hours * 3600 + minutes * 60 + seconds;
    double time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    if (time1 > time2) return true;
    else return false;
}

bool Time::operator< (const Time& t2) const
{
    double time1 = hours * 3600 + minutes * 60 + seconds;
    double time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    if (time1 < time2) return true;
    else return false;
}

bool Time::operator== (const Time& t2) const
{
    double time1 = hours * 3600 + minutes * 60 + seconds;
    double time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    if (time1 == time2) return true;
    else return false;
}

int main()
{
    Time time1, time2, time3, time4, time5, time6;

    time1.get_time();
    time2.get_time();
    time3 = time1 + time2;
    time4 = time1 - time2;
    time5 = time1 + 5.004;
    time6 = 5.004 + time1;
    
    cout << "time1 + time2 = " << time3 << endl;
    cout << "time1 - time2 = " << time4 << endl;

    cout << "Time + double = " << time5 << endl;
    cout << "double + Time = " << time6 << endl;

    bool timediff1 = time1 > time2;
    bool timediff2 = time1 < time2;
    bool timediff3 = time1 == time2;

    if (timediff1 == true) cout << time1 << " > " << time2 << endl;
    if (timediff2 == true) cout << time1 << " < " << time2 << endl;
    if (timediff3 == true) cout << time1 << " = " << time2 << endl;

}
