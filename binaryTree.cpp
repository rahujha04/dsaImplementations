#include<bits/stdc++.h>
using namespace std;

// struct node{
//     int data;
//     node* left;
//     node* right;

//     node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

class node{
    public: 
    int data;
    node *left, *right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void inorderTraversal(node* root){
    if(root==NULL)return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    
    node* root = new node(1);

    root->left = new node(2);

    root->left->left = new node(4);

    root->right = new node(3);

    inorderTraversal(root);

    return 0;
}