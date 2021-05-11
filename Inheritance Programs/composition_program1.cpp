//* Composition Example
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//? The class that can used in many different class
class FlightAbility
{
    private:
    //* The speed with which the being flies
    double velocity;
    public:
    //* Function to set the being aflight
    void takeFlight(string objName){
        cout<<"The "<<objName<<" is now airborne with "<<velocity<<" mph velocity"<<endl;
    }
    //* Function to set the velocity
    void setVelocity(double v){
        velocity = v;
    }
    //* Constructor to set the velocity to avoid getting garbage value
    FlightAbility(int x){
        setVelocity(x);
    }
    ~FlightAbility(){}
};

//? The class that 'has a' flight ability
class Bird
{
private:
    //* Example of composite association
    FlightAbility flightAbility = FlightAbility(0.0);
    //* The name of the bird
    string name;
public:
    //* Function to call the flight function and give the name of the being
    void setAflight() {
        flightAbility.takeFlight(name);
    }
    //* Function to set the name of the bird and its speed
    void setDetails(string n, double v){
        name = n;
        flightAbility.setVelocity(v);
    }
};


int main() {
    //* Object created
    Bird bird1;
    string name;
    double v;
    //? Getting the name of the bird
    cout<<"Name of the bird: ";
    getline(cin, name);
    //? Getting the speed of the bird
    cout<<"Set the speed of flight: ";
    cin>>v;
    //? Setting the details
    bird1.setDetails(name, v);
    //* Setting the bird aflight
    bird1.setAflight();
}