//Link: https://csacademy.com/contest/archive/task/processing-discounts/statement/
//* Result = 100%

#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;

struct keyValue
{
    int key;
    int value;
};


void findMinimumAmount(keyValue *arr, int N, int X)
{

    int finalAmount = X, temp = 0, discount = 0, secondTemp = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].key >= X)
        {
            secondTemp += arr[i].value; 
            temp = arr[i].key - secondTemp; //
            if (temp <= finalAmount)
            {
                finalAmount = temp;
            }
        }
        else
        {
            discount += arr[i].value;
            finalAmount = X - discount;
            secondTemp = discount;
        }
    }
    
    cout<<finalAmount;
}

int main()
{
    int N, X;
    cin >> N >> X;
    keyValue array[100000];
    for (int i = 0; i < N; i++)
        cin >> array[i].key >> array[i].value;
    sort(array, array+N, [](const keyValue& a, const keyValue& b) {
       return a.key < b.key; 
    });
    
    findMinimumAmount(array, N, X);
    return 0;
}