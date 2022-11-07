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

class MyQueue
{
private:
    int *arr;
    int top = 0;
    int size, front = 0, rear = 0;

public:
    int push(int data)
    {
        if (rear == size)
            return -1;
        arr[rear] = data;
        rear++;
        return arr[rear - 1];
    }
    int pop()
    {
        if (rear == 0)
            return -1;
        else if (rear == (front + 1))
        {
            cout << "Here" << endl;
            int temp = arr[front];
            rear = 0;
            front = 0;
            return temp;
        }
        front++;
        return arr[front - 1];
    }
    int first()
    {
        if (rear == 0)
            return -1;
        return arr[front];
    }
    int last()
    {
        if (rear == 0)
            return -1;
        return arr[rear - 1];
    }
    bool isEmpty()
    {
        return rear == 0;
    }
    MyQueue(int s)
    {
        arr = new int[s];
        size = s;
    }
    ~MyQueue() {}
};

int main()
{
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;
    MyQueue s = MyQueue(size);
    int choice = 1;
    while (choice)
    {
        cout << "1. Push\n2. Pop\n3. First\n4. Last\n5. Is Empty?\n0. Exit\n\nYour choice: ";
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
            cout << s.first() << endl;
            break;
        case 4:
            cout << s.last() << endl;
            break;
        case 5:
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