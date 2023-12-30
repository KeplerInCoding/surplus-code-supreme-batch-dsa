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

    TreeNode* fixNode(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2, unordered_map <int, int> &mp){
        if(e1-s1 <= -1) {
            return NULL;
        }
        // cout<<"s1 : "<<s1<<"  e1 : "<<e1<<"  s2 : "<<s2<<"  e2 : "<<e2<<endl;
        TreeNode* root=new TreeNode(NULL); 
        root->val = preorder[s1];
        int r = mp[preorder[s1]];
        root->left = fixNode(preorder, s1+1, s1+r-s2, inorder, s2, r-1, mp);
        root->right = fixNode(preorder, s1+r-s2+1, e1, inorder, r+1, e2, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int, int> mp;
        TreeNode* root = new TreeNode(NULL);
        int n = preorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
        root = fixNode(preorder, 0, n-1, inorder, 0, n-1, mp);
        return root;
    }
};