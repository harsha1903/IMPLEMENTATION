#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1=m-l+1,n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[i+l];
    }
        
    for(int i=0;i<n2;i++){
        right[i]=arr[i+m+1];
    }
    
    int i=0,j=0,index=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[index++]=left[i++];
        }
        else{
            arr[index++]=right[j++];
        }
    }
    while(i<n1){
        arr[index++]=left[i++];
    }
    while(j<n2){
        arr[index++]=right[j++];
    }
}
    
void mergeSort(int arr[], int l, int r)
{
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
 

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
} 
