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
    cout << "Input two numbers to divide:\n";
    int number1, number2;
    cin >> number1;
    cin >> number2;
    try
    {
        float result = quotient(number1, number2);
        cout << "Result: " << result << endl;
    }
    catch (DivideByZeroError& error)
    {
        cout << "ERROR: ";
        error.printMessage();
        return 1; // завершение программы при ошибке
    }
    return 0; // нормальное завершение программы
}