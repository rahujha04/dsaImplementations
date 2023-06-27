#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    int *arr;
    int sz;
    int capacity;

public:
    Heap(int capacity)
    {
        this->capacity = capacity;
        sz = 0;
        arr = new int[capacity];
    };

    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return abs(i - 1) / 2;
    }

    void insert(int val)
    {
        // Time complexity -> O(Height of Binary Tree) or O(logN)

        if (sz == capacity)
        {
            cout << "Heap Overflowed" << endl;
            return;
        }
        arr[sz] = val;
        int index = sz;
        while (index)
        {
            int par = parent(index);
            if (arr[par] > arr[index])
            {
                swap(arr[par], arr[index]);
                index = par;
            }
            else
                break;
        }
        sz++;
    }

    void Heapify(int i)
    {
        // compare node with it's left and right child and choose the minimum amongst them
        int smallest = i;
        int leftChild = left(i);
        int rightChild = right(i);
        if (leftChild < sz && arr[leftChild] < arr[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < sz && arr[rightChild] < arr[smallest])
        {
            smallest = rightChild;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            Heapify(smallest);
        }
    }

    int getMin()
    {
        return arr[0];
    }

    int ExtractMin()
    {
        // Remove the minimum element in heap

        // Time complexity: O(log(N))

        int top = arr[0];
        swap(arr[0], arr[sz - 1]);
        sz--;
        Heapify(0);
        return top;
    }

    void changeElement(int i, int val)
    {
        arr[i] = val;
        while (i)
        {
            int par = parent(i);
            if (arr[par] > arr[i])
            {
                swap(arr[par], arr[i]);
                i = par;
            }
            else
            {
                Heapify(i);
                break;
            }
        }
    }

    void Delete(int i){
        changeElement(i, INT_MIN);
        ExtractMin();
    }

    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Heap minHeap(10);
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(40);
    minHeap.insert(50);
    minHeap.insert(100);
    minHeap.insert(25);
    minHeap.insert(45);
    minHeap.insert(12);

    minHeap.print();

    // cout << minHeap.getMin() << endl;

    // cout<<minHeap.ExtractMin()<<endl;

    // minHeap.print();

    // cout << minHeap.ExtractMin() << endl;

    // minHeap.changeElement(1, 72);

    // minHeap.print();

    minHeap.Delete(1);

    minHeap.print();
}

// Binary Heap is a complete binary tree

// left(i) = 2*i + 1
// right(i) = 2*i + 2
// parent(i) = |i-1|/2
