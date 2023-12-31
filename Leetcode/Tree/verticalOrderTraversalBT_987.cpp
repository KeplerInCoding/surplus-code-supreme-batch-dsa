//hard

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void trav(TreeNode* root, int dist,  map <pair<int,int>, vector <int>> &mp, int ht){
        if(root==NULL){
            return;
        }
        pair <int, int> p = {dist, ht};
        mp[p].push_back(root->val);
        trav(root->left, dist-1, mp, ht+1);
        trav(root->right, dist+1, mp, ht+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector <vector<int>> V;
        map <pair<int,int>, vector <int>> mp;
        trav(root, 0, mp, 0);
        for (auto it = mp.begin(); it != mp.end(); ++it){
            sort(it->second.begin(), it->second.end());
        }
        int dist = INT_MIN;
        for (auto it = mp.begin(); it != mp.end();) {
            dist = it->first.first;
            vector<int> v;
            while (it != mp.end() && it->first.first == dist) {
                for (int i = 0; i < (it->second).size(); i++) {
                    v.push_back(it->second[i]);
                }
                ++it;  
            }
            V.push_back(v);
        }

        return V;
    }
};