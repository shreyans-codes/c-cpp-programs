/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right to work only but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to inaction
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
        //* Queue is empty
        if (rear == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            rear++;
            return;
        }
        //* Queue is full
        if (rear == size)
        {
            cout << "Overflow encountered!" << endl;
            return;
        }
        //* Average Case
        arr[rear] = data;
        cout << "Inserted " << data << " at " << rear << endl;
        rear++;
        return;
    }
    void dequeue()
    {
        //* Queue is empty
        if (front == -1)
        {
            cout << "Underflow encountered!" << endl;
            return;
        }
        //* Queue has only one element
        if (front == size - 1 || front + 1 == rear)
        {
            cout << "Here " << front << " ";
            cout << "Dequeued " << arr[front] << endl;
            front = rear = -1;
            return;
        }
        //* Average case
        cout << "Dequeued " << arr[front] << endl;
        front++;
    }
    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
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
    int size;
    cin >> size;
    MyQueue q = MyQueue(size);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
}