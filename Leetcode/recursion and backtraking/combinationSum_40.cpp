//medium

class Solution {
public:

    void sum(vector<int>& v, int t, vector<vector<int>>&ans, vector<int> &s, int start){
        if(t<0) return;
        if(t==0){
            ans.push_back(s);
        }

        for(int i=start; i < v.size();  i++){
            s.push_back(v[i]);
            sum(v, t-v[i], ans, s, i+1);
            s.pop_back();
            while(((i+1)<v.size()) && (v[i+1]==v[i])) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> s; 
        sort(candidates.begin(), candidates.end());
        sum(candidates, target, ans, s, 0);

        return ans;
    }
};