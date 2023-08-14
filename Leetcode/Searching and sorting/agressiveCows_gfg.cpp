//gfg question

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:

    int ispossible(vector<int> &a, int k, int n, int mid){
        int count = 1;
        int maxSum = 0;


        //alt solution
        // int pos = a[0];

        // for(int i=1; i<n; i++){
        //     if(a[i]-pos>=mid){
        //         count++;  //one more cow has been placed
        //         pos=a[i];
        //     }
        //     if(c==k) return true; 
        // }
        // return false;





        
        for(int i=1; i<n; i++){
            int diff = a[i]-a[i-1];
            
            if(diff+maxSum>=mid){
                count++;
                maxSum=0;
            }
            else maxSum+=diff;
        }
        
        if(count<k){
            return 0;
        }
        else{
            return 1;
        }
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        
        
        int start = 0;
        int end = stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(start<=end){
            int mid = (start+end)/2;  //start+end >> 1
            
            if(ispossible(stalls, k, n, mid)){
                start=mid+1;
                ans=mid;
            }
            else end=mid-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends