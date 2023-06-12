#include <cmath>
#include <vector>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int end = arr.size()-1;
        int start = 0;
        int count = 0;
        vector<int> ans;
        while(end-start>=k){
            int l = abs(arr[start]-x);
            int r = abs(arr[end]-x);
            if(l>r){
                start++;
            }
            else{
                end--;
            }
        }
        // for(int i=start;i<=end; i++){
        //     ans.push_back(arr[i]);
        // }
        return vector<int> (arr.begin()+start, arr.begin()+start+k);
    }
    
};