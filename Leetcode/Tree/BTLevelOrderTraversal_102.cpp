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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> V;
        if(!root) return V;

        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            vector <int> v(width);

            for(int i=0; i<width; i++){
                v[i] = q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            V.push_back(v);
        }
        return V;
    }
};