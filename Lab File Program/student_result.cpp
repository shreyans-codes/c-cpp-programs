#include <iostream>
#include <math.h>
using namespace std;
class student
{
public:
    string name;
    string roll_no;
    string course;
    void get_details()
    {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter Roll number : ";
        cin >> roll_no;
        cout << "Enter your course : ";
        cin >> course;
    }
    void print_details()
    {
        cout << "\nName : " << name;
        cout << "\nRoll number : " << roll_no;
        cout << "\nCourse : " << course;
    }
};
class exam : public student
{
public:
    int marks[6];
    void enter_marks()
    {
        cout << "\n";
        for (int i = 0; i < 6; i++)
        {
            cout << "Enter marks of subject " << i + 1 << " : ";
            cin >> marks[i];
        }
    }
};
class result : public exam
{
public:
    int total_marks;
    result()
    {
        total_marks = 0;
    }
    void calc_marks()
    {
        for (int i = 0; i < 6; i++)
        {
            total_marks += marks[i];
        }
    }
    void print_result()
    {
        cout << "\n\n RESULT\n\n";
        print_details();
        cout << "\nTotal marks : " << total_marks << "/600";
    }
};
int main()
{
    result r;
    r.get_details();
    r.enter_marks();
    r.calc_marks();
    r.print_result();
}