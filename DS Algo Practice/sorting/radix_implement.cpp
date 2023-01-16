/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to
    ? inaction
*/

#include <bits/stdc++.h>
using namespace std;

void radixSort(int *arr, int n)
{
    int maxEl = arr[0], unitPlace = 1, k = 0;
    for (int i = 0; i < n; i++)
        maxEl = max(maxEl, arr[i]);
    queue<int> count[10];
    while (maxEl > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            if (arr[i] / unitPlace > 0)
                curr = (arr[i] / unitPlace) % 10;
            count[curr].push(arr[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            while (!count[i].empty())
            {
                int top = count[i].front();
                arr[k] = top;
                count[i].pop();
                k++;
            }
        }
        k = 0;
        unitPlace *= 10;
        maxEl /= 10;
    }
    // return arr;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i];
        else
            cout << arr[i] << " - ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}