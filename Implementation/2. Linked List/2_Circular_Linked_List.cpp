#include <iostream>
using namespace std;

struct node{
    int data;
    node *next=nullptr;
    node(int data){
        this->data=data;
        next=nullptr;
    }
};

void freeUpMemory(node *head){
    if(head==nullptr){
        return;
    }
    node *curr=head;
    node *temp=nullptr;
    while(temp!=head){
        temp=curr->next;
        delete curr;
        curr=temp;
    }
}

void ITEprintList(node *head){
    if(head==nullptr){
        return;
    }
    node *curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}

node * naiveInsertAtBegin(node *head,int data){
    node *temp=new node(data);
    if(head==nullptr){
        temp->next=temp;
        return temp;
    }
    node *curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    return temp;
}

node * efficientInsertAtBegin(node *head,int data){
    node *temp=new node(data);
    if(head==nullptr){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    int d=temp->data;
    temp->data=head->data;
    head->data=d;
    return head;
}

node * naiveInsertAtEnd(node *head,int data){
    node *temp=new node(data);
    if(head==nullptr){
        temp->next=temp;
        return temp;
    }
    node *curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    return head;
}

node * efficientInserAtEnd(node *head,int data){
    node *temp=new node(data);
    if(head==nullptr){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    int t=temp->data;
    temp->data=head->data;
    head->data=t;
    return temp;
}

node * naiveDeleteHead(node *head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==head){
        delete head;
        return nullptr;
    }
    node *curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next;
}

node * efficientDeleteHead(node *head){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==head){
        delete head;
        return nullptr;
    }
    node *temp=head->next;
    head->data=temp->data;
    head->next=temp->next;
    delete temp;
    return head;
}

node * deleteKthNode(node *head,int k){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==head){
        delete head;
        return nullptr;
    }
    if(k==1){
        node *temp=head->next;
        head->data=temp->data;
        head->next=temp->next;
        delete temp;
        return head;
    }
    node *curr=head;
    while(k>1){
        if(k==2){
            node *temp=curr->next;
            curr->next=temp->next;
            delete temp;
            break;
        }
        curr=curr->next;
        k--;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    int temp=n;
    node *head=nullptr;
    node *curr;
    int data;
    while(temp--){
        if(head==nullptr){
            cin>>data;
            head=new node(data);
            curr=head;
        }
        else{
            cin>>data;
            curr->next=new node(data);
            curr=curr->next;
        }
    }
    if(n!=0)
    curr->next=head;
    
    //PRINTING CIRCULAR LINKED LIST
    ITEprintList(head);
    
    // INSERT at BEGIN of CIRCULAR LINKED LIST
    cin>>data;
    head=naiveInsertAtBegin(head,data); O(N) time
    head=efficientInsertAtBegin(head,data);
    
    // INSERT at the END of CIRCULAR LINKED LIST
    cin>>data;
    head=naiveInsertAtEnd(head,data);
    head=efficientInserAtEnd(head,data);
    
    // DELETE HEAD of CIRCULAR LINKED LIST
    head=naiveDeleteHead(head);
    head=efficientDeleteHead(head);
    
    // DELETE Kth of a CIRCULAR LINKED LIST
    int k;
    cin>>k;
    head=deleteKthNode(head,k);
    ITEprintList(head);
    
    //TO free up the dynamically allocated memory
    freeUpMemory(head);
  
    return 0;
}
