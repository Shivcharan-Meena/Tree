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

// void helper(Node*root,vector<int>&ans,int n){
//     if(root==NULL){
        
        
//         return;
//     }
//      ans.push_back(root->data);
//    if(root->data==n){
//     return;
//    }
   
  
//   helper(root->left, ans, n);
// if (!ans.empty() && ans.back() == n)
//     return;

// helper(root->right, ans, n);
// if (!ans.empty() && ans.back() == n)
//     return;

// ans.pop_back();

// }

// void help(Node*root,int n){
//     vector<int>ans;
//     helper(root,ans,n);
//     for(auto i:ans){
//         cout<<i<<" ";
//     }
// }


Node * helper(Node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1|| root->data==n2){
        return root;
    }
    Node*left1=helper(root->left,n1,n2);
    Node*right1=helper(root->right,n1,n2);
    if(left1!=NULL && right1!=NULL){
        return root;
    }
    else if(left1!=NULL && right1==NULL){
        return left1;
    }
    else if(left1==NULL && right1!=NULL){
        return right1;
    }
    else return NULL;

}


int main()
{
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=build(root);
    cout<<"Sum of longest bloodline is"<<endl;
    cout<<helper(root,6,3)->data<<endl;
}