/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to
    ? inaction
*/
#include <bits/stdc++.h>
#include <stdio.h>

#define ll long long
using namespace std;

class MyStack
{
private:
    int *arr;
    int top = 0;
    int size;

public:
    int push(int data)
    {
        if (top == size)
            return -1;
        arr[top] = data;
        top++;
        return arr[top - 1];
    }
    int pop()
    {
        if (top == 0)
            return -1;
        top--;
        return arr[top];
    }
    int peek()
    {
        if (top == 0)
            return -1;
        return arr[top - 1];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    MyStack(int s)
    {
        arr = new int[s];
        size = s;
    }
    ~MyStack() {}
};

int main()
{
    int size;
    cout << "Enter size of stack: ";
    cin >> size;
    MyStack s = MyStack(size);
    int choice = 1;
    while (choice)
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n0. Exit\n\nYour choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cin >> data;
            cout << s.push(data) << endl;
            break;
        case 2:
            cout << s.pop() << endl;
            break;
        case 3:
            cout << s.peek() << endl;
            break;
        case 4:
            cout << s.isEmpty() << endl;
            break;
        case 0:
            break;
        default:
            break;
        }
    }

    return 0;
}