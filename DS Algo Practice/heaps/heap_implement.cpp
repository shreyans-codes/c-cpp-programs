/*
For 0 based indexing:
    Left Child = (2*i)+1
    Right Child = (2*i)+2
For 1 based indexing:
    Left Child = 2*i
    Right Child = (2*i)+1
*/

#include <bits/stdc++.h>
using namespace std;

class heap
{
private:
    int *arr;
    int size;
    int curr = 0;

public:
    void insert(int x)
    {
        curr++;
        if (curr <= size)
        {
            arr[curr] = x;
            int parent = curr;
            parent /= 2;
            int index = curr;
            while (parent >= 1)
            {
                if (arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                    parent /= 2;
                }
                else
                    break;
            }
            printHeap();
        }
        else
            cout << "Heap full!" << endl;
    }
    void deleteFromHeap()
    {
        if (curr == 0)
        {
            cout << "Heap empty!" << endl;
            return;
        }
        // It will always delete the root node
        // Swapping the root with last node to preserve it
        cout << "Removing " << arr[1] << endl;
        arr[1] = arr[curr];
        // Removing the last node
        curr--;
        int index = 1;
        heapify(1);
        // while (index <= curr)
        // {
        //     int leftChild = 2 * index;
        //     int rightChild = (2 * index) + 1;
        //     int child;
        //     if (leftChild > curr || rightChild > curr)
        //         break;
        //     if (arr[leftChild] >= arr[rightChild])
        //         child = leftChild;
        //     else
        //         child = rightChild;
        //     if (arr[child] > arr[index])
        //     {
        //         swap(arr[index], arr[child]);
        //     }
        //     else
        //         break;
        //     index = child;
        // }
        cout << "After removing: " << endl;
        printHeap();
    }
    void heapify(int index)
    {
        int leftChild = 2 * index;
        int rightChild = (2 * index) + 1;
        int child;
        if (leftChild > curr || rightChild > curr)
            return;
        if (arr[leftChild] >= arr[rightChild])
            child = leftChild;
        else
            child = rightChild;
        /*
           we replace the current node with its largest child
           and then call heapify with
           index = child (which now holds the parent)
        */
        if (arr[child] > arr[index])
        {
            swap(arr[index], arr[child]);
            heapify(child);
        }
    }
    void heapifyCustom(int *temp, int s, int index)
    {
        int leftChild = 2 * index;
        int rightChild = (2 * index) + 1;
        int child;
        if (leftChild > s || rightChild > s)
            return;
        if (temp[leftChild] >= temp[rightChild])
            child = leftChild;
        else
            child = rightChild;
        /*
           we replace the current node with its largest child
           and then call heapify with
           index = child (which now holds the parent)
        */
        if (temp[child] > temp[index])
        {
            swap(temp[index], temp[child]);
            heapifyCustom(temp, s, child);
        }
    }
    void heapSort()
    {
        int temp[size + 1];
        copy(arr + 0, arr + size + 1, temp);
        int i = size;
        while (i >= 1)
        {
            swap(temp[i], temp[1]);
            i--;
            heapifyCustom(temp, i, 1);
        }
        cout << "Sorted Heap: ";
        for (int i = 1; i <= size; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    void printHeap()
    {
        if (curr == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 1; i <= curr; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    heap(int s)
    {
        size = s;
        // 1 based indexing, so we insert -1 at arr[0], we don't need that space
        arr = new int[size + 1];
        arr[0] = -1;
    }

    ~heap() {}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    heap hp = heap(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hp.insert(x);
    }
    hp.heapSort();
    for (int i = 0; i < n; i++)
    {
        hp.deleteFromHeap();
    }
    return 0;
}