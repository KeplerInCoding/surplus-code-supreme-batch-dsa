// //easy
// class Solution {
//     #include <unordered_map>
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map <char, char> h;
//         set <char> mySet;
//         int m = s.size();
//         int n = t.size();
//         if(m!=n) return false;

//         for(int i=0; i<m; i++){
//             if(h.find(s[i])==h.end()){
//                 if(mySet.count(t[i])!=1){
//                     h[s[i]]=t[i];
//                     mySet.insert(t[i]);
//                 }
//                 else return false;
                
//             }
            
//             else if(h[s[i]]!=t[i]) return false;

//         }
//         return true;
//     }
// };




class Solution {
    #include <unordered_map>
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> h;
        int p[256] = {0};
        int m = s.size();
        int n = t.size();
        if(m!=n) return false;

        for(int i=0; i<m; i++){
            if(h.find(s[i])==h.end()){
                if(p[t[i]]==0){
                    h[s[i]]=t[i];
                    p[t[i]] = 1;
                }
                else return false;
                
            }
            
            else if(h[s[i]]!=t[i]) return false;

        }
        return true;
    }
};