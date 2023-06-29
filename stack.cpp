#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;
    set<pair<int, int>> mini;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            arr[++top] = data;
            mini.insert({data, top});
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            mini.erase({arr[top], top});
            top--;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    int getMin(){
        if(mini.size()==0)
            return -1;
        auto it = mini.begin();
        return (*it).first;
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

void solve()
{
    Stack st(5);
    st.push(98);
    st.push(77);
    st.push(34);
    st.push(82);

    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;

    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;
    
}

int main()
{
    solve();
}