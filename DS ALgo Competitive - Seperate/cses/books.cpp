#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;

//? CSES/ProblemSet/Sorting and Searching/Books

int main()
{
    ull n, temp1, temp2, count1 = 0;
    cin >> n;
    ull rTime[n], count2 = 0, x = 0, y = 0, xTotal = 0, yTotal = 0;
    for (ull i = 0; i < n; i++)
    {
        cin >> rTime[i];
    }
    sort(rTime, rTime + n);
    for (ull i = 0; i < n; i++)
    {
        temp1 = rTime[count2], temp2 = rTime[count1];
        if(temp1 > temp2) {
            yTotal+=temp1;
            while(temp1!=0) {
                temp1-=temp2;
                count1++;
                temp2 = rTime[count1];
            }
        }
    }
    return 0;
}