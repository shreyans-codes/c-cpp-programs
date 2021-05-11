//Link - https://www.codechef.com/LRNDSA02/problems/PSHOT
#include <iostream>
using namespace std;

int findEarliestMoment(int array[], int size)
{
    int returnValue = 0;
    int teamA = 0, teamB = 0, remaining;
    for (int i = 0; i < size; i += 2)
    {
        remaining = (size - (i + 1)) / 2;
        teamA += array[i];
        teamB += array[i + 1];

        if (array[i] == array[i + 1])
            continue;
        else
        {
            if (array[i] > array[i + 1] && (teamB + remaining) < teamA)
            {
                
                returnValue = (i + 2);
            }
            else if (array[i + 1] > array[i] && (teamA + remaining) < teamB)
            {
                
                returnValue = (i + 2);
            }
            else
            {
                continue;
            }
        }
    }
    returnValue == 0 ? returnValue = size : returnValue = returnValue;
    return returnValue;
}

int main()
{
    int test_cases; //T
    cin >> test_cases;
    int noOfGoals, temp = test_cases; //N
    int result[test_cases];
    for (int i = 0; i < test_cases; i++)
    {
        cin >> noOfGoals;
        int goalScored[(noOfGoals * 2)];
        for (int j = 0; j < (noOfGoals * 2); j++)
            cin >> goalScored[j];

        result[i] = findEarliestMoment(goalScored, (noOfGoals * 2));
    }
    for (int i = 0; i < test_cases; i++)
    {
        cout << result[i];
    }
    return 0;
}