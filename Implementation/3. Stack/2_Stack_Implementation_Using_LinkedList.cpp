#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
  node(int x){
      data=x;
      next=nullptr;
  }
//   ~node(){
//       cout<<"Destructor Called"<<endl;
//   }
};

struct stack{
  node *head;
  int siz;
  stack(){
      head=nullptr;
      siz=0;
  }
  
  void push(int x){
      siz++;
      node *temp=new node(x);
      temp->next=head;
      head=temp;
  }
  
  int pop(){
    if(siz==0){ 
        //cout<<"underflow"<<endl;
        return -1;
    }
    siz--;
    int res=head->data;
    node *temp=head;
    head=head->next;
    delete temp;
    return res;
  }
  
  int top(){
      if(siz==0){
        //cout<<"underflow"<<endl;
          return -1;
      }
      return head->data;
  }
  
  int size(){
      return siz;
  }
  
  bool empty(){
      if(siz==0) return 1;
      return 0;
  }
  
  void freeUp(){
    node *temp;
    while(head!=nullptr){
        temp=head;
        head=head->next;
        delete temp;
    }
  }
};

int main()
{
    int n;
    cin>>n;
    int data;
    stack s;
    for(int i=0;i<n;i++){
        cin>>data;
        s.push(data);
    }
    cout<<"Top element of the stack : "<<s.top()<<endl;
    cout<<"Removed element from stack : "<<s.pop()<<endl;
    cout<<"Top element of the stack : "<<s.top()<<endl;
    cout<<"Size of the stack : "<<s.size()<<endl;
    cout<<"Stack is empty (1 respresents true 0 & respresents false): "<<s.empty()<<endl;
    s.freeUp();
    return 0;
}
