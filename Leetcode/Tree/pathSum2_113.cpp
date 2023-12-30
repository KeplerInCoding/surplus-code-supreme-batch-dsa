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


    void find_path(TreeNode* root, int sum, vector <int> &k, vector <vector<int>> &ans){
        if(root==NULL) return;
        sum-=root->val;
        k.push_back(root->val);
        if(sum==0 && !root->left && !root->right){
            ans.push_back(k);
            k.pop_back();
            return;
        }
        find_path(root->left, sum, k, ans);
        find_path(root->right, sum, k, ans);
        k.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector <int> k;
        find_path(root, targetSum, k, ans);
        return ans;
        
    }
};