//medium

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    bool checkExists(TreeNode* root, int p){
        // basecase
        if(!root) return false;
        if(root->val==p) return true;
        if(p<root->val) return checkExists(root->left, p);
        return checkExists(root->right, p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        if((p->val < q->val && checkExists(root, p->val) && checkExists(root, q->val))
        || (p->val > q->val && checkExists(root, q->val) && checkExists(root, p->val))) return root;
        return NULL;
    }
};