#include <bits/stdc++.h>
using namespace std;

void printSolution(int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        printf("\n");
    }
}

bool isValid(int **board, int row, int col, int N)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveBoard(int **board, int col, int N)
{
    // base case
    if (col == N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isValid(board, i, col, N))
        {
            board[i][col] = 1;

            if (solveBoard(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solve(int N)
{
    int **board;
    board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N]{0};

    if (solveBoard(board, 0, N) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board, N);
    return true;
}

int main()
{
    int N;
    cout << "Enter value for N: ";
    cin >> N;
    solve(N);
    return 0;
}
