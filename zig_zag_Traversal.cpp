#include<iostream>
#include<queue>
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

Node*Build(Node*root){
    int n;
    cout<<"Enter data:";
    cin>>n;
    if(n==-1){
        return NULL;
    }
    if(root==NULL){

        root=new Node(n);
    }
    
    cout<<"Enter data for left of "<<root->data;
    root->left=Build(root->left);
    cout<<"Enter data for right of "<<root->data;
    root->right=Build(root->right);
    return root;
}

void Zig_Zag_Traversal(Node*root){
    vector<int>result;
    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    
    bool leftToRight=true;

    while(!q.empty()){
        int size= q.size();
        vector<int>ans(size);

        //process all nodes of current level
        for(int i=0;i<size;i++){
        Node*temp=q.front();
        q.pop();

     
        int index= leftToRight?i:size-i-1;
        ans[index]=temp->data;
       
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        
        }
        //change the direction
        leftToRight=!leftToRight;
        for(auto i:ans){
            cout<<i<<" ";
    }
    cout<<endl;
}
}
int main(){
    Node*root=NULL;
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=Build(root);
    cout<<"Displaying data"<<endl;
    Zig_Zag_Traversal(root);
}
