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

    bool checkBST(TreeNode* root, long long int upper, long long int lower){
        //base case
        if(!root) return true;

        return checkBST(root->left, root->val, lower) && checkBST(root->right, upper, root->val) && root->val < upper && root->val>lower;
    }

    bool isValidBST(TreeNode* root) {
        long long int upper = LONG_MAX;
        long long int lower = LONG_MIN;
        return checkBST(root, upper, lower);
    }
};