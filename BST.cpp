#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal to verify BST
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node* root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
