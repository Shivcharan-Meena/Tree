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

//this function basically prints path having sum k
void findPath(Node* root, int k, int& sum, vector<int>& v) {
    if (!root)
        return;

    // Include current node
    sum += root->data;
    v.push_back(root->data);

    // If sum found
    if (sum == k) {
        cout << "Path found: ";
        for (int x : v) cout << x << " ";
        cout << endl;
        // you can return here if only one path is needed
    }

    // Recur for left and right children
    findPath(root->left, k, sum, v);
    findPath(root->right, k, sum, v);

    // Backtrack
    sum -= root->data;
    v.pop_back();
}


//this function calculates the number of tree has the sum k
void sum_k_paths(Node*root,int k,int &count,vector<int>v){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);//stores the data of each node of traversed path

    sum_k_paths(root->left,k,count,v);
    sum_k_paths(root->right,k,count,v);

    //find the sum of the path and see the sum k is present or not
      int sum=0;
    for (int i = v.size() - 1; i >= 0; i--) {
    sum += v[i];
    if (sum == k) count++;
}
    v.pop_back();//jab node se backtrack karo to us node ko pop kardo;
    //The v.pop_back(); at the end isn't necessary since ans is passed by value, not reference. It won't affect the original vector outside the function.
}

//this function uses time complexiety as O(N) for finding k sum path
  #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(Node* root, int targetSum,ll currSum){
        if(root==NULL) return;
        currSum+=root->data;
        ans+=mp[currSum-targetSum];//it mean between the ongoing process there is a place where targetSum is generated.
        // currSum - prevSum = targetSum
        // → prevSum = currSum - targetSum // agar map me prevsum mila to matlab us node se lekar abhi vali nade ke bich me koi targetsum path exist karta h

        mp[currSum]++;
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        mp[currSum]--;
        currSum-=root->data;

    }
    int pathSum(Node* root, int targetSum) {
        mp[0]++;
        ll currSum=0;
        solve(root,targetSum,currSum);
        return ans;
    }



int main()
{
    Node*root=NULL;
     // 1 2 4 -1 -1 3 -1 -1 5 6 -1 -1 -1
    root=build(root);

    vector<int>v;
    int sum=0;
    // findPath(root,6,sum,v);
    int count=0;
    vector<int>path;
    int k=6;
    // sum_k_paths(root,k,count,path);
    
    //Examples
    //10 5 3 3 2 -1 11 3 2 -1 1 -1 -1 -1 -1 -1 -1 -1 -1  k=8;
    //1 3 -1 2 4 -1 -1 -1 8 5 -1 -1 -1 k=6;



    cout<<"Total "<<pathSum(root,k)<<" paths contains sum "<<k<<endl;
}