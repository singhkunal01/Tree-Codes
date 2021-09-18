//-----------------------------  F I R S T   A P P R O A C H -------------------------

//This approach will always attach the right subtree of target(to be delete node) into the left subtree at last and righmost node
Node *findRightmostNode(Node *root){
if(root->right == NULL) return root;
return findRightmostNode(root->right);
}

Node *helper(Node *root){
if(root->left == NULL) return root->right;
if(root->right == NULL) return root->left;
Node *rightChildren = root->right;
Node *lastRightmostChildren = findRightmostNode(root->left);
lastRightmostChildren->right = rightChildren;
return root->left;
}

 Node *deleteInBST(Node *root, int target) {
if(!root) return NULL;
if(root->val==target) return helper(root);
Node *dummy = root;
while(root){
    if(root->val >target){
        if(root -> left and root->left->val ==target){
            root->left = helper(root->left);
            break;
        }
        else root = root->left;
    }
    else{
        if(root -> right and root->right->val ==target){
            root->right = helper(root->right);
            break;
        }
        else root = root->right;
    }
}
   
return dummy;
}


// TC:O(height of a tree)
// SC:O(1)
