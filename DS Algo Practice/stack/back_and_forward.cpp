#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> backStack;
    stack<string> nextStack;
    string curr;
    cout << "Enter the current address: ";
    cin >> curr;
    int choice = 1;
    string temp;
    while (choice != 0)
    {
        cout << "1. Move Forward\n2. Move Backward\n3. Show current address\n";
        cout << "4. Show previous address\n5. Show next address\n0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (!nextStack.empty())
            {
                backStack.push(curr);
                curr = nextStack.top();
                nextStack.pop();
                cout << "Moved to: " << curr << endl;
            }
            else
            {
                backStack.push(curr);
                cout << "Enter address to move to: ";
                cin >> curr;
                cout << "Moved to: " << curr << endl;
            }
            break;
        case 2:
            if (!backStack.empty())
            {
                nextStack.push(curr);
                curr = backStack.top();
                backStack.pop();
                cout << "Moved to: " << curr << endl;
            }
            else
            {
                cout << "Backward Stack is empty, staying on " << curr << endl;
            }
            break;
        case 3:
            cout << "Current address: " << curr << endl;
            break;
        case 4:
            if (!backStack.empty())
                cout << "Previous address: " << backStack.top() << endl;
            else
                cout << "Backward Stack is empty" << endl;
            break;
        case 5:
            if (!nextStack.empty())
                cout << "Next address: " << nextStack.top() << endl;
            else
                cout << "Forward Stack is empty" << endl;
            break;
        case 0:
            cout << "Thank You!" << endl;
            break;
        default:
            cout << "Error encountered" << endl;
            break;
        }
    }
    return 0;
}