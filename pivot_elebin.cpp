#include <iostream>
#include <vector>
using namespace std;

int piv(vector <int> arr)
{
    int s=0;
    int e= arr.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(s==e)
        return arr[s];
        if(arr[mid]>arr[mid+1])
        return arr[mid];
        if(mid-1>0 && arr[mid-1]>arr[mid])
        return arr[mid-1];
        if(arr[s]>arr[mid])
        e=mid-1;
        else
        s=mid+1;
    }
    return -1;
}

int main()
{
    vector <int> arr{7, 8};
    int pivot= piv(arr);
    cout<<"The pivot element is : "<<pivot;
    return 0;
}