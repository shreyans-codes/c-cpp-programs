// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int flag = 0, r1 = 0, c1 = 0, j = 0, a = (r * c);
        vector<int> ans;
        while (ans.size() < a)
        {

            if (flag == 2)
            {
                for (int i = r - 1; i >= r1; i--)
                {
                    ans.push_back(matrix[i][c1]);
                    j++;
                }
                c1++;
                flag = 0;
            }
            if (flag < 2)
            {
                if (flag % 2 == 0)
                {
                    for (int i = c1; i < c; i++)
                    {
                        ans.push_back(matrix[r1][i]);
                        j++;
                    }
                    r1++;
                    flag = 3;
                }
                else
                {
                    for (int i = c - 1; i >= c1; i--)
                    {
                        ans.push_back(matrix[r - 1][i]);
                        j++;
                    }
                    r--;
                    flag = 2;
                }
            }
            else
            {
                if (!flag % 2 == 0)
                {
                    for (int i = r1; i < r; i++)
                    {
                        ans.push_back(matrix[i][c - 1]);
                        j++;
                    }
                    c--;
                    flag = 1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends