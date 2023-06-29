#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //Functions on vector
    int n;
    cin>>n;
    vector<int>v(n);//v(n,x) by default with zero
    vector<int>::iterator it;/*auto it*/
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    /*vector traversal*/
    cout<<"\nvector Traversal"<<endl;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //pop_back() removes last element but doesn't return popped element
    v.pop_back();
    
    //front() & back()
    cout<<"\nfront and back elements of vector\n"<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    
    //insert
    cout<<"\nInsert\n"<<endl;
    v.insert(v.begin(),10);//v.insert(address of position,data to be insert)
    v.insert(v.begin(),2,100);//v.insert(addr of pos,num of times,data to be insert)
    vector<int>v2;
    v2.insert(v2.begin(),v.begin(),v.begin()+2);//v.begin()+2 is not included
    
    //erase
    v.erase(v.begin());//erase the element at particular position
    v.erase(v.begin(),v.bein()+2);//erases the elements from v.begin() to v.begin()+1

    //clear
    v2.clear();//it erases all elements in the vector
    
    //empty()
    v2.empty()//it returns true if vector is empty else false
    
    //resize()
    /*it resizes the vector of size 2*/
    /*if there are more elements than size then last elements will be deleted*/
    /*if there are less elements than size then remaining elements filled with default value*/
    v2.resize(2)
    v2.resize(4,10);/*if there are less elements than size then remaining elements filled with 10*/
    
    //size of vector
    cout<<"\nSize of vector\n"<<endl;
    cout<<v2.size()<<endl;
    
    //capacity of a vector
    cout<<"\nCapacity of a vector\n"<<endl;
    /*Create an empty vector*/
    vector<int> vec;
    
    /*For 1 element, it allocates only 1 space*/
    vec.push_back(10);
    cout<<vec.capacity()<<endl;
    
    /* For a new element, it doubles the space to 2 */
    /*tostore 2 elements*/
    vec.push_back(10);
    cout<<vec.capacity()<<endl;
    
    /* For a new element, it doubles space to 4*/
    /* to store the 3rd element*/
    vec.push_back(10);
    cout<<vec.capacity();

    return 0;
}
