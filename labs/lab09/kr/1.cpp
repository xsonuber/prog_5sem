#include<cmath>
#include <iostream>
using namespace std;
class Triangle
{
public:
    class wrongsides
    {
    public:
        double wa, wb, wc;
        wrongsides(double ws1, double ws2, double ws3)
        {
            wa = ws1;
            wb = ws2;
            wc = ws3;
        }
    };
    Triangle(double a, double b, double c)
    {
        if (a + b <= c) throw wrongsides(a, b, c);
        if (a + c <= b) throw wrongsides(a, c, b);
        if (b + c <= a) throw wrongsides(b, c, a);
        Triangle::set_a(a);
        Triangle::set_b(b);
        Triangle::set_c(c);
    }

    void set_a(double side_a)
    {
        Triangle::a = side_a;
    }
    double get_a() const
    {
        return Triangle::a;
    }

    void set_b(double side_b)
    {
        Triangle::b = side_b;
    }
    double get_b() const
    {
        return Triangle::b;
    }

    void set_c(double side_c)
    {
        Triangle::c = side_c;
    }
    double get_c() const
    {
        return Triangle::c;
    }

    double square()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
private:
    double a, b, c;
};
int main()
{
    double a, b, c;
    cout << "Input first side: ";
    cin >> a;
    cout << "Input second side: ";
    cin >> b;
    cout << "Input third side: ";
    cin >> c;

    try
    {
        Triangle tr1 = Triangle(a, b, c);
        cout << "Result: " << tr1.square();
    }
    catch (Triangle::wrongsides& wr)
    {
        cout << "\nError. ";
        cout << "Summary of sides " << wr.wa << " and " << wr.wb << " is equal or less than the value of the third side " << wr.wc;
    }
}