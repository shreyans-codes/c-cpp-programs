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

//* SUCCESS
#include <bits/stdc++.h>
#include <stdio.h>

#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *mirror(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root;
    Node *leftNode = mirror(root->left);
    Node *rightNode = mirror(root->right);
    if (leftNode != NULL && rightNode != NULL)
    {
        root->left = rightNode;
        root->right = leftNode;
        return root;
    }
    if (leftNode == NULL && rightNode != NULL)
    {
        root->left = rightNode;
        root->right = NULL;
        return root;
    }
    if (leftNode != NULL && rightNode == NULL)
    {
        root->right = leftNode;
        root->left = NULL;
        return root;
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
        inOrder(root->left);
    cout << root->data << " ";
    if (root->right)
        inOrder(root->right);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Node *root = new Node(5);
    Node *temp = root;
    root->left = new Node(3);
    root->right = new Node(6);
    root = root->left;
    root->left = new Node(2);
    root->right = new Node(4);
    mirror(temp);
    inOrder(temp);
    return 0;
}