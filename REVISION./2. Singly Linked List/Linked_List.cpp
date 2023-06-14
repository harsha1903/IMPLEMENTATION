#include <iostream>
using namespace std;

struct node{
  int data;
  node * next;
  node(){
      next=nullptr;
  }
};

void freeupMemory(node *head){
    if(head==nullptr){
        return;
    }
    node *curr;
    while(head){
        curr=head;
        head=head->next;
        delete curr;
    }
}

void ITEprintlist(node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void RECprintlist(node *head){
    if(head==nullptr){ 
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    RECprintlist(head->next);
}

int ITEsearchlist(node *head,int key){
    int count=0;
    while(head){
        count++;
        if(head->data==key) return count;
        head=head->next;
    }
    return -1;
}

int RECsearchlist(node *head,int key){
    if(head->data==key) return 1;
    if(head->next==nullptr) return -1;
    int count=1+RECsearchlist(head->next,key);
    if(count==0) return -1;
    return count;
}

node * insertAtBegin(node *head,int data){
    node *temp=new node;
    temp->data=data;
    temp->next=head;
    return temp;
}

node * insertAtEnd(node *head,int data){
    
    node *temp=new node;
    temp->data =data;
    /*The below line is not need since we are already intializing next as nullptr using constructor*/
    // temp->next->=nullptr;
    if(head==nullptr)
    {
        return temp;   
    }
    
    node *curr= head;
    while(curr->next) {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

node * insertAtGivenPosition(node *head,int data,int pos){
    node *temp=new node;
    temp->data=data;
    
    if(pos==1){
        temp->next=head;
        return temp;
    }
    
    node *curr=head;
    while(curr && pos>2){
        curr=curr->next;
        pos--;
    }
    if(curr==nullptr){
        delete temp;
        return head;
    }
    if(curr!=nullptr){
        temp->next=curr->next;
        curr->next=temp;
    }
    return head;
}

node * deleteAtBegin(node *head){
    if(head==nullptr) return nullptr;
    node *temp = head->next;
    delete head;
    return temp;
}

node * deleteAtEnd(node *head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node *temp=head;
    while(head->next->next){
        head=head->next;
    }
    node *curr=head;
    head=head->next;
    delete head;
    curr->next=nullptr;
    return temp;
}

node * deleteAtGivenPosition(node *head,int pos){
    if(head==nullptr) return head;
    
    if(pos==1){
        node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    node *curr=head;
    while(curr &&pos>2){
        curr=curr->next;
        pos--;
    }
    if(curr==nullptr || curr->next==nullptr) return head;
    if(curr->next!=nullptr){
        node *temp=curr->next;
        curr->next=temp->next;
        delete temp;
    }
    return head;
}

node * sortedInsert(node *head,int data){
    node *temp= new node;
    temp->data=data;
    
    if(head==nullptr){
        return temp;
    }
    if(temp->data<head->data){
        temp->next=head;
        return temp;
    }
    
    node *curr=head;
    while(curr->next!=nullptr && curr->next->data<temp->data){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void naiveMiddleOfLinkedList(node *head){
    if(head==nullptr){
        return;
    }
    node *curr=head;
    int count=0;
    while(curr){
        count++;
        curr=curr->next;
    }
    if(count&1) count=(count+1)/2;
    else count=count/2;
    curr=head;
    while(count--){
        if(count==0){
            cout<<curr->data<<endl;
            break;
        }
        curr=curr->next;
    }
}

void efficientMiddleOfLinkedList(node *head){
    if(head==nullptr){
        return;
    }
    node *fast=head,*slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}

void naiveNthNodeFromEnd(node *head,int pos){
    node *curr=head;
    int count=0;
    while(curr){
        count++;
        curr=curr->next;
    }
    count=count-pos+1;
    if(count<1){
        return;
    }
    curr=head;
    while(curr){
        if(count==1){
            cout<<curr->data<<endl;
            return;
        }
        count--;
        curr=curr->next;
    }
}

void efficientNthNodeFromEnd(node *head,int pos){
    if(head==nullptr || (head->next==nullptr && pos!=1)){
        return;
    }
    node *first=head,*last=head;
    while(first->next){
        if(pos==1) break;
        pos--;
        first=first->next;
    }
    if(pos!=1){ 
        return;
    }
    while(first->next && last->next){
        first=first->next;
        last=last->next;
    }
    cout<<last->data<<endl;
}

node * naiveITErev(node *head){
    node *rev=nullptr;
    node *temp;
    node *curr=head;
    while(curr){
        if(rev==nullptr){
            rev=new node;
            rev->data=curr->data;
        }
        else{
            temp=new node;
            temp->data=curr->data;
            temp->next=rev;
            rev=temp;
        }
        curr=curr->next;
    }
    freeupMemory(head);
    return rev;
}

node * efficientITErev(node *head){
    node *prev=nullptr,*next=nullptr;
    node *curr=head;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node * RECrev1(node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *temp=RECrev1(head->next);
    node *next_head=head->next;
    head->next=nullptr;
    next_head->next=head;
    return temp;
}

node * RECrev2(node *curr,node * prev){
    if(curr==nullptr){
        return prev;
    }
    node * next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    return RECrev2(curr,prev);
}

void remDUP(node *head){
    node *curr=head;
    while(curr!=nullptr && curr->next!=nullptr){
        if(curr->data==curr->next->data){
            node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}

int main()
{
    node *head=new node,*first=new node,*second=new node;
    head->next=first;
    first->next=second;
    node *var=head;
    while(var){
        cin>>var->data;
        var=var->next;
    }
    //PRINTING LINKED LIST
    ITEprintlist(head);
    RECprintlist(head);
    
    //SEARCHING A KEY IN LINKED LIST
    int key;
    cin>>key;
    cout<<ITEsearchlist(head,key)<<endl;
    cout<<RECsearchlist(head,key)<<endl;
    
    //INSERT at Begin of singly LINKED LIST
    int data;
    cin>>data;
    head=insertAtBegin(head,data);

    // INSERT at End of singly LINKED LIST
    int data;
    cin>>data;
    head = insertAtEnd(head,data);
    
    //INSERT at given POSITION in singly LINKED LIST
    int data,position;
    cin>>data>>position;
    head=insertAtGivenPosition(head,data,position);
    
    // DELETE at Begin of singly LINKED LIST
    head=deleteAtBegin(head);
        
    //DELETE at End of singly LINKED LIST
    head=deleteAtEnd(head);
    
    //DELETE at given POSITION in singly LINKED LIST
    int position;
    cin>>position;
    head=deleteAtGivenPosition(head,position);
   
    //SORTED INSERT in a Singly LINKED LIST
    int data;
    cin>>data;
    head=sortedInsert(head,data);
    
    // MIDDLE of LINKED LIST
    naiveMiddleOfLinkedList(head);
    efficientMiddleOfLinkedList(head);
    
    // Nth Node FROM END of LINKED LIST
    int pos;
    cin>>pos;
    naiveNthNodeFromEnd(head,pos);
    efficientNthNodeFromEnd(head,pos);
    
    // REVERSE a LINKED LIST
    head=naiveITErev(head);
    head=efficientITErev(head);
    head=RECrev1(head);
    head=RECrev2(head,nullptr);
    
    // REMOVE DUPLICATES from a SORTED Singly LINKED LIST
    remDUP(head);
    ITEprintlist(head);
    
    //TO free up the dynamically allocated memory
    freeupMemory(head);
    return 0;
}
