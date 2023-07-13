#include<bits/stdc++.h>
using namespace std;


class Heap{
    public:
        int arr[100];
        int sz;

        Heap(){
            arr[0] = -1;
            sz = 0;
        }

        void insert(int val){
            sz++;
            arr[sz] = val;

            int index = sz;

            while(index>1){
                int parent = index / 2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }else{
                    break;
                }
            }
        }

        void Delete(){
            if(sz == 0){
                cout << "Nothing to delete" << endl;
                return;
            }

            arr[1] = arr[sz];
            sz--;

            int index = 1;

            while(index < sz){
                int leftChild = 2 * index;
                int rightChild = 2 * index + 1;
                
                if(leftChild <= sz && arr[leftChild] > arr[index] && arr[leftChild] > arr[rightChild]){
                    swap(arr[index], arr[leftChild]);
                    index = leftChild;
                }else if(rightChild <= sz && arr[rightChild] > arr[index] && arr[rightChild] > arr[leftChild]){
                    swap(arr[index], arr[rightChild]);
                    index = rightChild;
                }else{
                    return;
                }
            }
        }

        void print(){
            for(int i=1;i<=sz;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
        Heap h;

        h.insert(50);
        h.insert(55);
        h.insert(53);
        h.insert(52);
        h.insert(54);
        h.print();
        h.Delete();
        h.print();
}