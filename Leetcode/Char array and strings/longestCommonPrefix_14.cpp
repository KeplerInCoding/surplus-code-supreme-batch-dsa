//easy
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(strs[i][j]!=s[j]){
                    s.replace(0, s.size(), strs[i], 0, j);
                    break;
                }
            }
        }
        return s;
        
    }
    
};