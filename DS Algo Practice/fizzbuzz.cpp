#include <iostream>
/*
* Write a short program that prints each number from 1 to 100 on a new line. 
* For each multiple of 3, print "Fizz" instead of the number. 
* For each multiple of 5, print "Buzz" instead of the number. 
* For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.
*/

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int count = 1;
    for (int i = 1; i < 101; i++)
    {
        if (count % 3 == 0 && count % 5 == 0)
        {
            cout << "fizzbuzz";
            count = 0;
        }
        else if (count % 3 == 0)
        {
            cout << "fizz";
        }
        else if (count % 5 == 0)
        {
            cout << "buzz";
        }
        else
        {
            cout << i;
        }
        cout << endl;
        count++;
    }
}
