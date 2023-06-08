#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

node* addNode(node* root, int data){
    while(root!=NULL){
        if(root->data > data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    root = new node(data);
    return root;
}

void inorderTraversal(node* root){
    if(root==NULL)return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    node* root = NULL;

    root = addNode(root, 1);
    root = addNode(root, 4);
    root = addNode(root, 8);
    root = addNode(root, 3);
    root = addNode(root,2);
    root = addNode(root, 7);

    inorderTraversal(root);
}