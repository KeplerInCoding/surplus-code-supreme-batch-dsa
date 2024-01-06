//hard

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            while((nums[i]>0) && (nums[i]<=n) && nums[i]!=nums[nums[i]-1]){
                cout<<"i1 : "<<i<<"   nums[i] : "<<nums[i]<<endl;
            swap(nums[i], nums[nums[i]-1]);
            cout<<"i2 : "<<i<<"   nums[i] : "<<nums[i]<<endl;
            }

            cout<<"out "<<endl;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i+1) return i+1;
            cout<<"ret :"<<nums[i]<<"  i : "<<i<<endl;

        }
        return nums.size()+1;
    }
};