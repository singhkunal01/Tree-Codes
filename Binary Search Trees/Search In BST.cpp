//------------------------- R E C U R S I V E -----------------------------------
// TC: O(logn)
// SC:O(N)

Node *searchInABST(Node *root,int NodeToFind){
    if(root == NULL) return NULL;
    Node * curr = root;
    if(root->val < NodeToFind) curr = searchInABST(root->right, NodeToFind);
    else if(root->val > NodeToFind) curr = searchInABST(root->left, NodeToFind);
    else if(root->val == NodeToFind) return root;
    else return NULL;
    return curr;
}



//------------------------- I T E R A T I V E -----------------------------------
// TC: O(logn)
// SC:O(1)

Node *searchInABST(Node *root,int NodeToFind){
 while(root and root->val != NodeToFind){
    if(root->val < NodeToFind) 
        root = root->right;
    else root = root->left;
    }
    return root;
}

