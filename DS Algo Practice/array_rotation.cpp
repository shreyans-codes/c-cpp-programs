#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printArray(int arr[], int n) {
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" - ";
    }
}
//!Basic rotation - creating a temp array of size d
//* Complexity analysis - O(d) + O(n) = O(d*n) 
void rotate(int arr[], int d, int n) {
    int temp[d];
    //* O(d) + c1 (assigning) + c2 (incrementing) = O(d) 
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    //* O(n) + c1 (condition) + c2 (assignment) + c3 (incrementing) = O(n)
    for (int i = 0; i < n; i++)
    {
        if(i >= n - d){
            arr[i] = temp[i - (n-d)];
            continue;
        }
        arr[i] = arr[i+d];
    }
    printArray(arr, n);
}

//! Left Rotate by one. Storing arr[i] at the n-i location
//* Complexity Ananlysis - O(d * n)
void leftRotateByOne(int arr[], int n) {
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void leftRotate(int arr[], int d, int n) {
    for (int i = 0; i < d; i++)
    {
        leftRotateByOne(arr, n);
    }
    printArray(arr, n);
}


int main() {
    int arr[] = {0, 5, 8, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    //rotate(arr, 2, n);
    leftRotate(arr, 3, n);
}