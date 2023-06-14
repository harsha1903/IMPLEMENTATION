#include <iostream>

using namespace std;

int Lomuto_partition(int a[],int l,int h){
    int ind=l-1;
    for(int i=h-1;i>=l;i--){
        if(a[h]>a[i]){ 
            ind++;
            swap(a[ind],a[i]);
        }
    }
    swap(a[ind+1],a[h]);
    return ind+1;
}


void quicksort(int a[],int l,int h){
    if(l<h)
    {
        int p=Lomuto_partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

