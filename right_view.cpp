#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *Build(Node *root)
{
    int n;
    cout << "Enter data:";
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    if (root == NULL)
    {

        root = new Node(n);
    }

    cout << "Enter data for left of " << root->data;
    root->left = Build(root->left);
    cout << "Enter data for right of " << root->data;
    root->right = Build(root->right);
    return root;
}

void solve(Node*root,vector<int>&ans,int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right,ans,lvl+1);
    solve(root->left,ans ,lvl+1);
    
}
void right_view(Node*root){
    if(root==NULL){
        return ;
    }

    vector<int>ans;
    solve(root,ans,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
   Node* root=NULL;
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=Build(root);
    cout<<"Left view of tree is"<<endl;
    right_view(root);
    return 0;

}