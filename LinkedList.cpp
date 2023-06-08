#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
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

    void addMiddle(Node **head_ref, int val, int pos){
        if(pos==1){addFront(head_ref, val);return;}
        Node* newNode = new Node(val);
        Node* travel = *head_ref;
        pos--;
        while(--pos){
            travel = travel->next;
        }
        newNode->next = travel->next;
        travel->next = newNode;
    }

    void addEnd(Node **head_ref, int val){
        if(*head_ref == NULL)*head_ref = new Node(val);
        else{
            Node* newNode = new Node(val);
            Node* travel = *head_ref;
            while(travel->next!=NULL){
                travel = travel->next;
            }
            travel->next = newNode;
        }
    }

    void deleteNode(Node **head_ref, int key){
        Node* travel = *head_ref;

        if(travel->data == key){
            *head_ref = travel->next;
            delete(travel);
            return;
        }

        while(travel->next->data!=key){
            travel = travel->next;
        }

        Node* to_delete = travel->next;

        travel->next = travel->next->next;

        delete(to_delete);
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

    head->addEnd(&head, 70);

    head->addMiddle(&head, 60, 4);

    head->addMiddle(&head, 20, 1);

    head->printList(head);

    head->deleteNode(&head, 9);
    
    head->deleteNode(&head, 20);

    head->deleteNode(&head, 70);

    head->printList(head);


}

