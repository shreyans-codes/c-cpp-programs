#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//? The date class
class Date
{
private:
    int day, month, year;

public:
    //* Function to get (& set) the data
    void getData()
    {
        cout << "Enter the date: " << endl
             << "Day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;
    }
    //* Prefix increment operator
    void operator++()
    {
        if (month == 12 && day == 31)
        {
            year++;
            month = 1;
            day = 1;
        }
        else
        {
            if (month % 2 == 1 && day == 31)
            {
                month++;
                day = 1;
            }
            else if (month == 2 && day >= 28)
            {
                month++;
                day = 1;
            }
            else if (month % 2 == 0 && day == 30)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
    }
    //* Postfix Incrememnt Operator
    Date operator++(int)
    {
        Date tempD;
        tempD.day = this->day;
        tempD.month = this->month;
        tempD.year = this->year;
        if (month == 12 && day == 31)
        {
            year++;
            month = 1;
            day = 1;
        }
        else
        {
            if (month % 2 == 1 && day == 31)
            {
                month++;
                day = 1;
            }
            else if (month == 2 && day >= 28)
            {
                month++;
                day = 1;
            }
            else
            {
                day++;
            }
        }
        return tempD;
    }
    void printDate() const
    {
        cout << day << "/ " << month << "/ " << year << endl;
    }
    //* Parameterized Constructor
    Date(bool)
    {
        getData();
    }
    //* Default Constructor
    Date() {}
    //* Destructor
    ~Date() {}
};

int main()
{
    Date date1(true);
    Date date2 = date1;
    //* Example of Prefix Operator
    ++date1;
    date1.printDate();
    //* Example of Postfix Operator
    date2++;
    date2.printDate();
    return 0;
}