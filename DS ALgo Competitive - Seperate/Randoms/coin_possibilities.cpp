#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::sort;
/*
* This is a game in which we are given a set of numbers and some coins. 
* The objective is to place N number of coins in such a manner that the sum is the number in the set.
? So in this program we are given N [The number of coins we must use to get the sum] and denominations of the currency
? We need to find all the possible sums with the input. */
void findAllPossibilities(int N, vector<int> *denominations) {
    int end = denominations->size();
    //int max = denominations[end] * N;
}

int main() {
    int N, choice;
    vector<int> denominations;
    cout<<"Enter the number of coins to use: ";
    cin>>N;
    cout<<"Enter the denominations of your currency\nEnter 0 when you're done: ";
    do
    {
        cin>>choice;
        if(choice!=0)
            denominations.push_back(choice);
    } while (choice!=0);
    sort(denominations.begin(), denominations.end());
    return 0;
}