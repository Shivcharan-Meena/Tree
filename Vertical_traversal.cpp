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




void verticalOrder(Node*root){
    map<int,map<int,vector<int> > > nodes; // Horizontal_distance,<map<level,vector of nodes at that level>>
    queue<pair<Node*,pair<int,int>>>q;
    //queue<pair of Node and pair of level and horizontal distance>
    if(root==NULL) return;

    q.push({root,make_pair(0,0)});

    while(!q.empty()){
        Node*frontNode=q.front().first;
        int hd=q.front().second.first;
        int lvl=q.front().second.second;
        q.pop();
        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left) q.push({frontNode->left,make_pair(hd-1,lvl+1)});

        if(frontNode->right) q.push({frontNode->right,make_pair(hd+1,lvl+1)});



    }

    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                cout<<k<<" ";
            }
        }
        cout<<endl;
    }
}


int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root = Build(root);
    cout << "Displaying data" << endl;
    verticalOrder(root);
}