//Link - https://csacademy.com/contest/archive/task/fast-travel/statement/
#include <iostream>
#include <cstdlib>
#define MAX_N 1001

using std::cin;
using std::cout;

struct cityCoords
{
    int s;
    int x;
    int y;
};

struct cityList
{
    int A;
    int B;
};

int cityMemo[MAX_N][MAX_N] = {0};

int findFastestRoute(cityCoords *city, int cityA, int cityB)
{
    int m_d = abs(city[cityA].x - city[cityB].x) + abs(city[cityA].y - city[cityB].y);
    
}

int fastestRoute(cityList *arr, cityCoords *brr, int Q, int T)
{
    int answerList[Q], temp;
    for (int i = 0; i < Q; i++)
    {
        temp =
            abs(brr[arr[i].A - 1].x - brr[arr[i].B - 1].x) +
            abs(brr[arr[i].A - 1].y - brr[arr[i].B - 1].y);

        if (brr[arr[i].A - 1].s == 1 && brr[arr[i].B - 1].s == 1)
            temp > T ? answerList[i] = T : answerList[i] = temp;

        else if (brr[arr[i].A - 1].s != 1 && brr[arr[i].B - 1].s == 1 ||
                 brr[arr[i].A - 1].s == 1 && brr[arr[i].B - 1].s != 1)
        {
            int x1;
            brr[arr[i].A - 1].s != 1 ? x1 = arr[i].A - 1 : x1 = arr[i].B - 1;
            for (int j = 0; j < Q; j++)
            {
                int min = temp, tempDistance;
                if (brr[j].s == 1)
                {
                    tempDistance =
                        abs(brr[x1].x - brr[j].x) +
                        abs(brr[x1].y - brr[j].y);
                    min > tempDistance ? min = tempDistance : min = min;
                }

                min + T < temp ? temp = min + T : temp = temp;
            }
            answerList[i] = temp;
        }
        else
        {
            int x1;
            brr[arr[i].A - 1].s != 1 ? x1 = arr[i].A - 1 : x1 = arr[i].B - 1;
            for (int j = 0; j < Q; j++)
            {
                int min = temp, tempDistance1, tempDistance2;
                if (brr[j].s == 1)
                {
                    tempDistance1 =
                        abs(brr[x1].x - brr[j].x) +
                        abs(brr[x1].y - brr[j].y);
                    min > tempDistance1 ? min = tempDistance1 : min = min;
                }

                min + T < temp ? temp = min + T : temp = temp;
            }
            answerList[i] = temp;
        }
    }
    for (int i = 0; i < Q; i++)
        cout << answerList[i] << std::endl;
    return 0;
}

int main()
{
    int N, T, Q;
    cin >> N >> T;
    cityCoords citiesCoords[N];
    for (int i = 0; i < N; i++)
        cin >> citiesCoords[i].s >> citiesCoords[i].x >> citiesCoords[i].y;
    cin >> Q;
    cityList listOfCities[Q];
    for (int i = 0; i < Q; i++)
        cin >> listOfCities[i].A >> listOfCities[i].B;
    int temp = fastestRoute(listOfCities, citiesCoords, Q, T);
    return 0;
}