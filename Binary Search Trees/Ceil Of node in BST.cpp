// ---------------------------- F I R S T   A P P R O A C H -------------------------------------

// TC: O(logn)
// SC:O(1)


/* NOTE: This approach can fail (may be) sometimes but the test cases on which i have tested are passed so please help me to send some cases on which it fails 
so that i can check whether this solution is right or not . */

int ceilOfBST(Node *root,int key){
    int ceil = -1;
    while(root){
        if(root->val < key){
            ceil = max(ceil,root->val);
            root = root->right;
        }
        else if(root->val > key){
            ceil = max(ceil,root->val);
            root = root->left;
        }
        else return key;
    }
    return ceil;
}

// ------------------------------------ S E C O N D   A P P R O A C H  ---------------------------------------

int ceilOfBST(Node *root,int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->val;
           return ceil;
        }
        else if(root->val > key){
            root = root->left;
            ceil = root->val; // it handles the case of root->val==key automatically,it always recieves the value as much smaller as it can
          
        }
        else 
          root = root->right;
    }
    return ceil;
}
