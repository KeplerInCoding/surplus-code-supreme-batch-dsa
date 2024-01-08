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

    bool set_ans(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &node){
        if(root==NULL) return false;
        if((root == q) || (root == p)) {
            node = root;
            return true;
        }
        bool L = set_ans(root->left, p, q, node);
        bool R = set_ans(root->right, p, q, node);

        if(R && L){
            node = root;
            return false;
        }
        if(R || L){
            return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = NULL;
        set_ans(root, p, q, node);
        return node;
    }
};