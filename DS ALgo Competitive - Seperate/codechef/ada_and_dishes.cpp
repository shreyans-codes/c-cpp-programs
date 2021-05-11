//Link - https://www.codechef.com/NOV20B/problems/ADADISH
#include <iostream>
using namespace std;

/*
1. Place the item that takes the most time in one burner and optimise the rest.
2 3 4 5 - 7
New Way - Place the most time consuming first then as they get completed, replace them with the next big
* Third Way (07/05/2021) - Brute Force the shit out of the question
*/

int minTimeFromSelected(int arr[], int b1, int b2, int rem1, int rem2)
{
    int sum1;
    rem2 == -1 ? sum1 = max((min(b1, b2) + rem1), max(b1, b2)) : sum1 = max((min(b1, b2) + max(rem1, rem2)), max(b1, b2) + min(rem1, rem2));
    //cout << "Sum of B1 = " << b1 << " and B2 = " << b2 << " is = " << sum1 << " " << rem1 << " " << rem2 << endl;
    return sum1;
}

int minTime(int arr[], int b1, int n)
{
    int minValue = INT32_MAX, temp = 0, values[n];
    int b2;

    for (int i = 0; i <= n; i++)
    {
        if (i == b1)
            continue;
        values[temp] = i;
        temp++;
    }
    temp = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        b2 = values[0];
        for (int j = 0; j < n; j++)
        {
            if (j == b1 || j == b2)
                continue;
            values[temp] = j;
            temp++;
        }
        if (temp == 1)
        {
            temp = minTimeFromSelected(arr, arr[b1], arr[b2], arr[values[0]], -1);
        }
        else
        {
            temp = minTimeFromSelected(arr, arr[b1], arr[b2], arr[values[0]], arr[values[1]]);
        }
        minValue >= temp ? minValue = temp : minValue = minValue;
        temp = 0;
    }
    return minValue;
}

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        if (n == 2)
            cout << max(array[0], array[1]) << endl;
        else if (n == 1)
            cout << array[0] << endl;
        else
        {
            int minValue = INT32_MAX, temp;
            for (int i = 0; i < n; i++)
            {
                temp = minTime(array, i, n);
                minValue >= temp ? minValue = temp : minValue;
            }
            cout << minValue << endl;
        }
        t--;
    }
    return 0;
}