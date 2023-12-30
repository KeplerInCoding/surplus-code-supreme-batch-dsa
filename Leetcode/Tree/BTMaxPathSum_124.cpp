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

    int max_path(TreeNode *root, int &ans){
        if(root==NULL)return 0;
        int L = max_path(root->left, ans);
        int R = max_path(root->right, ans);
        cout<<"root : "<< root->val<<endl;
        cout<<ans<<" "<<L+R+root->val<<" "<<L+root->val<<" "<<R+root->val<<endl; 
        ans = max(ans, max(max(L+R+root->val, max(L+root->val, R+root->val)), root->val));
        return max(max(L, R)+root->val, root->val);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int p = max_path(root, ans);
        return ans;
    }
};