//PRATA SPOJ




#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

int isPossible(vector <int> rank, int p, int n, int mid){
    // cout<<"mid : "<<mid<<"\n";

    int prata = 0;
    
    for(int i=0; i<n; i++){
        int diff = rank[i];
       
        for(int j=0; j<p; j++){
            int T = j+1;
            int time = diff*(T*(T+1)/2);
            if(time > mid) break;
            // cout<<"time : "<<time<<"\n";
            prata ++;
            // cout<<"prata : "<<prata<<"\n";
            if(prata >= p) return 1;
            
            
        }

    }

    // cout<<"prata for not poss : "<<prata<<"\n";

    return 0;
}

int main(){
    int k;
    cin>>k;
    vector <int> ans;
    for(int j=0; j<k; j++){
        int p, n;
        cin>>p>>n;
        vector <int> rank(n);
        int min = INT_MAX;

        for(int i=0; i<n; i++){
            cin>>rank[i];
            if(rank[i]<min) min = rank[i];
            

        }
        // cout<<"min : "<<min<<"\n";
        //sn = n/2(2a+(n-1)d)      n=p, a=min;
        int end = min*(p*(p+1)/2);
        int start = 0;
        int A =-1;

        while(start<=end){
            int mid = (start+end)/2;

            if(isPossible(rank, p, n, mid)){
                end = mid - 1;
                A = mid;
            }
            else start = mid+1;
        }
        // cout<<"answer : "<<ans<<"\n";
        ans.push_back(A);
    }
    for(int i = 0; i<k; i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}