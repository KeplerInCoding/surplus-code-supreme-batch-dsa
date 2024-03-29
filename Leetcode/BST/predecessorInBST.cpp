Node* find_predecessor(Node* root, int key){
    Node* predecessor = NULL;
    while(root){
        if(root->val < key){
            predecessor = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return predecessor;
}