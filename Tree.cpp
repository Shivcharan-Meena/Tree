
#include <iostream>
#include <queue>
#include <stack>
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

Node *buildTree(Node *root)
{
    cout << "Enter data:";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void BFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void ReverseBFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
                s.push(-1); // Marker for new level
            }
        }

        else
        {
            s.push(temp->data);

            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    while (!s.empty())
    {
        if (s.top() == -1)
        {
            cout << endl;
            s.pop();
        }
        else
        {

            cout << s.top() << " ";
            s.pop();
        }
    }
}




void PreOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void iterativeInorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || !s.empty())
    {
        // Reach the leftmost node
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        // Current is NULL, pop from stack
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        // Go to right subtree
        curr = curr->right;
    }
}

void iterativePostorder(Node *root)
{
    if (!root)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}


// void iterativePreorder(Node *root)
// {
//     if (!root)
//         return;

//     stack<Node *> s1;
//     queue<Node *> q;
//     s1.push(root);

//     while (!s1.empty())
//     {
//         Node *curr = s1.top();
//         s1.pop();
//         q.push(curr);

//         if (curr->right)
//             s1.push(curr->right);
//         if (curr->left)
//             s1.push(curr->left);
//     }

//     while (!q.empty())
//     {
//         cout << q.front()->data << " ";
//         q.pop();
//     }
// }


void iterativePreorder(Node* root) {
    if (!root) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void BuildFromBFS(Node*&root){
    queue<Node*>q;
    cout<<"Enter data:";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        int leftdata;
        cout<<"Enter data for left of "<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter data for right of "<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }

    }
}

// int leafNodes(Node*root){
//     queue<Node*>q;
//     int sum=0;
//     q.push(root);
//     while(!q.empty()){
//         Node*temp=q.front();
//         q.pop();

//         if(temp->left) q.push(temp->left);
//         if(temp->right) q.push(temp->right);

//         if(temp->left==NULL && temp->right==NULL) sum+=1;
//     }

//     return sum;
// }

Node*InOrderTraversalhelper(Node*root,int &count){
    if(root==NULL){
        return NULL;
    }
     InOrderTraversalhelper(root->left,count);
     if(root->left==NULL && root->right==NULL) count++;
     InOrderTraversalhelper(root->right,count );
     return root;
}

int leafNodes(Node*root){
    int count=0;
    InOrderTraversalhelper(root,count);
    return count;
}

int main()
{
    // Node *root = NULL;
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);
    // cout << "Level order traversel" << endl;
    // BFS(root);
    // cout << " Reverse Level order traversel" << endl;
    // ReverseBFS(root);
    // cout << endl;

    // cout << "PreorderTraversal" << endl;
    // PreOrderTraversal(root);
    // cout << endl<< "Iterative Preorder Traversal" << endl;
    // iterativePreorder(root);

    // cout << endl<<"PostorderTraversal" << endl;
    // PostOrderTraversal(root);
    // cout << endl<< "Iterative Postorder Traversal" << endl;
    // iterativePostorder(root);

    // cout << endl<<"InOrderTraversal" << endl;
    // InOrderTraversal(root);
    // cout << endl
    //      << "Iterative Inorder Traversal" << endl;
    // iterativeInorder(root);
    // cout << endl;



    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    Node*root=NULL;
    BuildFromBFS(root);
    cout << "Level order traversel" << endl;
    BFS(root);
    cout<<endl;
    cout << " Reverse Level order traversel" << endl;
    ReverseBFS(root);
    cout<<endl<<"Total Leaf Nodes are ";
    cout<<leafNodes(root)<<endl;;
    return 0;
}