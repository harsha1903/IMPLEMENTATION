#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
           if(arr[min]>arr[j])
           {
               min=j;
           }
        }
       if(i!=min){ 
           swap(arr[min],arr[i]);
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
    selectionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
} 

