#include <iostream>
using namespace std;

struct node{
  int key;
  node *left, *right;
  node(int k){
      key=k;
      left=right=nullptr;
  }
  
//   ~node(){
//       cout<<"Destructor Called"<<endl;
//   }
};

void freeUpMemory(node *root){
    if(root==nullptr)
    return;
    freeUpMemory(root->left);
    freeUpMemory(root->right);
    delete root;
}

bool RECsearchInBST(node *root,int k){
    if(root==nullptr)
    return false;
    if(root->key==k)
    return true;
    if(root->key>k)
    return RECsearchInBST(root->left,k);
    // if(root->key<k)
    return RECsearchInBST(root->right,k);
}

bool ITEsearchInBST(node *root,int k){
    while(root!=nullptr){
        if(root->key==k)
        return true;
        if(root->key>k)
        root=root->left;
        else if (root->key<k)
        root=root->right;
    }
    return false;
}

node * RECinsertInBST(node *root,int k){
    if(root==nullptr)
    return new node(k);
    
    if(root->key>k)
    root->left=RECinsertInBST(root->left,k);
    
    if(root->key<k)
    root->right=RECinsertInBST(root->right,k);
    
    return root;
}

node * ITEinsertInBST(node *root,int k){
    if(root==nullptr)
    return new node(k);

    node *curr=root;
    while(true){
        if(root->key==k)
        break;
        if(root->key>k)
        {
            if(root->left==nullptr){
                root->left=new node(k);
                break;
            }
            root=root->left;
        }
        else if(root->key<k){
            if(root->right==nullptr){
                root->right=new node(k);
                break;
            }
            root=root->right;
        }
    }
    return root;
}

node * getSuccessor(node *root){
    root=root->right;
    while(true){
        if(root->left==nullptr)
        break;
        root=root->left;
    }
    return root;
}

node * deleteBST(node *root,int k){
    if(root==nullptr)
    return root;
    
    if(root->key>k)
    root->left=deleteBST(root->left,k);
    
    if(root->key<k)
    root->right=deleteBST(root->right,k);
    
    if(root->key==k)
    {
        if(root->left==nullptr)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==nullptr)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        
        node *successor=getSuccessor(root);
        root->key=successor->key;
        root->right=deleteBST(root->right,successor->key);
    }
    return root;
}

node * RECfloorOfBST(node *root,int k){
    if(root==nullptr)
    return nullptr;
    
    if(root->key==k)
    return root;
    
    if(root->key>k)
    return RECfloorOfBST(root->left,k);
    
    // if(root->key<k)
    node *temp=RECfloorOfBST(root->right,k);
    if(temp!=nullptr && temp->key<=k)
    return temp;
    else
    {
        return root;
    }
    
}

node * ITEfloorofBST(node *root,int k){
    node *res=nullptr;
    while(root!=nullptr){
        if(root->key==k)
        return root;
        
        if(root->key>k)
        root=root->left;
        else if(root->key<k){
            res=root;
            root=root->right;
        }
    }
    return res;
}

node * RECceilOfBST(node *root,int k){
    if(root==nullptr)
    return nullptr;
    
    if(root->key==k)
    return root;
    
    if(root->key<k)
    return RECceilOfBST(root->right,k);
    
    // if(root->key>k)
    node *cei=RECceilOfBST(root->left,k);
    if(cei!=nullptr && cei->key>=k && cei->key<root->key)
    {
        return cei;
    }
    return root;
}

node * ITEceilOfBST(node *root,int k){
    node *res=nullptr;
    while(root!=nullptr){
        if(root->key==k)
        return root;
        
        if(root->key<k)
        root=root->right;
        else
        {
            if(res==nullptr) res=root;
            else if(res->key > root->key) 
            res=root;
            
            root=root->left;
        }
    }
    return res;
}

int main()
{
    node *root=new node(10);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(4);
    root->right->right=new node(16);
    
    // Insert in BST C++
    int n;
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        root=RECinsertInBST(root,k);
        // root=ITEinsertInBST(root,k);
    }
    
    // BST deletion
    cin>>k;
    root=deleteBST(root,k);
    
    // Search in BST
    cin>>k;
    cout<<"Whether the key "<<k<<" is present in BST or not : "<<RECsearchInBST(root,k)<<endl;
    cout<<"Whether the key "<<k<<" is present in BST or not : "<<ITEsearchInBST(root,k)<<endl;
    
    // Floor in BST
    cin>>k;
    node *floo=RECfloorOfBST(root,k);
    node *floo=ITEfloorofBST(root,k);
    if(floo==nullptr) cout<<"Floor of key "<<k<<" in BST is not found"<<endl;
    else cout<<"Floor of key "<<k<<" in BST is : "<<floo->key<<endl;
    
    // Ceil in BST
    cin>>k;
    node *cei=RECceilOfBST(root,k);
    node *cei=ITEceilOfBST(root,k);
    if(cei==nullptr) cout<<"Ceil of key "<<k<<" in BST is not found"<<endl;
    else cout<<"Ceil of key "<<k<<" in BST is : "<<cei->key<<endl;
    
    // To free up the dynamically allocated memory
    freeUpMemory(root);

    return 0;
}
