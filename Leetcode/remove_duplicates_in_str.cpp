//leetcode 1047  Remove All Adjacent Duplicates In String
class Solution {
public:
    string removeDuplicates(string s) {
        int i =0;
        string m ="";
        while(i<s.length()){
            if(m.length()!=0 && m[m.length()-1]==s[i]){
                m.pop_back();

            }
            else m.push_back(s[i]);
            i++;
        }
        return m;
    }
    
};