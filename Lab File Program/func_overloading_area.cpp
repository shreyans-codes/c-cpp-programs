#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

//* Function for calculation area of triangle
void AREA(int base, int height)
{
    double area = 0.5 * base * height;
    cout << "Area of Triangle = " << area << endl;
}

//* Function for calculation area of rectangle
//! Breadth input error, takes garbage value
void AREA(float breadth, float height)
{
    float area = (breadth * height);
    cout << "Area of Rectangle = " << std::fixed << area << endl;
}

//* Function for calculation area of circle
void AREA(double radius)
{
    double area = M_PI * pow(radius, 2.0);
    cout << "Area of Circle = " << area << endl;
}

void assignFunction(int &c)
{

    switch (c)
    {
        int base, height;
        float breadth, height2;
    case 1:

        cout << "\nBase of Triangle: ";
        cin >> base;
        cout << "\nHeight of Triangle: ";
        cin >> height;
        AREA(base, height);
        break;
    case 2:
        cout << "Width of Rectangle: ";
        cin >> breadth;
        cout << "Height of Rectangle: ";
        cin >> height;
        AREA(breadth, height2);
        break;
    case 3:
        double radius;
        cout << "\nRadius of Circle: ";
        cin >> radius;
        AREA(radius);
        break;
    case 0:
        cout << "Thank You!";
        break;
    default:
        cout << "Incorrect Option";
        break;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Choose an option"
             << "\n1. Area of triangle\n2. Area of rectangle\n3. Area of circle\n0. Exit" << endl
             << "Your choice: ";
        cin >> choice;
        assignFunction(choice);

    } while (choice != 0);

    return 0;
}