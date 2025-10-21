#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*build(Node*root){
    cout<<"Enter data ";
    int n;
    cin>>n;
    if(n==-1){
        return NULL;
    }
    if(root==NULL){
        root=new Node(n);
    }

    cout<<"Enter data to the left of "<<root->data<<endl;
    root->left=build(root->left);
    cout<<"Enter data to the right of "<<root->data<<endl;
    root->right=build(root->right);
    return root;
}

Node* kth_ancestor(Node*root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    
    Node*lft=kth_ancestor(root->left,k,node);
    Node*rght=kth_ancestor(root->right,k,node);
    
    if(lft!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            // taki ye upper root tak keval ancestor ko hi bhejta rahe
            return root;
        }
        else return lft;
    }
    
    if(rght!=NULL){
           k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else return rght;
    }
    
    return NULL;
}


int main(){
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1 Balanced Tree
     // 1 2 3 4 -1 -1 -1 -1 -1 UnBalanced Tree
     
    root=build(root);
    int k=1;
    int node=4;
     cout<<k<<"th ancestor of "<<node<<" is "<<kth_ancestor(root,k,node)->data<<endl;
     return 0;
 
}
