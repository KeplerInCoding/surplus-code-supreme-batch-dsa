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

    bool check(TreeNode* root, int &maxH){
        if(root == NULL) {
            maxH=0;
            return true;
        }
        int L = 0;
        bool boolL = check(root->left, L);

        int R = 0;
        bool boolR = check(root->right, R);
        maxH = max(L, R) + 1;
        if((L-R==0 || L-R==-1 || L-R==1) && (boolL && boolR)) return true;
        return false;
    } 


    bool isBalanced(TreeNode* root) {
        int h = 0;
        return check(root, h);
    }
};