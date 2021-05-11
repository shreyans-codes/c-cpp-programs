#include <iostream>

using std::cin;
using std::cout;
using std::endl;

enum BirthType
{
    eggs,
    offspring
};
//* class created and defined
class Mammal
{
private:
    int noOfLegs, noOfEyes;
    BirthType bType;
public:
    static const bool canFly = false; //* Static and constant member variable
    //* friend functions
    friend void setNoOfEyes(int nEyes, Mammal &m);
    friend void setNoOfLegs(int nLegs, Mammal &m);
    void setbType(BirthType b)
    {
        bType = b;
    }
    //* static member function
    static void printCanFly()
    {
        cout << std::boolalpha;
        cout << "Can it fly? " << canFly << endl;
    }
    //* const member function to display the details
    void displayDetails() const
    {

        cout << "\nMammal Details\n"
             << "Number of Eyes = " << noOfEyes << endl;
        cout << "Number of Legs = " << noOfLegs << endl;
        cout << "Birth Type = " << bType << endl;
    }
    //* Contructor
    Mammal()
    {
        noOfEyes = 2;
        noOfLegs = 2;
        bType = BirthType::offspring;
    }
    //* Destrctor
    ~Mammal(){
        cout<<"Destructor Called"<<endl;
    }
};
void setNoOfEyes(int nEyes, Mammal &m)
{
    m.noOfEyes = nEyes;
}
void setNoOfLegs(int nLegs, Mammal &m)
{
    m.noOfLegs = nLegs;
}
int main()
{
    Mammal platypus; //* Object created 
    cout<<"\nDetails for Platypus"<<endl;
    platypus.setbType(BirthType::eggs);
    setNoOfLegs(4, platypus);
    platypus.displayDetails();
    Mammal human;
    cout<<"\nDetails for Humans"<<endl;
    human.displayDetails();
    cout<<"\nStatic member function"<<endl;
    Mammal::printCanFly();//* accessing static member function without any object
    return 0;
}