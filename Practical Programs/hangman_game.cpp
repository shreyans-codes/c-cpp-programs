#include <bits/stdc++.h>
using namespace std;

void printRest(int lim)
{
    for (int i = 0; i < lim; i++)
        cout << "       |\n";
    cout << "========\n";
}

void printHangman(int miss)
{
    cout << "  +----+\n";
    cout << "  |    |\n";
    int rem;
    if (miss == 1)
        rem = 3;
    else if (miss > 1 && miss < 5)
        rem = 2;
    else if (miss > 4 && miss < 7)
        rem = 1;
    else
        rem = 4;
    if (miss > 0)
    {
        switch (miss)
        {
        case 1:
            cout << "  O    |\n";
            printRest(rem);
            break;
        case 2:
            cout << "  O    |\n";
            cout << "  |    |\n";
            printRest(rem);
            break;
        case 3:
            cout << "  O    |\n";
            cout << " /|    |\n";
            printRest(rem);
            break;
        case 4:
            cout << "  O    |\n";
            cout << " /|\\   |\n";
            printRest(rem);
            break;
        case 5:
            cout << "  O    |\n";
            cout << " /|\\   |\n";
            cout << " /     |\n";
            printRest(rem);
            break;
        case 6:
            cout << "  O    |\n";
            cout << " /|\\   |\n";
            cout << " / \\   |\n";
            printRest(rem);
            break;
        default:
            printRest(rem);
            break;
        }
    }
    else
        printRest(rem);
}

bool remWords(string correct, char guess[], int len)
{
    string actual(correct.length(), '_');
    for (int i = 0; i < correct.length(); i++)
    {
        char curr = correct[i];
        for (int j = 0; j < len; j++)
        {
            if (guess[j] == curr)
                actual[i] = curr;
        }
    }
    cout << actual << endl;
    if (actual == correct)
        return true;
    return false;
}

bool check(string word, char t)
{
    for (int i = 0; i < word.length(); i++)
        if (word[i] == t)
            return true;
    return false;
}

void printArr(char arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i];
    cout << endl;
}

int main()
{
    int flag = 1;
    int miss = 0;
    string words[] = {"shreyans", "shruti", "sangeeta", "gautam", "sneha", "gayatri", "meenal", "ankit", "sushmita", "pulkit", "palak", "surbhi", "pranjal", "khushbu", "raj", "sakshi", "vishakha", "disha", "kartik"};
    int len = sizeof(words) / sizeof(words[0]);
    srand(time(0));
    int num = (rand() % (len - 1 + 1)) + 1;
    char inGuess[6];
    int nextIn = 0;
    char cGuess[len];
    int nextC = 0;
    string correct = words[num - 1];
    len = correct.length();
    char g;
    while (flag)
    {
        cout << "Incorrect Guesses: " << miss << endl;
        printArr(inGuess, nextIn);
        printHangman(miss);
        if (remWords(correct, cGuess, nextC))
        {
            cout << "Congratulations!" << endl;
            break;
        }
        cout << "\nCorrect Guesses: ";
        printArr(cGuess, nextC);
        cout << "\nEnter Guess: ";
        cin >> g;
        if (num == len + 1)
            flag = 0;
        if (check(correct, g))
        {
            cGuess[nextC] = g;
            nextC++;
        }
        else
        {
            inGuess[nextIn] = g;
            nextIn++;
            miss++;
        }
        if (miss >= 6)
        {
            cout << "OOPS, you have lost!" << endl;
            cout << "The word was: " << correct << endl;
            printHangman(miss);
            flag = 0;
        }
    }
    return 0;
}