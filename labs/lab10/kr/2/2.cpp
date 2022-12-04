#include <iostream>
#include "Triangle.h"
using namespace std;
int main()
{

    Triangle* tr1 = new Triangle();

    tr1->show_sides();
    cout << "Perimetr: " << tr1->per() << endl;
    cout << "Square: " << tr1->sq() << endl;
    delete tr1;
    return 0;
}
