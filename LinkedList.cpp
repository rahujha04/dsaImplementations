#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
    }

    // Node *addFront(Node *head, int val){
    //     Node *newNode = new Node(val);
    //     newNode->next = head;
    //     head = newNode;
    //     return head;
    // }

    void addFront(Node **head_ref, int val){
        Node* newNode = new Node(val);
        newNode->next = *head_ref;
        *head_ref = newNode;
    }

    void printList(Node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
};

int main(){
    Node *head = NULL;

    // head = head->addFront(head, 5);
    // head = head->addFront(head, 7);
    // head = head->addFront(head, 9);
    // head = head->addFront(head, 2);
    // head = head->addFront(head, 1);
    
    head->addFront(&head, 5);
    head->addFront(&head, 8);
    head->addFront(&head, 3);
    head->addFront(&head, 1);
    head->addFront(&head, 2);
    head->addFront(&head, 9);


    head->printList(head);


}

