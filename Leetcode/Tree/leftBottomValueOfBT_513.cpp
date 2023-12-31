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

    void setbottom(TreeNode* root, int dist, pair <int, int> &ans){
        if(!root->left && !root->right){
            if(ans.second<dist){
                ans.second = dist;
                ans.first = root->val;
            }   
        }
        if(root->left) setbottom(root->left, dist+1, ans);
        if(root->right) setbottom(root->right, dist+1, ans);
    }


    int findBottomLeftValue(TreeNode* root) {
        int dist = 0;
        pair <int, int> ans  = {-1, INT_MIN};
        setbottom(root, dist, ans);
        return ans.first;
    }
};