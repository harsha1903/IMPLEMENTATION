#include <iostream>
using namespace std;

void bubbleSort(int arr[ ], int n)
{
    int ind;
    for(int i=0;i<n-1;i++){
        ind=1;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                ind=0;
            }
        }
        if(ind) break;
    }  
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
