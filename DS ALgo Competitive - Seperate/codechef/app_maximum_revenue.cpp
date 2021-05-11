//Link -https://www.codechef.com/LRNDSA01/problems/ZCO14003
#include <iostream>
#include <algorithm>
using namespace std;

/*
The customer will buy the app if the price is <= their budget
We have to choose a budget among the listed ones to maximise revenue
! Use long long instead of int
*/

//* Result - 100% (YEAH BOII)

long long findMaximumRevenue(long long array[], int length)
{
    long long max = 0, temp;
    for (int i = 0; i < length; i++)
    {
        temp = 0;
        temp = array[i] * (length - i);
        if (temp >= max)
            max = temp;
    }
    return max;
}

int main()
{
    int test_case_number;
    cin >> test_case_number;
    long long customer_budget[test_case_number];
    for (int i = 0; i < test_case_number; i++)
        cin >> customer_budget[i];
    sort(customer_budget, customer_budget + test_case_number);
    long long resut = findMaximumRevenue(customer_budget, test_case_number);
    cout << resut;
    return 0;
}