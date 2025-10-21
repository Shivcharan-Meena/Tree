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
//checking with height function Time Complexity O(n^2)
bool Balaced(Node*root){
    if(root==NULL){
        return true;
    }
    bool through_root = abs(Height(root->left) - Height(root->right)) <= 1;
    bool left = Balaced(root->left);
    bool right = Balaced(root->right);
    return left &&right&& through_root;
}

//calculating diameter of Tree with Time Complexity O(N)
pair<bool,int> Balanced_Fast(Node*root){

        if(root==NULL){
            return make_pair(1,0); //wether balaced or not ,height;
        }

        pair<bool,int> left=Balanced_Fast(root->left);
        pair<bool,int> right=Balanced_Fast(root->right);

        bool op1=left.first;
        bool op2=right.first;
        bool op3=abs(left.second-right.second)<=1;
        pair<bool,int>ans;
        ans.first=op1 && op2 && op3;
        ans.second=max(left.first,right.first)+1;
        return ans;
}

int Balanced(Node*root){
   
     return Balanced_Fast(root).first;
}

int main(){
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1 Balanced Tree
     // 1 2 3 4 -1 -1 -1 -1 -1 UnBalanced Tree
    root=build(root);
    cout<<endl;
    if(Balaced(root)){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is unbalaced"<<endl;
    }
}