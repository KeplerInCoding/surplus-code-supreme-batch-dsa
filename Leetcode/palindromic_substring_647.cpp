// class Solution {
// public:
//     int isPalindrome(string s, int start, int end){
//         while(start<=end){
//             if(s[start]!=s[end]) return 0;
//             start++;
//             end--;
//         }
//         return 1;
//     }
//     int countSubstrings(string s) {
//         int l = s.length();
//         int count = l;
//         if(l<2) return count;
//         for(int i = 1; i<l; i++){
//             for(int start = 0; start<l-i; start++){
//                 if(isPalindrome(s, start, start+i)) count++;
//             }
//         }
//         return count;
//     }

    
// };



class Solution {
public:
    int expand(string s, int start, int end){
        int count = 0;
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
            count++;
            
        }
        return count;
    }
    int countSubstrings(string s) {
        int l = s.length();
        int count = 0;
        for(int i = 0; i<l; i++){
            count = count + expand(s, i, i);
            count = count + expand(s, i, i+1);

        }
        return count;
    }

    
};