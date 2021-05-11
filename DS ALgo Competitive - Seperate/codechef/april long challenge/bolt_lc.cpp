//Link - https://www.codechef.com/APRIL21C/problems/BOLT
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int T;
    cin >> T;
    while (T != 0)
    {
        float k1, k2, k3, v;
        string answer = "NO";
        cin >> k1 >> k2 >> k3 >> v;
        float speed = k1 * k2 * k3 * v;
        float final_time = 100 / speed;
        float temp = (float)((int)(final_time * 100 + .5)) / 100;
        temp < 9.57 ? answer = "YES" : answer = "NO";
        //! Not rounding properly
        cout << temp<<" - " <<answer << std::endl;
        T--;
    }
}