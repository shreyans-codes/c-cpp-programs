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

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack
{
private:
    Node *top = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        if (top == NULL)
        {
            top = new Node(data);
            size = 1;
            mid = top;
            return;
        }
        Node *temp = new Node(data);
        top->next = temp;
        temp->prev = top;
        top = top->next;
        if (size % 2 == 1)
            mid = mid->next;
        size++;
    }
    void pop()
    {
        int data = -1;
        if (size != 0)
        {
            data = top->data;
            if (size == 1)
            {
                top = NULL;
                mid = NULL;
            }
            else
            {
                top = top->prev;
                top->next = NULL;
                if (size % 2 == 0)
                    mid = mid->prev;
            }
            size--;
        }
    }
    int peek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }
    int peekMid()
    {
        if (mid == NULL)
            return -1;
        return mid->data;
    }
    void deleteMid()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                top = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                top = top->prev;
                mid = mid->prev;
                top->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                    mid = mid->next;
                else
                    mid = mid->prev;
            }
            size--;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.peekMid() << endl;
    st.deleteMid();
    st.deleteMid();
    cout << st.peekMid() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    cout << st.peekMid() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}