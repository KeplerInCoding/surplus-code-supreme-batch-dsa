class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        for(int i =0; i< t.length(); i++){
            int index = s.find(t[i]);
            if(index== string::npos) return false;
            s.erase(index,1);
        }
        return true;
    }
};