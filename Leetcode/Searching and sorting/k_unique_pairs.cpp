// 532 
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array. 

// using binary search
class Solution {
public:

    int bs(vector<int> &nums, int start, int element){
        int end = nums.size()-1;
        
        while(start<=end){
            int mid = (start + end)/2;
            if(nums[mid]==element)
            return 1;
            if(nums[mid]<element)
            start=mid+1;
            else
            end=mid-1;

        }
        return 0;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set <pair<int,int>> s;

        for(int i = 0; i < nums.size()-1; i++)
        {
            if(bs(nums, i+1, nums[i]+k))
            {
                s.insert({nums[i], nums[i]+k});
            }
        }

        return s.size();
    }
};



// 2 pointer approach 

class Solution {
public:

    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set <pair<int,int>> s;
        int i = 0; 
        int j = 1;

        while(j<nums.size()){
            int diff = nums[j]-nums[i];
            if(diff==k){
                s.insert({nums[i], nums[j]});
                ++i;
                ++j;
            }
            else if(diff>k){
                i++;
            }
            
            else{
                j++;
            }
            
            if(i==j){
                j++;
            }
            
        }
        return s.size();
    }
    
    
};