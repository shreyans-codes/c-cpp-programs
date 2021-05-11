#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Function to check if the integer is Palindrome
bool intPalindromeCheck(int num)
{
    int temp = num;
    int remainder, holder = 0;
    bool returnValue;
    while (temp > 0)
    {
        remainder = temp % 10;
        holder = (holder * 10) + remainder;
        temp = temp / 10;
    }
    holder == num ? returnValue = true : returnValue = false;
    return returnValue;
}
// Function to check if the string is Palindrome
bool stringPalindromeCheck(string input)
{
    int i, length;
    bool returnValue = true;
    length = input.length();
    for (i = 0; i < length; i++)
    {
        if (input[i] != input[length - i - 1])
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}

int main()
{
    cout << "\nEnter A Number" << endl;
    int x;
    bool isPalindrome;
    cin >> x;
    //Boolean to store the result
    isPalindrome = intPalindromeCheck(x);
    //Checking and printing the result
    isPalindrome ? cout << "The number is Palindrome" : cout << "The number is not Palindrome";
    cout << "\nEnter A String" << endl;
    string input;
    cin >> input;
    //To convert the string to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //Boolean to store the result
    isPalindrome = stringPalindromeCheck(input);
    //Checking and printing the result
    isPalindrome ? cout << "The string is Palindrome" << endl : cout << "The string is not Palindrome" << endl;
    return 0;
}