#include <iostream>
using namespace std;

//class Template
template<typename T>
struct pai{
    T x,y;
    pai(T x,T y){
        this->x=x;
        this->y=y;
    }
    T getFirst();
    T getLast();
};

template<typename T> 
T pai<T>::getFirst(){
    return x;
}

template<typename T>
T pai<T>::getLast(){
    return y;
}


// Function Template
template<typename T>
T maxi(T x,T y){
    return (x>y)?x:y;
}

template<typename T1,int limit>
T1 arrMax(T1* arr,int n){
    if(n>limit)
    {
        cout<<"Limit exceeded"<<endl;
        return (T1)0;
    }
    T1 max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

int main()
{
    // Function templates
    cout<<maxi<int>(2,3)<<endl;
    cout<<maxi('c','g')<<endl;
    cout<<maxi(2.2,2.3)<<endl;
    
    int arr[4]={1,2,3,4};
    cout<<arrMax<int,4>(arr,4)<<endl;
    
    // Class Templates
    pai<int> p(10,20);
    cout<<p.getFirst()<<" "<<p.getLast()<<endl;
    return 0;
}
