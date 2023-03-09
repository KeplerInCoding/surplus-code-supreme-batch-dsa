#include <iostream>
using namespace std;

int Ans(int num)
{
    int ans=-1;
    int start=0;
    int end=num;
    
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(mid*mid==num)
        return mid;
        if(mid*mid>num)
        end=mid-1;
        else
        {
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}

//10-3.16227

double prec(int pre, double m, int num)
{
    double add=0.1;
    int j=0;
    double ans; 
    while(j++<pre)
    {
        for(double i=m; i*i<num; i+=add)
        ans=i;
        add=add/10;
    }
    return ans;
}


int main()
{
    int num, precision;
    cout<<"enter num whose sq root needs to be find and its prcision : ";
    cin>>num>>precision;
    //20-10-5-2-3
    int m= Ans(num);
    double answer= prec(precision, m, num);
    cout<<"The answer is : "<<answer;
    return 0;
}