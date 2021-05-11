#include <iostream>
using std::cin;
using std::cout;

struct Equation
{
    double x;
    double y;
    double s;
};

Equation eq[2];

void inter(Equation, Equation);

int main()
{
    cout << "Enter values of equation 1 : ";
    cin >> eq[0].x >> eq[0].y >> eq[0].s;

    cout << "Enter values of equation 2 : ";
    cin >> eq[1].x >> eq[1].y >> eq[1].s;

    cout << "\n"
         << eq[0].x << "x + " << eq[0].y << "y = " << eq[0].s;
    cout << "\n"
         << eq[1].x << "x + " << eq[1].y << "y = " << eq[1].s;

    inter(eq[0], eq[1]);
}

void inter(Equation eq1, Equation eq2)
{
    double x, y;

    y = (eq2.x * eq1.s - eq1.x * eq2.s) / (eq1.y * eq2.x - eq1.x * eq2.y);
    x = (eq2.y * eq1.s - eq1.y * eq2.s) / (eq1.x * eq2.y - eq1.y * eq2.x);

    cout << "\nIntersection point : (" << x << ", " << y << ")\n";
}