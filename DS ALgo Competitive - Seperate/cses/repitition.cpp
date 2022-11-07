/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not athe fruits of action be your motive, nor let your attachment be to inaction
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string inp;
    getline(cin, inp);
    int n = inp.length(), mL = 1, maxL = 1;
    for (int i = 1; i < n; i++)
    {
        inp[i] == inp[i - 1] ? mL++ : mL = 1;
        maxL < mL ? maxL = mL : maxL = maxL;
    }
    cout << maxL << endl;
    return 0;
}