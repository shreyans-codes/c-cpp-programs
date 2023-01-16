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
    cout << "Enter node values [use -1 to stop]" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        //? update root to point to new tree
        root = insertIntoBST(root, data);
        cin >> data;
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
    Node *root = NULL;
    takeInput(root);
    if (root != NULL)
    {
        pair<int, int> minMax = findMinMax(root);
        cout << "Min = " << minMax.first << endl;
        cout << "Max = " << minMax.second << endl;
    }

    int data;
    cout << "Enter data to delete: ";
    cin >> data;
    cout << "Pre order before deletion: " << endl;
    preOrder(root);
    cout << endl;
    deleteNode(root, data);
    cout << "Pre order after deletion: " << endl;
    preOrder(root);
    return 0;
}