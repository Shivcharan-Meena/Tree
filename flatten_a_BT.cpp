//https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

//here we are using morris travesal for O(n)time complexety and O(1) space complexeity

#include<iostream>
using namespace std;

class Node{
    public:
  int data;
  Node*left;
  Node*right;
  Node(int data){
    this->data=data;
    this->left=NULL;
    right=nullptr;
  }
};
  void flatten(Node*root){
    Node*curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node*pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL; //left part NULL
        }
        curr=curr->right;
    }
  
  }

  Node* Build(Node*root){
    int va;
    cin>>va;
    if(va==-1)return NULL;
    root=new Node(va);
    cout<<"Enter left child of "<<root->left<<endl;
    root->left=Build(root->left);
    cout<<"ENter right child of "<<root->right<<endl;
    root->right=Build(root->right);
    return root;
  }

  int main(){
    Node*root=NULL;
    root=Build(root);
    flatten(root);
  }