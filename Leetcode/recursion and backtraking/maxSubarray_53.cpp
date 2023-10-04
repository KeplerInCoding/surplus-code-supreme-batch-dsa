// Kadanes algo
//medium
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


// divide and conquer

// class Solution {
// public:

//     int rangeMax(vector <int> &nums, int start, int end){
//         int mid = start + ((end-start)>>1);
//         int rrmax = 0;
//         int lrmax = 0;
//         int sum = 0;
//         for(int i=mid-1; i>=0;  i--){
//             sum+=nums[i];
//             lrmax = max(lrmax,sum);
//         }

//         for(int i=mid+1; i<=end;  i++){
//             sum+=nums[i];
//             rrmax = max(rrmax,sum);
//         }

//         return (nums[mid]+lrmax+rrmax);
//     }
    
//     int divide(vector <int> &nums, int start, int end){
//         //bc
//         if(start==end) return nums[start];

//         int mid = start + ((end-start)>>1);

//         int rmax = divide(nums, mid+1, end);
//         int lmax = 0;
//         if(start!=mid) lmax = divide(nums, start, mid);
//         else lmax = nums[mid];
//         int rangeMax = divide(nums, start, end);

//         return max(rangeMax, max(lmax,rmax));
//     }

//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         int maxSum = nums[0];
//         int currentSum = nums[0];

//         for (int i = 1; i < n; i++) {
//             currentSum = max(nums[i], currentSum + nums[i]);
//             maxSum = max(maxSum, currentSum);
//         }

//         return maxSum;
//     }
// };