//medium

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//1,2,3,4,5,6,7,8,9   
//81-100   81/2= 40*2, 81/3= 27
#include <math.h>

class Solution{
public:
    vector <int> segSieve(int n){
        vector <int> v(n,1);
        v[0]=v[1]=0;
        int k=2;
        
        while(k*k<n){
            if(v[k]!=0){
                for(int i=k*k; i<n; i=i+k){
                    v[i]=0;
                }
            }
            k++;
        }
        
        return v;
    }
    long long primeProduct(long long L, long long R){
        // code here
        
        vector <int> block (R-L+1, 1);
        
        vector <int> v = segSieve(sqrt(R)+1);
        
        if(L==0){
            block[0]=block[1]=0;
        }
        if(L==1){
            block[0]=0;
        }
        
        
        
        
        for(int i=0; i<v.size(); i++){
            if(v[i]!=0){
                int m = L/i * i;   //m = first_multiple
                m = m<L?m+i:m;
                m=max(m, i*i);
                for(int j=m; j<=R; j=j+i) {
                    block[j-L]=0;
                }  
            }
        }
        
        int p=1;
        for(int i=0; i<block.size(); i++){
            if(block[i]!=0){
                p = (p * (i + L)) % 1000000007;
            }
        }
        return p;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends