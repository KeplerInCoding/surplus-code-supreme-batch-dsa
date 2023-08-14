//easy
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length()!=t.length()) return false;
//         for(int i =0; i< t.length(); i++){
//             int index = s.find(t[i]);
//             if(index== string::npos) return false;
//             s.erase(index,1);
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isAnagram(string s, string t) {
        int table[256]={0};

        for(int i=0; i<s.size(); i++){
            table[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            table[t[i]]--;
        }

        for(int i=0; i<256; i++){
            if(table[i]!=0)return false;
        }

        return true;

    }
};