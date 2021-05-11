#include <iostream>

using namespace std;

//Electricity class declared and defined
class Electricity
{
    //Protected members that derived classes can access
protected:
    float unit;
    float cost;

public:
    // Bill function to calculate the total amount
    void bill()
    {
        int temp;
        if (unit > 300)
        {
            //For first 100 units the cost is 0.5, between 100 and 300 is 0.55
            cost = 0.50 * 100;
            cost += 0.55 * 200;
            //We subtract the 300 units for which we have added the cost
            temp = unit - 300;
            //For the number of units above 300, the cost is 0.60
            cost += 0.60 * temp;
        }
        else if (unit <= 300)
        {
            //For first 100 units the cost is 0.5, between 100 and 300 is 0.55
            cost = 0.50 * 100;
            //We subtract the 100 units for which we have added the cost
            temp = unit - 100;
            //For the number of units above 100, the cost is 0.55
            cost += 0.55 * temp;
        }
        else
        {
            //The number of units is less than 100, so the cost is 0.50
            cost = 0.50 * unit;
        }
    }
    // Constructor to set the number of units as soon as an object is created
    Electricity()
    {
        cout << "Enter the no. of units: ";
        cin >> unit;
    }
};

//More Electricity class that inherits from Electricity class
class MoreElectricity : public Electricity
{
    //Private data members
private:
    float surcharge, difference, total_cost;

public:
    //Bill Function overridden so that we can add the surcharge
    void bill()
    {
        Electricity::bill();
        total_cost = cost;
        //Adding surcharge if the bill is more than 250
        if (cost > 250.00)
        {
            difference = cost - 250;
            surcharge = difference * 0.15;
            total_cost = cost + surcharge;
        }
        cout << "Total Bill Amount is: Rs. " << total_cost;
    }
};

int main()
{
    // More Electricity object created
    MoreElectricity moreElectricity;
    // Bill function called
    moreElectricity.bill();
    return 0;
}