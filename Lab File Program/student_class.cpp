//* Hybrid Inheritance
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::string;

//? Student class - the base class of all the other classes
class Student
{
public:
    string name;
    string enrNo;
    int totalSubjectMarks = 0;
    void getDetails()
    {
        cout << "Enter Student's name: ";
        cin >> name;
        cout << "Enter Student's enrollment number: ";
        cin >> enrNo;
    }
};

//* Academics class to get the marks in 4 subjects
class Academics : public virtual Student
{
public:
    int subject[4];

    void getDetails()
    {
        cout << "Enter marks in C++ : ";
        cin >> subject[0];
        cout << "Enter marks in Animation & Gaming : ";
        cin >> subject[1];
        cout << "Enter marks in PHP : ";
        cin >> subject[2];
        cout << "Enter marks in DBMS : ";
        cin >> subject[3];
        totalSubjectMarks += 400;
    }
};

//* ExtraCurricular class to get the marks of extra curricular subject
class ExtraCurricular : public virtual Student
{
public:
    int mark;

    void getExtraMarks()
    {
        cout << endl
             << "Enter marks in extra curricular subject: ";
        cin >> mark;
        totalSubjectMarks += 100;
    }
};

//* Result class that will calculate and print the marks and result of the student
class Result : public Academics, public ExtraCurricular
{
public:
    int totalMarks = 0;
    float perc = 0;
    //* Function to calculate the total marks and percentage
    void calcPercantage()
    {
        for (int i = 0; i < 4; i++)
            totalMarks += subject[i];

        totalMarks += mark;
        perc = ( (float) totalMarks/ (float) totalSubjectMarks) * 100.00;
    }
    //* Function to print the details of the student
    void print()
    {
        cout << "\nName : " << name << endl;
        cout << "Enrollment : " << enrNo << endl;
        cout << "Total marks : " << totalMarks << endl;
        cout << "Total Subject marks : " << totalSubjectMarks << endl;
        cout << "Percantage: " << fixed << perc;
    }
    //* Contructor to get the details as soon as the object is created
    Result()
    {
        Student::getDetails();
        Academics::getDetails();
        getExtraMarks();
        calcPercantage();
    }
};

int main()
{
    //* Object of class Result
    Result r;
    r.print(); //* Calling the print funcion
    return 0;
}