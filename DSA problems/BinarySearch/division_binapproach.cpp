#include <iostream>
using namespace std;

int quotient(int D, int d)
{
    int s = 0;
    int e = D;
    int ans = -1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(d*mid==D)
        return mid;
        if(d*mid<D)
        {
            ans=mid;
            s=mid+1;
        }
        else
        e=mid-1;
    }
    return ans;
}

int main()
{
    cout<<"Enter the dividend and divisor : ";
    int D, d;
    cin>>D>>d;
    
    int ans= quotient(abs(D), abs(d));
    if((d<0 && D>0) || (d>0 && D<0))
    ans*=-1;
    cout << "The quotient is : " << ans;
    return 0;
}