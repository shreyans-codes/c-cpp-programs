//* Link - https://codeforces.com/contest/1520/problem/C
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int matrix[n][n] = {0}, row = 0, col = 0, temp = 0;
            for (int i = 1; i < (n * n); i++)
            {
                if (i == 1)
                {
                    matrix[row][col] = i;
                    continue;
                }
                // flag = checkAdjacent(matrix, row, col, n);
                if (row % 2 == 0 || row == 0)
                {
                    if (col + 2 >= n)
                    {
                        if (row + 1 >= n)
                        {
                            temp = i + 1;
                            row = 0, col = 1;
                            matrix[row][col] = i;
                            i = n * n;
                            continue;
                        }

                        row++;
                        col = 1;
                    }
                    else
                    {
                        col += 2;
                    }
                    matrix[row][col] = i;
                }
                else
                {
                    if (col + 2 >= n)
                    {
                        if (row + 1 >= n)
                        {
                            temp = i + 1;
                            row = 0, col = 1;
                            matrix[row][col] = i;
                            i = n * n;
                            continue;
                        }
                        row++;
                        col = 0;
                    }
                    else
                    {
                        col += 2;
                    }
                    matrix[row][col] = i;
                }
            }
            for (int i = temp; i <= (n * n); i++)
            {

                // flag = checkAdjacent(matrix, row, col, n);
                if (row % 2 == 0 || 0)
                {
                    if (col + 2 >= n && row + 1 <= n)
                    {
                        if (row + 1 >= n)
                        {
                            break;
                        }
                        row++;
                        col = 0;
                    }
                    else
                    {
                        col += 2;
                    }
                    matrix[row][col] = i;
                }
                else
                {

                    if (col + 2 >= n)
                    {
                        if (row + 1 >= n)
                        {
                            break;
                        }
                        row++;
                        col = 1;
                    }
                    else
                    {
                        col += 2;
                    }
                    matrix[row][col] = i;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        t--;
    }

    return 0;
}