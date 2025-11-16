#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void buildMap(vector<int>in,int n,map<int,int>&m){
    for(int i=0;i<n;i++){
        m[in[i]]=i;
    }
}
int findPos(vector<int>in,int ele,int n){
    for(int i=0;i<n;i++){
        if(ele==in[i]){
            return i;
        }
    }
    return -1;
}

Node*InOrder_PreOrder( vector<int> &pre,  vector<int> &in,int &pre_index,int inStartIndex,int inEndIndex,int n){
    //base condition
    if(pre_index>=n || inStartIndex>inEndIndex){
        return NULL;
    }
    int ele=pre[pre_index++];
    int position=findPos(in,ele,n); //  this will take O(n) extra time so total time complexeity is O(n)
    Node*root=new Node(ele);

    root->left=InOrder_PreOrder(pre,in,pre_index,inStartIndex,position-1,n);
    root->right=InOrder_PreOrder(pre,in,pre_index,position+1,inEndIndex,n);
    return root;
}

//postOrder and Inorder
Node*Post_InOrder(vector<int> &post,  vector<int> &in,int &post_index,int inStartIndex,int inEndIndex,int n,map<int,int>&m){
      //base condition
    if(post_index<0 || inStartIndex>inEndIndex){
        return NULL;
    }
    int ele=post[post_index--];
    int position=m[ele]; //its worst case time complexity time complexeity is O(log(n)) instead use unorderd_map then total time complexity will be O(n);
    Node*root=new Node(ele);

    root->right=Post_InOrder(post,in,post_index,position+1,inEndIndex,n,m);
    root->left=Post_InOrder(post,in,post_index,inStartIndex,position-1,n,m);
    return root;
}

//LevelOrderTraversal
void BFS(Node*root){
    if(root==NULL){
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

int main(){
    vector<int>pre={1, 2, 4, 5, 3, 6};
    vector<int>in={4, 2, 5, 1, 3, 6};
    vector<int>post={4, 5 ,2 ,6, 3, 1};
    map<int,int>m;
    int n=in.size();
    buildMap(in,n,m);
    int k=n-1;
    // Node*root=InOrder_PreOrder(pre,in,k,0,n-1,n);
   Node*root= Post_InOrder(post,in,k,0,n-1,n,m);
    BFS(root);

}
