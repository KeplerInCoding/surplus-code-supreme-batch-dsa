class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < n; i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            // cout << "i: "<<i<<"  cursum= "<<currentSum<<"  nums[i]: = "<<nums[i]<<endl;
            maxSum = max(maxSum, currentSum);
            // cout <<"  maxsum="<<maxSum<<endl;

        }

        return maxSum;
    }
};