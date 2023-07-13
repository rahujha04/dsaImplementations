#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int *arr;
        int size;
        int capacity;

        Heap(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            size = 0;
        }

        int left(int i) {return (2 * i + 1);}
        int right(int i) {return (2 * i + 2);}
        int parent(int i) {return ((i - 1) / 2);}

        void insert(int data){
            if(size == capacity){
                cout << "Heap Overflow" << endl;
                return;
            }

            int ind = size;

            arr[size++] = data;

            while(ind>0){
                int par = parent(ind);
                if(arr[par] > arr[ind]){
                    swap(arr[par], arr[ind]);
                    ind = par;
                }else
                    break;
            }

        }

        void Heapify(int ind){
            if(ind >= size)
                return;

            int smallest = ind;
            int leftChild = left(ind);
            int rightchild = right(ind);

            if(leftChild < size && arr[leftChild] < arr[smallest]){
                smallest = leftChild;
            }
            if(rightchild < size && arr[rightchild] < arr[smallest]){
                smallest = rightchild;
            }

            if(smallest==ind)
                return;
            swap(arr[smallest], arr[ind]);
            Heapify(smallest);
        }

        int getMin(){
            return arr[0];
        }

        int extractMin(){
            if(size==0){
                cout << "Heap Underflow" << endl;
                return -1;
            }
            int top = arr[0];
            arr[0] = arr[size - 1];
            size--;
            Heapify(0);
            return top;
        }

        void decreaseKey(int key, int val){
            arr[key] = val;
            int ind = key;
            while(ind>0){
                int par = parent(ind);
                if(arr[par] > val){
                    swap(arr[par], arr[ind]);
                    ind = par;
                }else{
                    break;
                }
            }
        }
        
        void Delete(int key){
            // decreaseKey(key, -infinity) + extractMin()
            decreaseKey(key, -1e9);
            extractMin();
        }

        void print(){
            cout << "The Heap Elements are as follows: " << endl;
            for (int i = 0;i<size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};



void HeapifyFunction(int *brr, int ind, int size){
    if (ind >= size)
        return;

    int smallest = ind;
    int leftChild = (2 * ind + 1);
    int rightchild = (2 * ind + 2);

    if (leftChild < size && brr[leftChild] < brr[smallest])
    {
        smallest = leftChild;
    }
    if (rightchild < size && brr[rightchild] < brr[smallest])
    {
        smallest = rightchild;
    }

    if (smallest == ind)
        return;
    swap(brr[smallest], brr[ind]);
    HeapifyFunction(brr, smallest, size);
}

void BuildHeap(int *arr, int n)
{
    int size = n;
    int lastNode = size - 1;
    int par = (lastNode - 1) / 2;
    for (int i = par; i >= 0; i--)
    {
        HeapifyFunction(arr, i, size);
    }
}

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

        // Heap h(12);
        // h.insert(40);
        // h.insert(20);
        // h.insert(30);
        // h.insert(35);
        // h.insert(25);
        // h.insert(80);
        // h.insert(32);
        // h.insert(100);
        // h.insert(70);
        // h.insert(60);

        // h.print();

        // h.decreaseKey(3, 5);

        // h.Delete(4);

        // h.print();


        // h.insert(12);

        // h.print();

        // cout<<h.getMin()<<endl;

        // cout << h.extractMin() << endl;

        // h.print();

        // BuildHeap: Given an array which have elements in any random order, You will have to make a min Heap from it

        // start the BuildHeap function from the parent of the last node that is |(size - 1) - 1/2|;

        // The Time Complexity of BuildHeap function is O(n)

        int brr[] = {5, 8, 22, 34, 99, 78, 11, 9};

        BuildHeap(brr, 8);

        printArray(brr, 8);
}