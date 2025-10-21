#include <iostream>
#include <queue>
#include<map>
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

//Method 1
void top_view(Node*root){
    if(root==NULL){
        return;
    }

    Node*curr=root->left;
    vector<int>temp;
    while(curr){
        temp.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=NULL;
    }
    for(int i=temp.size()-1;i>=0;i--){
        cout<<temp[i]<<" ";
    }
    cout<<root->data<<" ";
    curr=root->right;
    while(curr){
        cout<<curr->data<<" ";
        if(curr->right) curr=curr->right;
        else curr=NULL;

    }
}


//Method 2
void Top_view(Node* root) {
    if (root == NULL) return;

    map<int, int> topNode;  // stores first node at each horizontal distance
    queue<pair<Node*, int>> q;  // node and its horizontal distance

    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // if this horizontal distance is seen for the first time
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)  q.push({frontNode->left, hd - 1});
        if (frontNode->right) q.push({frontNode->right, hd + 1});
    }

    // print top view
    for (auto i : topNode) {
        cout << i.second << " ";
    }
}


int main(){
    Node *root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    //  1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    root=Build(root);
    cout<<"Top veiw of the tree is "<<endl;
    // top_view(root);
    Top_view(root);
}