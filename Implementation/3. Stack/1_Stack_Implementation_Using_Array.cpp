#include <iostream>
#include <limits.h>
using namespace std;

struct stack{
  int *arr;// we can also implement using vector
  int top;
  int cap;
  
  stack(int cap){
      this->cap=cap;
      top=-1;
      arr=new int[cap];
  }
  
  void push(int x){
      top++;
      if(top>=cap){
          cout<<"Over Flow"<<endl;
          return;
      }
      arr[top]=x;
  }
  
  int pop(){
    if(top==-1){
      //cout<<"underflow"<<endl;
      return INT_MAX;
    }
    int res=arr[top];
    top--;
    return res;
  }
  
  int peek(){
      if(top==-1){
        //cout<<"underflow"<<endl;  
        return INT_MAX;
      }
      return arr[top];
  }
  
  int size(){
      return top+1;
  }
  
  bool empty(){
      if(top==-1) return 1;
      return 0;
  }
  
  void freeUp(){
      delete[] arr;
  }
};

int main()
{
    int cap,data;
    cin>>cap;
    stack s(cap);
    for(int i=0;i<cap;i++){
        cin>>data;
        s.push(data);
    }
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    s.freeUp();
    return 0;
}
