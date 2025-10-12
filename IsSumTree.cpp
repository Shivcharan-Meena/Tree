#include<iostream>
#include<algorithm>
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

pair<bool,int>IsSumTree_Fast(Node*root){
        if(root==NULL){
            pair<bool,int>p= make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){ 
             pair<bool,int>p= make_pair(true,root->data);
            return p;
        }

        pair<bool,int>leftans=IsSumTree_Fast(root->left);
        pair<bool,int>rightans=IsSumTree_Fast(root->right);

        bool left=leftans.first;
        bool right=rightans.first;
        bool condn=root->data==leftans.second+rightans.second;
        pair<bool,int>ans;
        ans.first=condn && left && right;
        ans.second=root->data+leftans.second+rightans.second;
        return ans;
}

void IsSumTree(Node*root){
    if(IsSumTree_Fast(root).first){
        cout<<"Tree is SumTree"<<endl;
    }
    else cout<<"Tree is Not SumTree"<<endl;
}


int main(){
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1 Balanced Tree
     // 1 2 3 4 -1 -1 -1 -1 -1 UnBalanced Tree
    root=build(root);
    cout<<endl;
    IsSumTree(root);
}