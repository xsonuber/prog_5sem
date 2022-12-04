#include <iostream>
#include "Triangle.h"
using namespace std;
int main()
{
    Dot* dot1 = new Dot(1, 3);
    Dot* dot2 = new Dot(4, 4);
    Dot* dot3 = new Dot(4, 1);

    Triangle* tr1 = new Triangle(dot1, dot2, dot3);

    tr1->show_sides();
    cout << "Perimetr: " << tr1->per() << endl;
    cout << "Square: " << tr1->sq() << endl;
    delete tr1;
    return 0;
}
