#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*build(Node*root){
    cout<<"Enter data ";
    int n;
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

//searchig a node k and storing its path;
//with this function we can solve our problem but with cost of O(N) space complexeity
bool search(Node* root, int k, vector<int>& v) {
    if (root == NULL) return false;

    v.push_back(root->data);

    if (root->data == k) return true; // node found

    // search left or right; stop if found
    if (search(root->left, k, v) || search(root->right, k, v)) {
        return true;
    }

    // node not found in either subtree, backtrack
    v.pop_back();
    return false;
}

Node* kth_ancestor(Node*root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    
    Node*lft=kth_ancestor(root->left,k,node);
    Node*rght=kth_ancestor(root->right,k,node);
    
    if(lft!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            // taki ye upper root tak keval ancestor ko hi bhejta rahe
            return root;
        }
        else return lft;
    }
    
    if(rght!=NULL){
           k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else return rght;
    }
    
    return NULL;
}




int main(){
    Node*root=NULL;
    root=build(root);
    
    //  1 3 8 -1 2 5 -1 4 -1 -1 -1 -1 -1 -1

    //  vector<int>v;
    //  int k=2;
    //  if(search(root,k,v)){
    //      for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    //  }
    //  }
    //  else cout<<"akad bakad bombay bo"<<endl;

     //searching kth ancestor
     int m=2;
     int node=5;
     cout<<m<<"th ancestor of "<<node<<" is "<<search_kth_ancestor(root,m,node)->data<<endl;
    

}
