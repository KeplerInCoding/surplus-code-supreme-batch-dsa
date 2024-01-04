//medium

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

    string coding(TreeNode* root, map <string, int> &v, vector <TreeNode*> &ans){
        if(!root) return "null";
        string s = to_string(root->val);
        string s1 = coding(root->left, v, ans);
        string s2 = coding(root->right, v, ans);
        
        string st = s + "," + s1 + "," + s2;
        auto it = v.find(st);
        if(it==v.end()) v[st] = 1;
        else {
            if(v[st]==1)ans.push_back(root);
            v[st]++;
        }
        return st;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map <string, int> v;
        vector <TreeNode*> ans;
    
        string s = coding(root, v, ans);
        return ans;
    }
};