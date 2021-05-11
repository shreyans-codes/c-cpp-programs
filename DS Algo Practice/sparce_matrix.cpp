
//? Link: https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

void matchStrings(string str[], int n, string queries[], int q) {
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}

int main()
{
    int n, q;
    cin>>n;
    string strings[n];
    for (int i = 0; i < n; i++)
        cin>>strings[i];
    cin>>q;
    string queries[q];
    for (int i = 0; i < q; i++)
        cin>>queries[i];
        matchStrings(strings, n, queries, q);
    return 0;
}
