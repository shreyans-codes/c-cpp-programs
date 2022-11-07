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
public:
    Node *top = NULL;
    void push(int data)
    {
        if (top == NULL)
        {
            top = new Node(data);
            return;
        }
        Node *temp = new Node(data);
        top->next = temp;
        temp->prev = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
            return;
        if (top->prev == NULL)
        {
            top = NULL;
            return;
        }
        Node *temp = top->prev;
        temp->next = NULL;
        top = temp;
    }
    int peek()
    {
        if (top == NULL)
            return 0;
        return top->data;
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
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}