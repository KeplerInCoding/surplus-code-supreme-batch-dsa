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
            cout<<v[i]<<endl;
            sum(v, t-v[i], ans, s, i);
            s.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> s; 
        sum(candidates, target, ans, s, 0);

        return ans;
    }
};