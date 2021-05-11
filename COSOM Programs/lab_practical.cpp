#include <iostream>

using namespace std;

/*
? Write a program to calculate mean, median and mode of a frequency distribution.
*/

void findMean()
{
    int n;

    cout << "Enter the n : ";
    cin >> n;

    double x[n];
    double f[n];
    double sum = 0;
    double sum2 = 0;
    double mul[n];

    cout << "Enter Xi values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter Fi values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        sum += f[i];
        mul[i] = f[i] * x[i];
        sum2 += mul[i];
    }

    cout << "\nMean : " << sum2 / sum << endl;
}

void findMedian()
{
    int n, start, interval;

    cout << "Enter the N: ";
    cin >> n;

    cout << "Enter the start: ";
    cin >> start;

    cout << "Enter the interval: ";
    cin >> interval;

    double f[n];
    double sum = 0;
    double sum2 = 0;
    double cf[n];

    cout << "Enter fi values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        sum += f[i];
        cf[0] = f[0];
        if (i > 0)
            cf[i] = f[i] + cf[i - 1];
    }

    sum2 = sum / 2;

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (cf[i] < sum2)
        {
            index++;
        }
        else
        {
            break;
        }
    }

    double h = interval;
    double l = start + (interval * (index));
    double c = cf[index - 1];
    double F = f[index];

    cout << "l = " << l << endl;
    cout << "h = " << h << endl;
    cout << "c = " << c << endl;
    cout << "f = " << F << endl;
    cout << "n/2 = " << sum2 << endl;

    double median = l + h * ((sum2 - c) / F);
    cout << "\nMedian : " << median << endl;
}

void findMode()
{
    int n;
    double start, interval;

    cout << "Enter N: ";
    cin >> n;

    int f[n];
    int maximum = 0;
    int max_2;

    cout << "Enter start value: ";
    cin >> start;

    cout << "Enter interval value: ";
    cin >> interval;

    cout << "Enter f: ";
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    max_2 = f[0];

    for (int i = 1; i < n; i++)
    {
        if (f[i] > max_2)
        {
            max_2 = f[i];
            maximum = i;
        }
    }

    double l = (start + interval) * maximum;
    double fm, fm1, fm2;

    fm = f[maximum];
    maximum == n - 1 ? fm1 = 0 : fm1 = f[maximum + 1];
    maximum == 0 ? fm2 = 0 : fm2 = f[maximum - 1];
    cout << "l = " << l << endl;
    cout << "f m = " << fm << endl;
    cout << "f m+1 = " << fm1 << endl;
    cout << "f m-1 = " << fm2 << endl;

    double mode = l + (((fm - fm2) / ((fm - fm2) + (fm - fm1))) * interval);
    cout << "\nMode = " << mode << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "------//Mean, Median and Mode//--------" << endl
             << "1. Mean" << endl
             << "2. Median" << endl
             << "3. Mode" << endl
             << endl
             << "0. Exit" << endl;
        cout << "Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            findMean();
            break;
        case 2:
            findMedian();
            break;
        case 3:
            findMode();
            break;
        case 0:
            cout << "Good bye!";
            break;
        default:
            break;
        }
    } while (choice != 0);
}