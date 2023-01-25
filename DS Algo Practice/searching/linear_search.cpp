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

bool linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return true;
    return false;
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
    int currId;
    cout << "Enter Id to search: ";
    cin >> currId;
    if (linearSearch(voterId, size, currId))
        cout << "Voter Id found: " << currId << endl;
    else
        cout << "Voter Id not found: " << currId << endl;

    return 0;
}