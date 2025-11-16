// finding minimum time to burn a tree.
// You are given a target node and find how much time it will take to burn the entire tree in one sec you can burn a nodes left ,right and its parent node.

#include <iostream>
#include <map>
#include <queue>
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
    int val;
    cout << "Enter a value ";
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    
        root = new Node(val);

    cout << "Enter left child of " << root->data << endl;
    root->left = Build(root->left);
    cout << "Enter right child of " << root->data << endl;
    root->right = Build(root->right);
    return root;
}
// recursively mapping
void NodeToParentMappinp(Node *root, map<Node *, Node *> &m, int ele, Node *&target)
{
    if (root == NULL)
        return;

    if (root->data == ele)
    {
        target = root;
    }

    if (root->left)
    {
        m[root->left] = root;
    }
    if (root->right)
    {
        m[root->right] = root;
    }

    NodeToParentMappinp(root->left, m, ele, target);
    NodeToParentMappinp(root->right, m, ele, target);
}
// parent child mapping by levelOrder traversal
//  void NodeToParentMapping(Node* root, map<Node*, Node*>& parent, int target, Node*& targetNode) {
//      queue<Node*> q;
//      q.push(root);
//      parent[root] = NULL;

//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         if (temp->data == target) {
//             targetNode = temp;
//         }

//         if (temp->left) {
//             parent[temp->left] = temp;
//             q.push(temp->left);
//         }
//         if (temp->right) {
//             parent[temp->right] = temp;
//             q.push(temp->right);
//         }
//     }
// }
int MinTimeToBurn(Node *root, int target)
{
    Node *tar = NULL;
    map<Node *, Node *> m;
    NodeToParentMappinp(root, m, target, tar);
    queue<Node *> q;
    int time = -1;
    q.push(tar);

    map<Node *, bool> visited;
    visited[tar] = true;

    while (!q.empty())
    {
        int size = q.size();
        time++;
        for (int i = 0; i < size; i++)
        {

            Node *temp = q.front();
            q.pop();
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (m.find(temp) != m.end())
            { // parent exists
                Node *parent = m[temp];
                if (parent && !visited[parent])
                {
                    q.push(parent);
                    visited[parent] = true;
                }
            }
        }
    }
    return time;
}

int main()
{
    Node *root = NULL;
    // 10 5 20 3 7 -1 30 -1 -1 -1 -1 -1 -1 target 20 time:3
    // 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1 target 2 time:3
    // 1 2 3 -1 -1 -1 -1 target:3 time:2
    //1 -1 2 -1 3 -1 -1  target:1 time:2
    //10 5 3 -1 -1 7 -1 -1 20 -1 30 -1 -1  target:5 time:3

    root = Build(root);
    cout << "Time to burn the tree is " << MinTimeToBurn(root, 5) << endl;
    return 0;
}