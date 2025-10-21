#include<iostream>
#include<algorithm>
#include<vector>
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


/* code1*/
    //leaf nodes print
    void Leaf_Nodes(Node*root){
        if(root==NULL){
            return;
        }
        Leaf_Nodes(root->left);
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" ";
        }
        Leaf_Nodes(root->right);
    }

void Boundary_Traversal(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    //left part print
    Node*curr=root->left;
    while(curr){
        if(curr->left || curr->right){
            cout<<curr->data<<" ";
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }


    Leaf_Nodes(root->left);
    //right subtree
    Leaf_Nodes(root->right);

    //right part print
    vector<int>v;
    curr=root->right;
    while(curr){
        if(curr->left || curr->right){
            v.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}


int main(){
    Node*root=NULL;
    root=build(root);
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1 Balanced Tree
    Boundary_Traversal(root);
    return 0;
}