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

bool binarySearch(int *arr, int l, int h, int key)
{
    //* base case
    if (l > h)
        return false;
    int m = (l + h) / 2;
    if (arr[m] == key)
        return true;
    if (arr[m] > key)
        return binarySearch(arr, l, m - 1, key);
    if (arr[m] < key)
        return binarySearch(arr, m + 1, h, key);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int size;
    cout << "Enter size: ";
    cin >> size;
    int voterId[size];
    cout << "Enter voter Ids: ";
    for (int i = 0; i < size; i++)
    {
        cin >> voterId[i];
    }
    sort(voterId, voterId + size);
    int currId;
    cout << "Enter Id to search: ";
    cin >> currId;
    if (binarySearch(voterId, 0, size, currId))
        cout << "Voter Id found: " << currId << endl;
    else
        cout << "Voter Id not found: " << currId << endl;

    return 0;
}