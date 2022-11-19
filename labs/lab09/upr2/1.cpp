#include <iostream>
#include <string>
using namespace std;
class DivideByZeroError
{
public:
    DivideByZeroError() : message("Can't divide by zero.") { }
    void printMessage() const { cout << message << endl; }
private:
    string message;
};

float quotient(int numl, int num2)
{
    if (num2 == 0)
        throw DivideByZeroError();
    return (float)numl / num2;
}
int main()
{
    cout << "Input number:\n";
    int number;
    cin >> number;
    for (int i = -10; i < 10; i++)
    {
        try
        {
            float result = quotient(number, i);
            cout << "Result: " << result << endl;
        }
        catch (DivideByZeroError& error)
        {
            cout << "ERROR: ";
            error.printMessage();
        }
    }
}