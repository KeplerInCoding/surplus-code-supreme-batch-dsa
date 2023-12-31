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

        
    void zag(stack <TreeNode*> &S, vector <vector<int>> &V, int odev){
        if(S.empty()) return;
        stack <TreeNode*> st;
        TreeNode *temp = NULL;
        vector <int> v;
        V.push_back(v);
        // cout<<"size of v : "<<V.size()<<endl;

        while(!S.empty()){ 
            temp = S.top();
            // cout<<S.top()->val<<endl;
            // cout<<temp->val<<endl;
            // cout<<"odev : "<<odev<<endl;
            V[odev].push_back(temp->val);
            // cout<<"push in v : "<<temp->val<<endl;
                    // cout <<"evv : "<<temp->right<< "  " <<temp->left<<endl;

            S.pop();
            if(temp){
                
                if(odev%2==0){
                    if (temp->left) {
                        // cout <<"evv : "<<temp->left->val<< endl;
                        st.push(temp->left);
                    }
                    if (temp->right) {
                        // cout <<"evv : "<<temp->right->val<< endl;
                        st.push(temp->right);
                    }
                }
                else{
                    if (temp->right) {
                        st.push(temp->right);
                        // cout <<"evv : "<<temp->right->val<< endl;
                    }
                    if (temp->left) {
                        st.push(temp->left);
                        // cout <<"evv : "<<temp->left->val<< endl;
                    }
                    
                }
            }
        }
        zag(st, V, odev+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> V;
        stack <TreeNode*> st;
        st.push(root);
        // cout<<"int main : st.top = "<<st.top()->val<<endl;
        if(root){
            int odev=0;
            zag(st, V, odev);
        }
        return V;
    }
};