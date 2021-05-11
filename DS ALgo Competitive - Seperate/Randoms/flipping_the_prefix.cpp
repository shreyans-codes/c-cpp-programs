//Link - https://csacademy.com/contest/archive/task/flip-the-prefix/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void findHighestSum(int *arr, int N)
{
    int temp = 0, sum = 0;
    vector<int> index;
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] < 0)
        {
            for (int x = 0; x <= i; x++)
            {
                arr[x] = -1 * arr[x];
            }
            index.push_back(i+1);
            temp++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    cout<<sum<<std::endl;
    int size = sizeof(index) / sizeof(index[0]);
    for (int i = 0; i < index.size(); i++)
    {
        cout<<index[i]<<" ";
    }
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    findHighestSum(arr, N);
    return 0;
}