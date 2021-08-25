/*============== FIND THE SIZE OF A TREE ====================*/

// SIZE OF A TREE == SIZE OF A LEFT SUB-TREE + SIZE OF RIGHT SUB-TREE + 1(ROOT);
int sizeOfTree(Node *root){
    if(root == NULL) return 0;
    return sizeOfTree(root->left)+sizeOfTree(root->right)+1;
}
