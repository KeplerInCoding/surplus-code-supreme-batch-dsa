//medium

//gfg

//{ Driver Code Starts
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    vector < long long > v;
    queue <long long> q;
    for(long long int i=0; i<k; i++){
        if(A[i]<0){
            q.push(i);
            // cout<<i<<endl;
        }
        
    }
    
    for(long long int i = k; i<N; i++){
        if(!q.empty()){
            v.push_back(A[q.front()]);
            // cout<<A[q.front()]<<endl;
        }
        else{
            v.push_back(0);
        }
        if(!q.empty() && (i-q.front()>=k)){
            q.pop();
        }
        if(A[i]<0){
            q.push(i);
        }
    }
    if(!q.empty()) v.push_back(A[q.front()]);
    else v.push_back(0);
    return v;
 }

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    vector < long long > v;
    queue <long long> q;
    for(long long int i=0; i<k; i++){
        if(A[i]<0){
            q.push(i);
            // cout<<i<<endl;
        }
        
    }
    
    for(long long int i = k; i<N; i++){
        if(!q.empty()){
            v.push_back(A[q.front()]);
            // cout<<A[q.front()]<<endl;
        }
        else{
            v.push_back(0);
        }
        if(!q.empty() && (i-q.front()>=k)){
            q.pop();
        }
        if(A[i]<0){
            q.push(i);
        }
    }
    if(!q.empty()) v.push_back(A[q.front()]);
    else v.push_back(0);
    return v;
 }