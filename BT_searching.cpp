//searching 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// In-order DFS: Left, Root, Right
void inOrderDFS(Node* node) {
    if (node == nullptr) return;

    inOrderDFS(node->left);
    cout << node->data << " ";
    inOrderDFS(node->right);
}

// Pre-order DFS: Root, Left, Right
void preOrderDFS(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

// Post-order DFS: Left, Right, Root
void postOrderDFS(Node* node) {
    if (node == nullptr) return;

    postOrderDFS(node->left);
    postOrderDFS(node->right);
    cout << node->data << " ";
}

void BFS(Node* root) {

    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop(); 
        cout << node->data << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
        
    }
}

void search_BFS(Node*root,int val){
    //search by BFS Algorithm
    if(root==nullptr){
        cout<<"Tree is empty"<<endl;
        return;
    }

    if(root->data==val){
        cout<<val<<" found"<<endl;
        return;
    }

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        
        if(temp->left!=nullptr &&temp->left->data==val){
            cout<<val<<" found"<<endl;
            return;

        }
        else if (temp->left!=nullptr){
            q.push(temp->left);
        }
        if(temp->right!=nullptr &&temp->right->data==val){
            cout<<val<<" found"<<endl;
            return;
        }
        else if (temp->right!=nullptr){
            q.push(temp->right);
        }
    }
    cout<<val<<" Not found"<<endl;

}

void search_Preorder_Traversal(Node*node,int val){
    if (node == nullptr) return;
    //search by Preorder Traversal Algorithm
    if(node->data==val){

        cout << node->data <<" Found"<<endl;
        return;
    }
    search_Preorder_Traversal(node->left,val);
    search_Preorder_Traversal(node->right,val);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);

    cout << "In-order DFS: ";
    inOrderDFS(root);

    cout << "\nPre-order DFS: ";
    preOrderDFS(root);
   
    cout << "\nPost-order DFS: ";
    postOrderDFS(root);
  
    cout << "\nLevel order: ";
    BFS(root);
    cout<<endl;
    search_BFS(root,5);

    search_Preorder_Traversal(root,2);
    return 0;
}