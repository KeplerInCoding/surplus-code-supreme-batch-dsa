class Solution {
public:

    bool ispalin(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }


    bool validPalindrome(string s) {
        int l = s.length();
        int start= 0; 
        int end = l-1;
        while(start<=end){
            if(s[start]!=s[end]){
                return (ispalin(s, start+1, end) || ispalin(s, start, end-1));
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};