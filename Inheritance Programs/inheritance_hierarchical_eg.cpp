//* Hierarchical Inheritance
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::string;

//? Base class
class School
{
protected:
    string baseClass;
    string highestClass;
    string name;
public:
    void setDetails(string base, string highest, string n){
        baseClass = base;
        highestClass = highest;
        name = n;
    }
    string getName(){
        return name;
    }
    string getBase(){
        return baseClass;
    }
    string getHighestClass(){
        return highestClass;
    }
};

class PrimarySchool : public School
{
    public:
    void setDetails(){
        string base, h, n;
        cout<<"Enter Details for Primary School: "<<endl<<"Base Class: ";
        cin>>base;
        cout<<"Highest Class: ";
        cin>>h;
        cout<<"Name: ";
        cin>>n;
        School::setDetails(base, h, n);
    }
    void printDetails() const {
        cout<<endl<<"Details for Primary School:"<<endl;
        cout<<"Base Class = "<<baseClass<<endl;
        cout<<"Highest Class = "<<highestClass<<endl;
        cout<<"Name = "<<name<<endl;
    }
    PrimarySchool(){
        setDetails();
    }
};

class HighSchool : public School
{
    public:
    void setDetails(){
        string base, h, n;
        cout<<"Enter Details for High School: "<<endl<<"Base Class: ";
        cin>>base;
        cout<<"Highest Class: ";
        cin>>h;
        cout<<"Name: ";
        cin>>n;
        School::setDetails(base, h, n);
    }
    void printDetails() const {
        cout<<endl<<"Details for High School:"<<endl;
        cout<<"Base Class = "<<baseClass<<endl;
        cout<<"Highest Class = "<<highestClass<<endl;
        cout<<"Name = "<<name<<endl;
    }
    HighSchool(){
        setDetails();
    }
};

int main()
{
    PrimarySchool school1;
    HighSchool school2;
    school1.printDetails();
    school2.printDetails();
    return 0;
}