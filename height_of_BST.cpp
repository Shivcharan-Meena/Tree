#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;
        Node(int data){
            this->data=data;
            this->right=NULL;
            this->left=NULL;
        }
};

Node* build(Node*root){
    int n;
    cout<<"Enter data : ";
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

void display(Node*root){
    if(root==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right) q.push(temp->right);
        }

    }
}

//Height of Tree by BFS
int Height(Node*root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
        
            ans++;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            if(temp->left) {q.push(temp->left);}
            if(temp->right) {q.push(temp->right);}
        }
    }

    return ans;
}

//Height of Tree  by recursion

// int Height(Node*root){
//     if(root==NULL){
//         return 0;
//     }
//     int left=Height(root->left);
//     int right=Height(root->right);
//     return 1+max(left,right);
// }

int main(){
    Node*root=NULL;
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=build(root);
    cout<<endl;
    display(root);
    cout<<endl<<"Height of the Tree is "<<Height(root)<<endl;
    return 0;
}