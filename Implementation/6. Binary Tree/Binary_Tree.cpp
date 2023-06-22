#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

struct node{
    int key;
    node *left,*right;
    node(int k){
        key=k;
        left=right=nullptr;
    }
    
    // ~node(){
    //     cout<<"Destructor Called"<<endl;
    // }
};

void inorder_Traversal(node *root){
    if(root==nullptr)
    return;
    
    inorder_Traversal(root->left);
    cout<<root->key<<" ";
    inorder_Traversal(root->right);
}

void ITEinorder_Traversal(node *root){
    if(root==nullptr)
    return;
    stack<node*>s;
    node *curr=root;
    while(curr!=nullptr || s.empty()==false){
        while(curr!=nullptr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
    
}

void preorder_Traversal(node *root){
    if(root==nullptr)
    return;
    
    cout<<root->key<<" ";
    preorder_Traversal(root->left);
    preorder_Traversal(root->right);
}

void ITEpreorder_Traversal(node *root){
    if(root==nullptr)
    return;
    stack<node*>s;
    node *curr=root;
    while(curr!=nullptr || s.empty()==false){
        while(curr!=nullptr){
            s.push(curr);
            cout<<curr->key<<" ";
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        curr=curr->right;
    }
    
}

void efficientITEpreorder_Traversal(node *root){
    if(root==nullptr)
    return;
    stack<node *>s;
    s.push(root);
    node *curr=nullptr;
    while(curr!=nullptr || s.empty()==false){
        if(curr==nullptr){
            curr=s.top();
            s.pop();
        }
        cout<<curr->key<<" ";
        if(curr->right!=nullptr)
        s.push(curr->right);
        curr=curr->left;
    }
}

void postorder_Traversal(node *root){
    if(root==nullptr)
    return;
    
    postorder_Traversal(root->left);
    postorder_Traversal(root->right);
    cout<<root->key<<" ";
}

void ITEpostorder_Traversal(node *root){
    if(root==nullptr)
    return;
    stack<node *>s1;
    stack<node *>s2;
    s1.push(root);
    node *curr=nullptr;
    while(s1.empty()==false){
        curr=s1.top();
        s1.pop();
        if(curr->left!=nullptr)
        s1.push(curr->left);
        if(curr->right!=nullptr)
        s1.push(curr->right);
        s2.push(curr);
    }
    while(s2.empty()==false){
        curr=s2.top();
        s2.pop();
        cout<<curr->key<<" ";
    }
}

int heightOfBTree(node *root){
    if(root==nullptr)
    return 0;
    
    return 1+max(heightOfBTree(root->left),heightOfBTree(root->right));
}

void printNodesAtKdistance(node *root,int k){
    if(root==nullptr)
    return;
    if(k==0)
    cout<<root->key<<" ";
    
    printNodesAtKdistance(root->left,k-1);
    printNodesAtKdistance(root->right,k-1);
    
}

void naiveLevelOrderTraversal(node *root){
    if(root==nullptr)
    return;
    int ht=heightOfBTree(root);
    for(int i=0;i<ht;i++){
        printNodesAtKdistance(root,i);
    }
}

void efficientLevelOrderTraversal(node *root){
    if(root==nullptr)
    return;
    queue<node*>q;
    q.push(root);
    while(q.empty()==false){
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
    }
}

int sizeOfBTree(node *root){
    if(root==nullptr)
    return 0;
    
    return 1+sizeOfBTree(root->left)+sizeOfBTree(root->right);
}

int maxInBTree(node *root){
    if(root==nullptr)
    return INT_MIN;
    return max(root->key,max(maxInBTree(root->left),maxInBTree(root->right)));
}

void freeUpMemory(node *root){
    if(root==nullptr)
    return;
    
    freeUpMemory(root->left);
    freeUpMemory(root->right);
    delete root;
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->right->right=new node(50);
    
    // Traversal
    cout<<"Inorder Traversal : ";
    inorder_Traversal(root);
    cout<<endl;
    cout<<"Iterative Inorder Traversal : ";
    ITEinorder_Traversal(root);
    cout<<endl;
    
    cout<<"Preorder Traversal : ";
    preorder_Traversal(root);
    cout<<endl;
    cout<<"Iterative Preorder Traversal : ";
    ITEpreorder_Traversal(root);
    cout<<endl;
    cout<<"Efficient Iterative Preorder Traversal : ";
    efficientITEpreorder_Traversal(root);
    cout<<endl;
    
    cout<<"Postorder Traversal : ";
    postorder_Traversal(root);
    cout<<endl;
    cout<<"Iterative Postorder Traversal : ";
    ITEpostorder_Traversal(root);
    cout<<endl;
    
    // Height of Binary Tree
    cout<<"Height of Binary Tree : "<<heightOfBTree(root)<<endl;
    
    // Print Nodes at K distance
    int k;
    cin>>k;
    cout<<"Print Nodes at distance "<<k<<" is/are : ";
    printNodesAtKdistance(root,k);
    cout<<endl;
    
    // Level Order Traversal
    cout<<"Level Order Traversal : ";
    // naiveLevelOrderTraversal(root);
    efficientLevelOrderTraversal(root);
    cout<<endl;
    
    // Size of Binary Tree
    cout<<"Size of Binary Tree : "<<sizeOfBTree(root)<<endl;
    
    // Maximum in Binary Tree
    cout<<"Maximum in Binary Tree : "<<maxInBTree(root)<<endl;
    
    //To free up the dynamically allocated memory
    freeUpMemory(root);
    
    return 0;
}
