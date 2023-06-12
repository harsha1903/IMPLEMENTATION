#include <iostream>

using namespace std;

int Hoare_partition(int a[],int l,int h){
    int i=l-1,j=h+1;
    int pivot=a[l];
    while(true)
    {
        do{
            i++;
        }while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i>=j) break;
        swap(a[i],a[j]);
    }
    return j;
}

void quicksort(int a[],int l,int h){
    if(l<h)
    {
        int p=Hoare_partition(a,l,h);
        quicksort(a,l,p);
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
