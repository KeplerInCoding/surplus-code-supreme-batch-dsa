#include <iostream>
using namespace std;
#include <vector>

int isPossible(vector <int> a, int mid, int n, int need){
    int count = 0;
    int sum = 0; 

    for(int i = 0; i<n; i++){
        if(a[i]<mid) continue;
        sum = sum + a[i] - mid;
        if(sum>=need) return 1;
    }
    return 0;
}

int main(){
    int n, need;
    cin>>n>>need;
    vector <int> a(n);
    int maxH = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(maxH<a[i]) maxH=a[i];
    }
    int ans = -1;

    int start = 0;
    int end = maxH;

    while(start<=end){
        int mid = (start+end)/2;

        if(isPossible(a, mid, n, need)){
            ans = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    cout << ans;
    return ans;
}