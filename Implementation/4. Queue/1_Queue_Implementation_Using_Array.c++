#include <iostream>
#include <limits.h>
using namespace std;

struct queue{
    int cap,size;
    int front,rear;//rear=(front+size-1)%cap;
    int *arr;
    
    queue(int cap){
        this->cap=cap;
        arr=new int[cap];
        size=front=rear=0;
    }
    
    void enqueue(int x){
        if(size==cap){
            cout<<"We cannot insert more elements into Queue since 'Queue is full'"<<endl;
            return;
        }
        arr[rear]=x;
        size++;
        rear=(rear+1)%cap;
    }
    
    void dequeue(){
        if(size==0){
            cout<<"We cannot delete from Queue since 'Queue is empty'"<<endl;
            return ;
        }
        front=(front+1)%cap;
        size--;
    }
    
    int getFront(){
        if(size==0){
            return INT_MAX;
        }
        return arr[front];
    }
    
    int getRear(){
        if(size==0){
            return INT_MAX;
        }
        return arr[(rear+cap-1)%cap];
    }
    
    bool isFull(){
        if(size==cap) return 1;
        return 0;
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
        delete[] arr;
    }
};

int main()
{
    int cap;
    cin>>cap;
    queue q(cap);
    int data;
    for(int i=0;i<cap;i++){
        cin>>data;
        q.enqueue(data);
    }
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
    
    cout<<"Queue is full ('1' indicates True & '0' indicates False) : "<<q.isFull()<<endl;
    cout<<"Queue is empty ('1' indicates True & '0' indicates False) : "<<q.isEmpty()<<endl;
    
    q.freeUpMemory();
    return 0;
}
