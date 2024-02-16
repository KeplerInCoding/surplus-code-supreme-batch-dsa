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

    TreeNode* buildTree(vector<int> &preorder, vector<int>& hash, int si, int ei, int sp){
        if(si>ei) return nullptr;

        TreeNode* newNode = new TreeNode;
        int ele = preorder[sp];
        newNode->val = ele;


        if(si==ei){
            return newNode;
        }
        int index = hash[ele];
        newNode->left = buildTree(preorder, hash, si, index-1, sp+1);
        newNode->right = buildTree(preorder, hash, index+1, ei, sp+1+index-si);
        return newNode;

    }



    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector <int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        vector<int> hash(1001, -1);
        for(int i=0; i<preorder.size(); i++){
            hash[inorder[i]]=i;
        }
        int s=0, e=preorder.size()-1;
        TreeNode* root;
        root = buildTree(preorder, hash, s, e, s);
        return root;
    }
};