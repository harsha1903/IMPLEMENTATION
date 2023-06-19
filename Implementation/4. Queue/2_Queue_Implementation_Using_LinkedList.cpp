#include <iostream>
#include <limits.h>
using namespace std;

struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=nullptr;
    }
};

struct queue{
    int size;
    node *front,*rear;
    
    queue(){
        size=0;
        front=nullptr;
        rear=nullptr;
    }
    
    void enqueue(int x){
        if(front==nullptr){
            front= new node(x);
            rear=front;
        }
        else{
            rear->next=new node(x);
            rear=rear->next;
        }
        size++;
    }
    
    void dequeue(){
        if(size==0){
            cout<<"We cannot delete from Queue since 'Queue is empty'"<<endl;
            return ;
        }
        node *temp=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
        size--;
    }
    
    int getFront(){
        if(size==0){
            return INT_MAX;
        }
        return front->data;
    }
    
    int getRear(){
        if(size==0){
            return INT_MAX;
        }
        return rear->data;
    }
    
    bool isEmpty(){
        if(size==0) return 1;
        return 0;
    }
    
    int getSize(){
        return size;
    }
    
    void freeUpMemory()
    {
        node *temp;
        while(front!=nullptr){
            temp=front;
            front=front->next;
            delete temp;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    queue q;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        q.enqueue(data);
    }
    cout<<"Size of Queue is : "<<q.getSize()<<endl;
    q.dequeue();
    cout<<"Size of Queue is : "<<q.getSize()<<endl;
    if(q.getFront()==INT_MAX){
        cout<<"There is no front element in Queue since 'Queue is empty'"<<endl;
    }
    else{
        cout<<"Front element in the Queue is : "<<q.getFront()<<endl;
    }
    
    if(q.getRear()==INT_MAX){
        cout<<"There is no Rear element in Queue since 'Queue is empty'"<<endl;
    }
    else{
        cout<<"Rear element in the Queue is : "<<q.getRear()<<endl;
    }
    
    cout<<"Queue is empty ('1' indicates True & '0' indicates False) : "<<q.isEmpty()<<endl;
    
    q.freeUpMemory();
    return 0;
}
