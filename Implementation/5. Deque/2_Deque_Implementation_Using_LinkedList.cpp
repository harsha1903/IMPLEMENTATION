#include <iostream>
#include <limits.h>
using namespace std;

struct node{
    int data;
    node *prev,*next;
    node(int x){
        data=x;
        prev=next=nullptr;
    }
};

struct deque{
    int size;
    node *front,*rear;
    
    deque(){
        size=0;
        front=rear=nullptr;
    }
    void insertFront(int x){
        node *temp=new node(x);
        if(front==nullptr){
            front=rear=temp;
        }
        else{
            temp->next=front;
            front->prev=temp;
            front=temp;
        }
        size++;
    }
    void insertRear(int x){
        node *temp=new node(x);;
        if(rear==nullptr){//size=0;
            front=rear=temp;
        }
        else{
            rear->next=temp;
            temp->prev=rear;
            rear=temp;
        }
        size++;
    }
    void deleteFront(){
        if(front==nullptr){//size=0;
            cout<<"Deque Underflow"<<endl;
            return;
        }
        else{
            if(front->next==nullptr){
                node *temp=front;
                front=rear=nullptr;
                delete temp;
            }
            else{
                node *temp=front;
                front=front->next;
                front->prev=nullptr;
                delete temp;
            }
        }
        size--;
    }
    void deleteRear(){
        if(rear==nullptr){
            cout<<"Deque Underflow"<<endl;
            return;
        }
        else{
            if(rear->prev==nullptr){
                node *temp=rear;
                front=rear=nullptr;
                delete temp;
            }
            else{
                node *temp=rear;
                rear=rear->prev;
                rear->next=nullptr;
                delete temp;
            }
        }
        size--;
    }
    int getFront(){
        if(size==0) return INT_MAX;;
        return front->data;;
    }
    int getRear(){
        if(size==0) return INT_MAX;
        return rear->data;
    }
    int siz(){
        return size;
    }
    bool isEmpty(){
        if(size==0) return 1;
        return 0;
    }
};

int main()
{
    deque dq;
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertRear(40);
    dq.deleteRear();
    dq.deleteFront();
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    cout<<dq.siz()<<endl;
    cout<<dq.isEmpty()<<endl;
    return 0;
}
