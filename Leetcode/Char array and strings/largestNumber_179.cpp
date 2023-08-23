// //medium

// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return to_string (nums[0]);
//         vector <string> v;
//         for(int i=0; i<n; i++){
//             v.push_back(to_string(nums[i]));
//         }

//         for(int i=0; i<n-1; i++){
//             int flag = 0;
//             for(int j=0; j<n-i-1; j++){
//                 if(v[j]+v[j+1] < v[j+1]+v[j]){
//                     flag=1;
//                     swap(v[j], v[j+1]);
//                 } 
//             }
//             if(flag==0) break;
//         }

//         string ans;

//         for(int  i=0; i<n; i++){
//             ans = ans + v[i];
//         }

//         while (ans.size() > 1 && ans[0] == '0') {
//             ans.erase(0, 1);
//         }

//         return ans;
        
//     }
// };



class Solution {
public:
    static bool mycomp(string a,string b){
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
        sort(snums.begin(),snums.end(),mycomp);
        if(snums[0]=="0")return "0";
        string ans="";
        for(auto str: snums){
            ans +=str;
        }
        return ans;
    }
};