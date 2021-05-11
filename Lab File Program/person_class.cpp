#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//? The Person class that contais the details and function of a Person object
class Person
{
private:
    //? The private data members
    char *name = new char[64];
    char *address = new char[20];
    int age;
    double salary;

public:
    //* Function to set the details of the private objects
    void setDetails(char nameSet[], char addressSet[], int ageSet, double salarySet)
    {
        name = nameSet;
        address = addressSet;
        age = ageSet;
        salary = salarySet;
    }
    //* Getter for age
    int getAge()
    {
        return age;
    }
    //* Function to print the salary slip
    void printSalarySlip() const
    {
        cout<<"Salary Slip :"<<endl;
        cout << "Name = " << name << endl;
        cout << "Address = " << address << endl;
        cout << "Age = " << age << endl;
        cout << "Salary = " << salary << endl;
    }
    //* Parameterised constructor to set the details and print the salary slip
    Person(char nameSet[], char addressSet[], int ageSet, double salarySet) {
        setDetails(nameSet, addressSet, ageSet, salarySet);
        printSalarySlip();
    }
    //* Normal constructor for when we don't want to print salary as soon as an object is created
    Person() {}
};

//* Function to find the Youngest and Eldest age in an array
inline void findYoungestEldest(Person p[], int n)
{
    int min = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].getAge() >= max)
        {
            max = p[i].getAge();
            if (i == 0)
                min = max;
        }
        else if (p[i].getAge() <= min)
        {
            min = p[i].getAge();
        }
    }
    cout << "\nMin Age : " << min << endl;
    cout << "Max Age : " << max << endl;
}

int main()
{
    //? Array of Person objects, with non-parameterised constructor
    Person people[4];

    //* Setting the details of the objects
    people[0].setDetails("Hritik", "Jaipur", 25, 55000.0);
    people[1].setDetails("Kaushik", "Jalandar", 22, 25000.0);
    people[2].setDetails("Suyash", "Prayagraj", 32, 100000.0);

    //? New Person object that prints salary slip as soon as an object is created
    Person newPerson("Pavan", "Ludhiana", 24, 75000.0);
    people[3] = newPerson;

    //* Calling the inline function
    findYoungestEldest(people, 4);
    return 0;
}