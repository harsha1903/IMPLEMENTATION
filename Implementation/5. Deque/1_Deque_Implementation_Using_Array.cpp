#include <iostream>
#include <limits.h>
using namespace std;

struct deque{
    int front,rear,cap,size;
    int *arr;
    
    deque(int cap){
        this->cap=cap;
        front=rear=size=0;
        arr=new int[cap];
    }
    void insertFront(int x){
        if(size==cap){
            cout<<"Deque Overflow"<<endl;
            return;
        }
        size++;
        if(size==1){
            arr[front]=x;
        }
        else{
            front=(front-1+cap)%cap;
            arr[front]=x;
        }
    }
    void insertRear(int x){
        if(size==cap){
            cout<<"Deque Overflow"<<endl;
            return;
        }
        rear=(front+size)%cap;
        arr[rear]=x;
        size++;
    }
    void deleteFront(){
        if(size==0){
            cout<<"Deque Underflow"<<endl;
            return;
        }
        front=(front+1)%cap;
        size--;
    }
    void deleteRear(){
        if(size==0){
            cout<<"Deque Underflow"<<endl;
            return;
        }
        rear=(rear-1+cap)%cap;
        size--;
    }
    int getFront(){
        if(size==0) return INT_MAX;;
        return arr[front];
    }
    int getRear(){
        if(size==0) return INT_MAX;
        return arr[rear];
    }
    int siz(){
        return size;
    }
    bool isFull(){
        if(size==cap) return 1;
        return 0;
    }
    bool isEmpty(){
        if(size==0) return 1;
        return 0;
    }
};

int main()
{
    int cap;
    cin>>cap;
    deque dq(cap);
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertRear(40);
    dq.deleteRear();
    dq.deleteFront();
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    cout<<dq.siz()<<endl;
    cout<<dq.isFull()<<endl;
    cout<<dq.isEmpty()<<endl;
    return 0;
}
