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

int Height (Node*root){
    if(root==NULL){
        return 0;
    }
    int left=Height(root->left);
    int right=Height(root->right);
    return 1+max(right,left);
}
//Calculating diameter of Tree with Time Complexity O(n^2)
int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int diameter_through_root = Height(root->left) + Height(root->right) + 1;
    int left = diameter(root->left);
    int right = diameter(root->right);
    return max(diameter_through_root, max(left, right));
}

//calculating diameter of Tree with Time Complexity O(N)
pair<int,int> Diameter_fast(Node*root){

        if(root==NULL){
            return make_pair(0,0);
        }

        pair<int,int> left=Diameter_fast(root->left);
        pair<int,int>right=Diameter_fast(root->right);

        int op1=left.first;//diameter of left subtree
        int op2=right.first;//diameter of right subtree
        int op3=left.second+right.second+1;//height of left subtree+ height of right subtree+1
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.first,right.first)+1;
        return ans;
}

int Diameter(Node*root){
   
     return Diameter_fast(root).first;
}

int main(){
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=build(root);
    cout<<endl<<"Diameter of the Tree is ";
    cout<<Diameter(root)<<endl;
}