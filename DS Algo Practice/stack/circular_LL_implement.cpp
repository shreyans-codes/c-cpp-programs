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

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class CLL
{
private:
    Node *head = NULL;

public:
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = newNode;
            return;
        }
        Node *tail = findTail();
        tail->next = newNode;
        newNode->next = head;
    }
    Node *findTail()
    {
        if (head == NULL)
            return NULL;
        Node *tail = head->next;
        set<Node *> store;
        store.insert(head);
        while (store.find(tail->next) == store.end())
        {
            tail = tail->next;
        }
        return tail;
    }
    void popAtBack()
    {
        if (head == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }
        Node *tail = findTail();
        Node *prev = head;
        while (prev->next != tail)
            prev = prev->next;
        prev->next = head;
        free(tail);
    }
    void displayCLL()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }
        cout << head->data << " - ";
        Node *curr = head->next;
        while (curr != head)
        {
            cout << curr->data;
            if (curr->next != head)
                cout << " - ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CLL list1;
    list1.push(3);
    list1.push(4);
    list1.displayCLL();
    list1.popAtBack();
    list1.displayCLL();
    list1.popAtBack();
    list1.popAtBack();
    return 0;
}