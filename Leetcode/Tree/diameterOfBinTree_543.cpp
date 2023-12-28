//easy

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

    int maxDepth(TreeNode* root, int &ans) {

        if(root == NULL) return 0;

        int L = maxDepth(root->left, ans);
        int R = maxDepth(root->right, ans);

        ans = max(L+R+1, ans);

        return max(L, R) + 1;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int D = maxDepth(root, ans);

        return ans-1;
    }
};