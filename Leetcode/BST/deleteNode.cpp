// //medium

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     TreeNode* findPred(TreeNode* root){ 
//         TreeNode* pred=root;
//         while(pred->left){
//             pred=pred->left;
//         }
//         return pred;
//     }

//     TreeNode* findKey(TreeNode* root, int key){
//         if(!root || root->val==key){
//             return root;
//         }
//         TreeNode* Node=NULL;
//         if(root->val>key){
//             Node = findKey(root->left, key);
//         }
//         else{
//             Node = findKey(root->right, key);
//         }
//         return Node;

//     }

//     TreeNode* deleteN(TreeNode* root){
//         if(!root->left && !root->right){
//             root=NULL;
//             if(!root)cout<<"NULL";
//             return root;
//         }
//         if(!root->left && root->right){
//             return root->right;
//         }
//         if(root->left && !root->right){
//             return root->left;
//         }

//         TreeNode* pred = findPred(root->right); //successor* not pred

//         root->val=pred->val;
//         pred = deleteN(pred);
//         if(!pred)cout<<"predNULL";

//         return root;
//     }

//     TreeNode* deleteNode(TreeNode* root, int key) {
//         TreeNode* temp = findKey(root, key);
//         if(temp){
//             temp = deleteN(temp);
//         }
        
//         return root;
//     }
// };


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


    int getSucc(TreeNode* succ){
        while(succ->left){
            succ=succ->left;
        }
        return succ->val;
    }

    TreeNode* deleteN(TreeNode* root, int key){
        if(!root) return root;
        if(root->val==key){
            if(!root->left && !root->right){
                return NULL;
            }
            if(root->left && !root->right){
                return root->left;
            }
            if(!root->left && root->right){
                return root->right;
            }
            //fing succ
            int succ = getSucc(root->right);
            root->val=succ;
            root->right = deleteN(root->right, succ);

        }
        else if(root->val>key){
            root->left = deleteN(root->left,  key);
        }
        else {
            root->right = deleteN(root->right,  key);
        }
        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deleteN(root, key);
        return root;

    }
};