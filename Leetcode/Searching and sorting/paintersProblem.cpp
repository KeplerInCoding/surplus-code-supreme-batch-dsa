//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    int ispossible(int arr[], int k, int n, long long mid){
          int count=1;
          
          long long maxSum = 0;
          for(int i=0; i<n; i++){
              if(arr[i]>mid) return 0;
              
              if(arr[i]+maxSum>mid){
                  count++;
                  maxSum=arr[i];
                  if(count>k){
                      return 0;
                  }
              }
              else{
                  maxSum=maxSum+arr[i];
              }
          } 
          return 1;
    }
        
    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
        
        for(int i=0; i<n; i++){
            sum=sum+arr[i];
        }
        
        long long ans = -1;
        long long start = 0; 
        long long end = sum;
        
        
        
        while(start<=end){
            long long mid = (start+end)/2;
            
            if(ispossible(arr, k, n, mid)){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
        }
        
        
        
            
       
        
        
        
        // return minimum time
        return ans;
    }
};

//{ Driver Code Starts.
//painters problem gfg
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends