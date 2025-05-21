#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    }
};
void nested(){
    
}

void build(Node*&root,int val){
    if(root==NULL){
        root=new Node(val);
        return;
    }
    
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
    Node*temp=q.front();
    q.pop();
    if(temp->left==NULL){
        temp->left=new Node(val);
        break;
    }
    else{
        q.push(temp->left);
    }
    if(temp->right==NULL){
        temp->right=new Node(val);
        break;
    }
    else{
        q.push(temp->right);
    }
   }

}
void InOrder(Node*root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void deletion(Node* root, int val) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    Node* target = NULL;
    Node* deepest = NULL;
    Node* parentOfDeepest = NULL;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == val) {
            target = temp;
        }

        if (temp->left) {
            parentOfDeepest = temp;
            q.push(temp->left);
        }

        if (temp->right) {
            parentOfDeepest = temp;
            q.push(temp->right);
        }

        deepest = temp;
    }

    if (target == NULL) {
        cout << "Value not found in the tree" << endl;
        return;
    }

    // Replace target's data with deepest node's data
    target->data = deepest->data;

    // Now delete the deepest node
    if (parentOfDeepest) {
        if (parentOfDeepest->left == deepest) {
            delete parentOfDeepest->left;
            parentOfDeepest->left = NULL;
        } else if (parentOfDeepest->right == deepest) {
            delete parentOfDeepest->right;
            parentOfDeepest->right = NULL;
        }
    } else {
        // If root is the only node
        delete root;
        root = NULL;
    }
}

//Function to find height of  a tree

int height(Node*root){
    if(root==NULL){
        return 0;
    }
     int lheight=height(root->left);
     int rheight=height(root->right);
     return max(lheight,rheight)+1;
}
pair<int,int> diameter_fast(Node*root){
    if(root==NULL){     
        pair<int,int>p=make_pair(0,0) ;
        return p;
    }
    pair<int,int>left=diameter_fast(root->left);
    pair<int,int>right=diameter_fast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3)); //diameter
    ans.second=max(left.second,right.second)+1; //height
    return ans;
}

int diameter_fisat(Node*root){
    pair<int,int>p=diameter_fast(root);
    return p.first;
}

int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
    return max(op3,max(op1,op2));
}
pair<bool,int> balanced_fast(Node*root){
    if(root==NULL){
        pair<bool,int>p=make_pair(1,0);
        return p;
    }
    pair<bool,int>left=balanced_fast(root->left);
    pair<bool,int>right=balanced_fast(root->right);
    bool leftbal=left.first;
    bool rightbal=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if(leftbal&&rightbal&&diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;

}
bool isBalanced(Node*root){
    //if left subtree and right subtree's height's diffrence is <=1 
    if(root==NULL){
        return true;
    }
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left&&right&&diff){
        return true;
    }
    else{
        return false;
    }
}

bool isIdentical(Node*root1,Node*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL||root2==NULL){
        return false;
    }
    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);
    return (root1->data==root2->data&&left&&right);
}   

int main(){
                          
Node*root=NULL;
build(root,1);
build(root,2);
build(root,3);
build(root,4);
build(root,5);
build(root,6);
build(root,7);
build(root,8);
InOrder(root);
cout<<endl;
cout<<"After Deletion"<<endl;
// deletion(root,3);
InOrder(root);
cout<<endl;
cout<<"Height of Binary tree is "<< height(root)<<endl;
cout<<"Diameter of tree is(Time complexity is O(n^2)):"<<diameter(root)<<endl;
cout<<"Diameter of tree is(Time complexity is O(n)):"<<diameter_fisat(root)<<endl;
cout<<isBalanced(root)<<endl;
    return 0;
}