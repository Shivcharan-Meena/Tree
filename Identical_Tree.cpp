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

bool IsIdentical(Node*root1,Node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }

    if(root1!=NULL && root2==NULL){
        return false;
    }
    bool left=IsIdentical(root1->left,root2->left);
    bool right=IsIdentical(root1->right,root2->right);
    bool val=root1->data==root2->data;
    return val && left && right;
}
    

int main(){
    Node*root1=NULL;
    Node*root2=NULL;
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    // 1 2 3 4 -1 -1 -1 -1 -1
     cout<<"Enter data for First Tree"<<endl;
    root1=build(root1);
    cout<<endl<<endl<<"Enter data for second Tree"<<endl;
    root2=build(root2);
    cout<<endl;
    // display(root);
    if(IsIdentical(root1,root2)) cout<<endl<<" Trees are balanced"<<endl;
    else cout<<" Trees are Not balanced"<<endl;
 
    return 0;
}