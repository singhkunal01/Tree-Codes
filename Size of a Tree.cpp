/*============== FIND THE SIZE OF A TREE ====================*/

// SIZE OF A TREE == SIZE OF A LEFT SUB-TREE + SIZE OF RIGHT SUB-TREE + 1(ROOT);
//SIZE OF TREE MEANS = HOW MAY NUMBER OF NODES ARE THERE IN A WHOLE TREE
int sizeOfTree(Node *root){
    if(root == NULL) return 0;
    int NumberOfNodesInLeft = sizeOfTree(root->left);
    int NumberOfNodesInRight = sizeOfTree(root->right);
    
    return NumberOfNodesInLeft + NumberOfNodesInRight + 1; //added one for root
}
