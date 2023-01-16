#include <bits/stdc++.h>
#include <stdio.h>

#define ll long long
using namespace std;

void InsertionSort(pair<int, int> *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j;
        pair<int, int> temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void SelectionSort(pair<int, int> *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].second < arr[minIndex].second)
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(pair<int, int> *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int currDate = arr[i].second;
        int day = currDate % 100;
        currDate /= 100;
        int month = currDate % 100;
        currDate /= 100;
        int year = currDate;
        cout << arr[i].first << " " << year << "-" << month << "-" << day << endl;
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    pair<int, int> arr[size * 2];

    cout << "Enter previous days IDs and dates: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    // Insertion Sort
    cout << "Enter today's IDs and dates: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[size + i].first;
        cin >> arr[size + i].second;
    }

    cout << "Applying Insertion Sort based on IDs" << endl;
    InsertionSort(arr, size * 2);

    printArray(arr, size * 2);

    cout << "Applying Selection Sort based on dates" << endl;
    SelectionSort(arr, size * 2);

    printArray(arr, size * 2);

    return 0;
}

/*
4 20200819
6 20080717
3 20210709
1 20220101
*/