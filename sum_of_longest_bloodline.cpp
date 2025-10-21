#include<iostream>
#include<algorithm>
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

//function to return sum of longest bloodline
void helper(Node*root,int sum,int &maxsum,int len,int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            sum=maxsum;
            
        }
        else if(len==maxLen){
            maxsum=max(sum,maxsum);
        }
        return;
    }

    sum=sum+root->data;
    helper(root->left,sum,maxsum,len,maxLen);
    helper(root->right,sum,maxsum,len,maxLen);
}


int sum_of_longest_bloodline(Node*root){
  int sum=0;
  int maxsum=0;
  int len=0;
  int maxLen=0;
  helper(root,sum,maxsum,len,maxLen);
  return maxsum;

}

int main()
{
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=build(root);
    cout<<"Sum of longest bloodline is"<<endl;
    cout<<sum_of_longest_bloodline(root);
    
}