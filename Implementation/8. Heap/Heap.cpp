#include <iostream>
#include <limits.h>
using namespace std;

struct heap{
    int cap,size;
    int *arr;
    
    heap(int c){
        cap=c;
        size=0;
        arr=new int[cap];
    }
    
    // ~heap(){
    //     cout<<"Destructor Called"<<endl;
    // }
    
    int parent(int);
    int left(int);
    int right(int);
    void insert(int);
    void minHeapify(int);
    int extractMin();
    void decreaseKey(int,int);
    void deleteKey(int);
    void display();
    void buildHeap();
    void freeUpMemory();
};

int heap::parent(int i){
    i=(i-1)/2;
    if(i>=0)
    return i;
    else
    return INT_MAX;
}

int heap::left(int i){
    i=2*i+1;
    if(i<size)
    return i;
    else
    return INT_MAX;
}

int heap::right(int i){
    i=2*i+2;
    if(i<size)
    return i;
    else
    return INT_MAX;
}

void heap::insert(int data){
        if(size==cap){
            cout<<"Cannot be inserted since capacity is full"<<endl;
            return;
        }
        arr[size]=data;
        int ind=size,parent=size;
        while(ind!=0){
            parent=(ind-1)/2;
            if(arr[parent]>arr[ind]){
                swap(arr[parent],arr[ind]);
                ind=parent;
            }
            else{
                break;
            }
        }
        size++;
    }

void heap::minHeapify(int i){
    int l,r,s;
    while(true){
        l=left(i);
        r=right(i);
        s=i;
        if(l<size && arr[l]<arr[i])
            s=l;
        if(r<size && arr[r]<arr[s])
            s=r;
        
        if(s!=i){
            swap(arr[i],arr[s]);
            i=s;
        }
        else
            break;
    }
}

int heap::extractMin(){
    if(size==0)
        return INT_MAX;
    if(size==1){
        size--;
        return arr[0];
    }
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(0);
    return arr[size];
}

void heap::decreaseKey(int i,int x){
    if(i>=size)
        cout<<"Not possible since the selected index is out of size"<<endl;
    arr[i]=x;
    int p=0;
    while(i!=0){
    p=parent(i);
    if(arr[i]<arr[p]){
        swap(arr[i],arr[p]);
        i=p;
    }
    else
        return;
    }
}

void heap::deleteKey(int i){
    if(i>=size)
        cout<<"Not possible since the selected index is out of size"<<endl;
    decreaseKey(i,INT_MIN);
    extractMin();
}

void heap::display(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heap::buildHeap(){
    for(int i=(size-1)/2;i>=0;i--){
        minHeapify(i);
    }
}

void heap::freeUpMemory(){
    delete[] arr;
}

int main()
{
    int n;
    cin>>n;
    heap h(n);
    for(int i=0;i<n;i++){
        h.arr[i]=n-i;
        h.size++;
    }
    h.display();
    cout<<h.extractMin()<<endl;
    h.decreaseKey(n-1,1);
    h.deleteKey(2);
    h.buildHeap();
    h.display();
    cout<<h.arr[h.parent(1)]<<endl;
    cout<<h.arr[h.left(1)]<<endl;
    cout<<h.arr[h.right(1)]<<endl;
    h.freeUpMemory();
    return 0;
}
