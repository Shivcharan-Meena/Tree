//time complexiety:O(n) space complexeity:O(1)
//Prints tree in Inorder/Preorder
// Time Complexity: O(n), if we take a closer look, we can notice that every edge of the tree is traversed at most three times.
// Auxiliary Space: O(1)


//for Inorder
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void MorrisTraversalPostorder(Node*root){
    if(root==NULL){
        return;
    }
    vector<int>res;
    Node*curr=root;
    while(curr!=NULL){
        if(curr->right==NULL){
            res.push_back(curr->data);
            curr=curr->left;

        }
        else{
            Node*pred=curr->right;
            while(pred->left!=NULL&&pred->left!=curr){
                pred=pred->left;
            }

            if(pred->left==curr){
                pred->left=NULL;
                curr=curr->left;
            }
            else{
                res.push_back(curr->data);
                pred->left=curr;
                curr=curr->right;
            }
        }
    }
    reverse(res.begin(),res.end());
      for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
   cout<<endl;
}

vector<int> morrisPreorder(Node* root) {
    vector<int> pre;
    Node* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            pre.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pre.push_back(curr->data);   // visit before creating thread
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = NULL;          // thread break
                curr = curr->right;
            }
        }
    }
    return pre;
}


vector<int> morrisInorder(Node* root) {
    vector<int> inorder;
    Node* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = curr; //make the link
                curr = curr->left;
            }
            else {
                pred->right = NULL; //break the link
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = morrisPreorder(root);
  
     for (int data : res) {
        cout << data << " ";
    }
    
    return 0;
}