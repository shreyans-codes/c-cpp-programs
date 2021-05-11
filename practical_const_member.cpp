#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class City
{
private:
    long residentCount;
    string current_MLA, cityName;
    string location;

public:
    City()
    {
        residentCount = 1800000;
        current_MLA = "Ashok Lahoty";
        cityName = "Jaipur";
        location = "Lat: 26.922070, Long:75.778885";
    }
    //* Const member function, this function cannot change any variable's value
    void displayDetails() const{
        cout<<endl;
        cout<<"Number of residents = "<<residentCount<<endl;
        cout<<"City Name = "<<cityName<<endl;
        cout<<"MLA = "<<current_MLA<<endl;
        cout<<"Location = "<<location<<endl;
    }
};

int main()
{
    City jaipur;//* Object created
    cout<<endl;
    jaipur.displayDetails();//* Const member function called
    return 0;
}