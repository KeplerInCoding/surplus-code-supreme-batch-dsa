// Given a sorted integer array arr, two integers k and x, return the k 
// closest integers to x in the array. The result should also be sorted in ascending order.


//2 pointer method
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






//binary search method
#include <cmath>
#include <vector>
class Solution {
public:
// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
    int bs(vector<int> &arr, int x){
        int n= arr.size();
        int high = n-1;
        int start = 0;
        int end = n-1;

        while(start<=end){
            int mid = (start + end)/2;
            if(arr[mid]<x){
                start = mid+1;
            }
            else{
                high = mid;
                end = mid-1;
                
            }

            
        }
        return high;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //using binary search
        int high = bs(arr, x);
        int low = high-1;
        while(k--){
            if(high>=arr.size())
            low--;
            else if(low<0)
            high++;
            else if(arr[high]-x < x-arr[low])
            high++;
            else
            low--;
        }
        return vector<int> (arr.begin()+low+1, arr.begin()+high);
    }
    
};
