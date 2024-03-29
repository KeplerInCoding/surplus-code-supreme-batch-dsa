Node* BST_sucessor(Node* root, int key){
    Node* sucessor = NULL;
    while(root){
        if(root->val > key){
            sucessor = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return sucessor; 
}