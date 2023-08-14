//medium



// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         vector <vector<string>> V;
//         vector <string> s;

//         for(int i=0; i<strs.size(); i++){
//             s.push_back(strs[i]);
//             sort(s[i].begin(),s[i].end());
//         }
        
//         for(int i=0; i<strs.size(); i++){
//             if(s[i]!="-1"){
//                 vector <string> v;
//                 v.push_back(strs[i]);


//                 for(int j=i+1; j<strs.size(); j++){
//                     if(s[i]==s[j]){
//                         v.push_back(strs[j]);
//                         s[j]="-1";

//                     }
                
//                 }
//                 s[i]="-1";
//                 if(v.size()!=0){
//                     V.push_back(v);
//                 }
//             }
//         }
//         return V;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map <string, vector<string>> mp;

        for(auto s:strs){
            string str = s;
            sort(str.begin(), str.end());
            mp[str].push_back(s);
        }
 
        vector <vector<string>> ans;

        for(auto it=mp.begin();it!=mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};