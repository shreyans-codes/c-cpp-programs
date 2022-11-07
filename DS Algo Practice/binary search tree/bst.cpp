/*
    * कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    * मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    ! Karmanye vadhikaraste Ma Phaleshu Kadachana,
    ! Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    ? The meaning of the verse is :—
    ? You have the right only to work but never to its fruits.
    ? Let not the fruits of action be your motive, nor let your attachment be to
    ? inaction
*/
#include <bits/stdc++.h>

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
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    //* kuch bhi hoe, return toh root hi hona chahiye na
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        //? update root to point to new tree
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
            q.pop();
        }
        cout << endl;
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
        preOrder(root->left);
    if (root->right)
        preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
    cout << root->data << " ";
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

bool searchBST(Node *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    if (root->data > data)
        return searchBST(root->left, data);
    else
        return searchBST(root->right, data);
}

int findMin(Node *root)
{
    if (root->left != NULL)
        return findMin(root->left);
    return root->data;
}

int findMax(Node *root)
{
    if (root->right != NULL)
        return findMax(root->right);
    return root->data;
}

pair<int, int> findMinMax(Node *root)
{
    return {findMin(root), findMax(root)};
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;
    if (root->data == data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if (root->left != NULL && root->right != NULL)
        {
            int minVal = findMin(root->right);
            root->data = minVal;
            root->right = deleteNode(root->right, minVal);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, data);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = NULL;
    takeInput(root);
    // preOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // levelOrder(root);
    int data;
    // cout << "Enter data to search: ";
    cin >> data;
    if (searchBST(root, data))
        cout << "Found the element" << endl;
    else
        cout << "Not found" << endl;
    if (root != NULL)
    {
        pair<int, int> minMax = findMinMax(root);
        cout << "Min = " << minMax.first << endl;
        cout << "Max = " << minMax.second << endl;
    }
    // cout << "Enter data to delete: ";
    cin >> data;
    deleteNode(root, data);
    levelOrder(root);
    return 0;
}