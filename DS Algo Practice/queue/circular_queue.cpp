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
using namespace std;

class MyQueue
{
private:
    int *arr;
    int rear;
    int front;
    int size;

public:
    void enqueue(int data)
    {
        if (rear == -1)
        {
            rear = 0;
            front = 0;
            arr[rear] = data;
            rear++;
            return;
        }
        if (rear == size)
        {
            if (front > 0)
            {
                rear = 0;
                arr[rear] = data;
                rear++;
            }
            else if (rear == front || front == 0)
                cout << "Overflow encountered" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }
    void dequeue()
    {
        if (front == -1 || front == rear)
        {
            cout << "Underflow encountered" << endl;
            return;
        }
        else if (front == size && front > rear)
        {
            front = 0;
            cout << "Dequeued " << arr[front] << endl;
            rear++;
            return;
        }
        cout << "Dequeued " << arr[front] << endl;
        front++;
    }
    MyQueue(int s)
    {
        size = s;
        arr = new int(s);
        rear = -1;
        front = -1;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    MyQueue q = MyQueue(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}