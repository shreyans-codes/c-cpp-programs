
//? Link: https://www.hackerrank.com/challenges/2d-array/problem
//* Result: Success

#include <iostream>
#define N 6

using std::cin;
using std::cout;
using std::endl;

//* Function to calculate an individual hourglass and return its sum
int calculateHourglassSum(int arr[N][N], int rowStartPosition, int columnStartPosition)
{
    int temp = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 2 && j != 1)
                continue;
            temp += arr[rowStartPosition + (i - 1)][columnStartPosition + j];
        }
    }
    return temp;
}

//* Function to find the hourglasses in the Matrix
int findHourglass(int arr[N][N])
{
    int max = -10000;
    int temp;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < N - 2; j++)
        {
            temp = calculateHourglassSum(arr, i, j);
            if (temp > max)
                max = temp;
        }
    }
    return max;
}

int main()
{
    int array[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> array[i][j];
        }
    }
    int max = findHourglass(array);
    cout << max;
    return 0;
}