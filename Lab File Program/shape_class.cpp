#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

class Shape
{
private:
    double radius, length, width;
    double perimeter;
public:
    Shape();
    ~Shape();
    //Getters and Setters for privae member variables
    double getRadius() { return radius; }
    double getLength() { return length; }
    double getWidth() { return width; }
    void setRadius(double r) { radius = r; }
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    void calcPerimeter(int isCircle)
    {
        switch (isCircle)
        {
        case 1:
            perimeter = 2 * M_PI * radius;
            cout << "Perimeter of circle = " << perimeter << endl;
            break;
        case 2:
            perimeter = 2 * (length + width);
            cout << "Perimeter of rectangle = " << perimeter << endl;
            break;
        default:
            break;
        }
    }
};

Shape::Shape()
{
    //To avoid operations on null
    radius = 0;
    length = 0;
    width = 0;
}

Shape::~Shape()
{
    cout << "Destructor Called"<<endl;
}

int main()
{
    double input1, input2;
    Shape circle;
    cout<<"Enter radius for circle: ";
    cin>>input1;
    circle.setRadius(input1);
    circle.calcPerimeter(1);
    Shape rectangle;
    cout<<"Enter length & width for rectangle: ";
    cin>>input1>>input2;
    rectangle.setLength(input1);
    rectangle.setWidth(input2);
    rectangle.calcPerimeter(2);
    return 0;
}