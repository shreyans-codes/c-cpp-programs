/*
* Q1)  Create a class called employee. It stores employees’ name, designation, 
*      empcode and address. From class employee now derive classes TemporaryEmp 
*     and PermanentEmp. The temporary employee a fixed wage per day and 
*      overtime as Rs. 50 per extra hour whereas permanent employs enjoys salary 
*      depending on the  number of days worked. Each class should have a constructor, 
*      destructor and a function for displaying his data (name it as print).
*      Also implement the following specifications
? Make employee an abstract base class.
? Modify the program to add private data member birthdate ( a data object) and department code (as int) to class employee. Assume that this program is run once every month,
? as your program calculates the payroll for each employee, add Rs. 1000 as bonus to the persons payroll amount if this is the month in which the employee’s birthday occurs.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

//* Address class to store the address
class Address
{
private:
    string houseNo, area, city, pincode;

public:
    void setAddress()
    {
        cout << "Enter House No: ";
        getline(cin, houseNo);
        cout << "Enter Area: ";
        getline(cin, area);
        cout << "Enter City: ";
        getline(cin, city);
        cout << "Enter Pincode: ";
        getline(cin, pincode);
    }
    string getAddress()
    {
        string propAdress = houseNo + ", " + area + ", " + city + ", " + pincode;
        return propAdress;
    }
};

//* Date class to store the birthdate
class Date
{
public:
    int day, month, year;
    //* Function to set the date
    void setDate()
    {
        string temp;
        cout << "Enter the date: " << endl
             << "Day: ";
        getline(cin, temp);
        day = std::stoi(temp);
        cout << "Month: ";
        getline(cin, temp);
        year = std::stoi(temp);
        cout << "Year: ";
        getline(cin, temp);
        year = std::stoi(temp);
    }
    //* Function to return the properly formated string
    string getDate()
    {
        string propDate = to_string(day) + " \\ " + to_string(month) + " \\ " + to_string(year);
        return propDate;
    }
};

//* The main employee base class
class Employee
{
protected:
    string empName, designation, empCode;
    int deptCode;
    Address address;
    Date birthday;
public:
    //* Function to set the detailos of the employee as soon as a derived class object is created
    void setDetails()
    {
        string temp;
        cout<<endl;
        cout << "Enter Employee Name: ";
        getline(cin, empName);
        cout << "Enter Employee Designation: ";
        getline(cin, designation);
        cout << "Enter Department Code: ";
        getline(cin, temp);
        deptCode = std::stoi(temp);
        cout<<endl;
        cout << "Enter Employee Code: ";
        getline(cin, empCode);
        cout << "Enter Employee Address: " << endl;
        address.setAddress();
        cout << "Enter Employee Birthday: " << endl;
        birthday.setDate();
    }
    //* Pure virtual function
    virtual void print() = 0;
    //* Contructor
    Employee()
    {
        setDetails();
    }
    ~Employee() {}
};

//* Temporary employee class
class TempEmployee : private Employee
{
private:
    //* private data members to calculate the salary
    double fixedWage;
    int numberOfOvertime;
    int noOfDaysWorked;
    double salary;

public:
    //* Function to calculate salary
    void calcSalary()
    {
        salary = (fixedWage * (double)noOfDaysWorked) + (50.0 * (double)numberOfOvertime);
    }
    //* Function to set the details of the employee
    void setDetails()
    {
        string temp;
        cout << "Temporary Employee Details: " << endl;
        cout << "Enter the fixed wage: ";
        getline(cin, temp);
        fixedWage = std::stoi(temp);
        cout << "Enter the number of overtime: ";
        getline(cin, temp);
        numberOfOvertime = std::stoi(temp);
        cout << "Enter the number of days worked: ";
        getline(cin, temp);
        noOfDaysWorked = std::stoi(temp);
    }
    //* Function to return the salary
    double getSalary()
    {
        calcSalary();
        return salary;
    }
    //* pure virtual function deined in the derived class
    void print()
    {
        cout << endl
             << "Details of Employee" << endl;
        cout << "Name: " << empName << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department Code: " << deptCode << endl;
        cout << "Employee Code: " << empCode << endl;
        cout << "Address: " << address.getAddress() << endl;
        cout << "Birthday: " << birthday.getDate() << endl;
    }
    //* Constructor
    TempEmployee()
    {
        setDetails();
    }
    ~TempEmployee() {}
};

class PermanentEmployee : private Employee
{
private:
    double fixedWage;
    int noOfDaysWorked;
    double salary;

public:
    void calcSalary(int month)
    {
        month == birthday.month ? salary = (fixedWage * (double)noOfDaysWorked) + 1000.0 : salary = (fixedWage * (double)noOfDaysWorked);
    }
    void setDetails()
    {
        cout << "Permanent Employee Details: " << endl;
        cout << "Enter the fixed wage: ";
        cin >> fixedWage;
        cout << "Enter the number of days worked: ";
        cin >> noOfDaysWorked;
    }
    double getSalary(int month)
    {
        calcSalary(month);
        return salary;
    }
    //* pure virtual function deined in the derived class
    void print()
    {
        cout << endl
             << "Details of Employee" << endl;
        cout << "Name: " << empName << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department Code: " << deptCode << endl;
        cout << "Employee Code: " << empCode << endl;
        cout << "Address: " << address.getAddress() << endl;
        cout << "Birthday: " << birthday.getDate() << endl;
    }
    PermanentEmployee()
    {
        setDetails();
    }
    ~PermanentEmployee() {}
};

//* Function to allot approptiate function of the required classes
void assignFunction(int choice, TempEmployee *emp1, PermanentEmployee *emp2)
{
    int i;
    switch (choice)
    {
    case 1:
        emp1->calcSalary();
        cout << "Salary = " << emp1->getSalary();
        break;
    case 2:
        cout << "Enter the current Month: ";
        cin >> i;
        emp2->calcSalary(i);
        cout << "Salary = " << emp2->getSalary(i);
        break;
    case 3:
        emp1->print();
        break;
    case 4:
        emp2->print();
        break;
    default:
        break;
    }
}

int main()
{
    int choice = 0;
    cout << "Temporary Employee: " << endl;
    //? Temp Employee object created
    TempEmployee emp1;
    cout << "Permanent Employee: " << endl;
    //? Permanent Employee object created
    PermanentEmployee emp2;
    //* Loop that shows the user the menu
    do
    {
        cout << "\nSelect from the following" << endl
             << "1. Calculate Temp Employee Salary" << endl
             << "2. Calculate Permanent Employee Salary" << endl
             << "3. Print Temp Employee Details" << endl
             << "4. Print Permanent Employee Details" << endl
             << endl
             << "0. Exit" << endl;
        cin >> choice;
        if (choice > 0 && choice <= 4)
        {
            assignFunction(choice, &emp1, &emp2);
        }
        else if (choice == 0)
        {
            cout << "See you later";
        }
        else
        {

            cout << "Incorrect option selected";
        }

    } while (choice != 0);
    return 0;
}