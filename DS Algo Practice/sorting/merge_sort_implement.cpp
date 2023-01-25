/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to inaction
*/

#include <bits/stdc++.h>
using namespace std;

int *mergeArr(int *a1, int *a2, int size1, int size2)
{
    int i = 0, j = 0, k = 0;
    int *finalArr = new int[size1 + size2];
    while (i < size1 && j < size2)
    {
        if (a1[i] <= a2[j])
        {
            finalArr[k] = a1[i];
            i++;
        }
        else
        {
            finalArr[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        finalArr[k] = a1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        finalArr[k] = a2[j];
        j++;
        k++;
    }
    return finalArr;
}

int *mergeSort(int *arr, int size)
{
    if (size == 1)
        return arr;
    int size1 = size / 2;
    int size2 = size - size1;
    int *arr1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i];
    }
    int *arr2 = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[size1 + i];
    }
    cout << "Printing divided arrays" << endl;
    cout << "Array 1: ";
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Array 2: ";
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    arr1 = mergeSort(arr1, size1);
    arr2 = mergeSort(arr2, size2);

    return mergeArr(arr1, arr2, size1, size2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr = mergeSort(arr, n);
    // print array
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
