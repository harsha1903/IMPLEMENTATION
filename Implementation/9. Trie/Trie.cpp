#include <bits/stdc++.h>
using namespace std;

struct trieNode{
    unordered_map<char,trieNode*>m;
    bool is_end;
    
    trieNode(){
        is_end=false;
    }
    
};

void insertTrie(trieNode* root,string &key){
    trieNode* curr=root;
    for(int i=0;i<key.size();i++){
        if(curr->m[key[i]]==nullptr){
            curr->m[key[i]]=new trieNode;
        }
        curr=curr->m[key[i]];
    }
    curr->is_end=true;
}
    
bool searchTrie(trieNode* root,string &key){
    trieNode* curr=root;
    for(int i=0;i<key.size();i++){
        if(curr->m[key[i]])
        {
            curr=curr->m[key[i]];
        }
        else{
            return false;
        }
    }
    return curr->is_end;
}

trieNode* deleteTrie(trieNode* root,string &key,int i){
    if(root==nullptr)
        return nullptr;
    if(i==key.length()){
        if(root->is_end)
            root->is_end=false;
        if(root->m.empty()){
            delete root;
            root=nullptr;
        }
        return root;
    }
    root->m[key[i]]=deleteTrie(root->m[key[i]],key,i+1);
    if(root->m.empty() && root->is_end==false)
    {
        delete root;
        root=nullptr;
    }
    return root;
}

int main()
{
    trieNode *root=new trieNode;
    
    int n;
    cout<<"Enter the number of words you want to inset into Trie datastructure"<<endl;
    cin>>n;
    
    while(n--){
        string s;
        cout<<"Enter the string you want to insert into trie datastructure:"<<endl;
        cin>>s;
        
        //Insert
        insertTrie(root,s);
    }
    
    string t;
    cout<<"Enter the string you want to search in the trie datastructure"<<endl;
    cin>>t;
    
    //Search
    cout<<searchTrie(root,t)<<endl;
    
    //Delete
    cout<<"Enter the string you want to delete in the trie datastructure"<<endl;
    cin>>t;
    root = deleteTrie(root,t,0);
    cout<<searchTrie(root,t);
    return 0;
}

