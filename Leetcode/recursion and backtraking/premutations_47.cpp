//medium

class Solution {
public:

    void perm(vector <int> &nums, vector <vector <int>> &ans, vector <int>v, vector<int> &track){

        if(v.size()==nums.size()) {
            ans.push_back(v);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(((i>0 && nums[i]==nums[i-1] && track[i-1]==0)) ||track[i]) continue;
            v.push_back(nums[i]);
            track[i]=1;
            perm(nums, ans, v, track);
            track[i]=0;
            v.pop_back();
        }

    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> v;
        sort(nums.begin(), nums.end());
        vector <int> track(nums.size(), 0);
        perm(nums, ans, v, track);

        return ans;
    }
};


