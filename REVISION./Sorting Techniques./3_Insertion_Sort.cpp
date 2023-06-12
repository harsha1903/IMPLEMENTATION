#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j+1]>arr[j]){
                break;
            }
            else{
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
} 
