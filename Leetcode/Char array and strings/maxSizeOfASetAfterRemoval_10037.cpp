//medium

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        const unordered_set<int> s1(nums1.begin(), nums1.end()),  s2(nums2.begin(), nums2.end());
        const int n = nums1.size(), m = n >> 1;
        int unique1 = 0, unique2 = 0;
        for (int x : s1) {
            if (s2.count(x) == 0) {
                ++unique1;
            }
        }
        for (int x : s2) {
            if (s1.count(x) == 0) {
                ++unique2;
            }
        }
        const int common = s1.size() - unique1;
        unique1 = min(unique1, m);
        unique2 = min(unique2, m);
        return unique1 + unique2 + min(n - unique1 - unique2, common);
        
    }
};

// class Solution {
// public:
//     int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {

//         unordered_set <int>s1;
//         unordered_set <int>s2;

//         int n1=nums1.size();
//         int n2=nums2.size();
//         int  dup1=0, dup2=0;
//         int common =0;

//         for(int i=0; i<n1; i++){
//             if(!s1.count(nums1[i])){
//                 s1.insert(nums1[i]);
//             }
//             else{
//                 dup1++;
//             }
//         }

//         for(int i=0; i<n2; i++){
//             if(!s2.count(nums2[i])){
//                 if(s1.count(nums2[i])){
//                     common++;
//                 }
//                 s2.insert(nums2[i]);
//             }
//             else{
//                 dup2++;
//             }
            
//         }
//         int half1=n1/2;
//         int half2=n2/2;
//         int penalty1=0; 
//         int penalty2=0;
//         int c = common; 
//         if(dup1<(half1)){
//             if(common<((half1-dup1))){
//                 penalty1=half1-dup1-common;
//                 common=0;
//             }
//             else{
//                 common=common-(half1-dup1);
//             }
//         }
//         if(dup2<(half2)){
//             if(common<((half2-dup2))){
//                 penalty2=half2-dup2-common;
//                 common=0;
//             }
//             else{
//                 common=common-(half2-dup2);
//             }
//         }
//         cout<<"s1 : "<<s1.size()<<"    s2 : "<<s2.size()<<"     penalty1 : "<<penalty1<<"    penalty2 : "<<penalty2<<"    common : "<<common<<endl;
//         return s1.size()+s2.size()-penalty1-penalty2-c;
//     }
// };