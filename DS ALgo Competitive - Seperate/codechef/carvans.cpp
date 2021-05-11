//Link -https://www.codechef.com/LRNDSA01/problems/CARVANS
#include <iostream>

using namespace std;

//* Result = Success!

/*
In this question, we are given the number of cars and their maximum speed.
The cars are running in a queue so if the car in front of a car is slower than the max speed if this car,
then this car would run in that speed.
We have to find how many cars are at their max speed.
*/

int findMaxSpeedCars(int *array, int length)
{
    /* 10 2 4 8 1 5 */
    int current_max_speed = array[0];
    int result = 0;
    if (array[0] == 0)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
            break;
        if (array[i] > current_max_speed)
            continue;
        else if(array[i] <= current_max_speed) {
            result++;
            current_max_speed = array[i];
        }
    }
    return result;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    int results[test_cases];
    int N, j = 0, temp = test_cases;
    while (test_cases > 0)
    {
        cin >> N;
        int cars_speed[N];
        for (int i = 0; i < N; i++)
            cin >> cars_speed[i];
        results[j] = findMaxSpeedCars(cars_speed, N);
        j++;
        test_cases--;
    }
    for (int i = 0; i < temp; i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}