#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Student
{
private:
    int marks[10];
    string name;

public:
    Student addMarks(int inputMarks[10], Student &s)
    {
        Student temp = s;
        for (int i = 0; i < 10; i++)
        {
            temp.marks[i] = inputMarks[i];
        }
        return temp;
    }
    void setName(string s)
    {
        name = s;
    }
    void showDetails()
    {
        cout << "Name = " << name << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "Marks " << i + 1 << ": " << marks[i] << endl;
        }
    }
};

int main()
{
    Student studentObject;
    string name;
    cout << "Enter the name of the student" << endl;
    getline(cin, name);
    studentObject.setName(name);
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Marks " << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }
    studentObject = studentObject.addMarks(array, studentObject);
    studentObject.showDetails();
    return 0;
}