#include <iostream>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;
    node(int x){
        data=x;
        prev=nullptr;
        next=nullptr;
    }
};

void freeUpMemory(node *head){
    if(head==nullptr){
        return;
    }
    node *curr=head;
    while(head){
        head=head->next;
        delete curr;
        curr=head;
    }
}

void ITEprintlist(node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node * insertAtBegin(node *head,int data){
    node *temp=new node(data);
    temp->next=head;
    if(head!=nullptr){
        head->prev=temp;
    }
    return temp;
}

node * insertAtEnd(node *head,int data){
    node *temp=new node(data);
    if(head==nullptr){
        return temp;
    }
    node *curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}

node * deleteHead(node *head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node *temp=head->next;
    temp->prev=nullptr;
    delete head;
    return temp;
}

node * deleteLast(node *head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    node *curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->prev->next=nullptr;
    delete curr;
    return head;
}

node * rev(node *head){
    if(head==nullptr){
        return head;
    }
    node *curr=head;
    while(curr!=nullptr){
        curr=head->next;
        head->next=head->prev;
        head->prev=curr;
        if(curr!=nullptr)
        head=curr;
    }
    return head;
}

int main()
{
    int n;
    cin>>n;
    node *head=nullptr;
    node *curr;
    int data;
    while(n--){
        if(head==nullptr){
            cin>>data;
            head=new node(data);
            curr=head;
        }
        else{
            cin>>data;
            curr->next=new node(data);
            curr->next->prev=curr;
            curr=curr->next;
        }
    }
    
    //PRINTING DOUBLY LINKED LIST
    ITEprintlist(head);
    
    // INSERT at BEGIN of DOUBLY LINKED LIST
    cin>>data;
    head=insertAtBegin(head,data);
    
    // INSERT at END DOUBLY LINKED LIST
    cin>>data;
    head=insertAtEnd(head,data);
    
    // DELETE HEAD of a DOUBLY LINKED LIST
    head=deleteHead(head);
    
    // DELETE LAST Node of a DOUBLY LINKED LIST
    head=deleteLast(head);
    
    // REVERSE a DOUBLY LINKED LIST
    head=rev(head);
    
    //TO free up the dynamically allocated memory
    freeUpMemory(head);
    
    return 0;
}
