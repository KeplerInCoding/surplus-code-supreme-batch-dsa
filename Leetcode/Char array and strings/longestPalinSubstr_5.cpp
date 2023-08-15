//medium

class Solution {
public:

    int lenPalin(string s, int start, int end){//start =0, end = 1;
        if(start!=end && s[start]!=s[end]) return 0;
        int ans = end - start + 1;

        while(((--start)>=0) && ((++end)<s.size()) && (s[start]==s[end])){

            ans = end - start + 1;
        }
        return ans;
    }

    string longestPalindrome(string s) {
        
        string ans;
        int max=0;


        //odd
        for(int i=0; i<s.size(); i++){
            int m = lenPalin(s, i, i);
            if(max<m) {
                max = m;
                ans = s.substr(i - max/2, max);
            }

        }

        //even

        for(int i=0; i<s.size()-1; i++){
            int m = lenPalin(s, i, i+1);
            if(max<m) {
                max = m;
                ans = s.substr(i - max/2 + 1, max);

            }

        }
        return ans;
        
    }
};