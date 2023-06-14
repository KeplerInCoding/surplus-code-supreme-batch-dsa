#include <iostream>
#include <vector>
using namespace std;

int dup(vector <int> arr, int n)
{
    if(n==1)
    return arr[n-1];
    int s=0; 
    int e=n-1;
    int ans =-1;
    while(s<=e)
    {
        int mid= (s+e)/2;
        if((mid & 1) == 0)
        {
            if(arr[mid]==arr[mid+1])
            s=mid+2;
            else
            {
                ans=mid;
                e=mid-1;
            }
        }
        else 
        {
            if(mid-1>=s && arr[mid]==arr[mid-1])
            s=mid+1;

            else
            {
                ans=mid;
                e=mid-2;
            }
        }
        
    }
    return arr[ans];
}
 
int main()
{
    int n;
    cout<<"Enter no. of elements : ";
    cin>>n;
    cout<<"Enter the array elements in pairs : ";  // {1 1 3 3 4 4 7 7 4 4 3 5 5}
    vector <int> arr;
    for(int i=0; i<n; i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int ans = dup(arr, n);
    cout<<"The odd occuring element is : "<<ans;
    return 0;
}