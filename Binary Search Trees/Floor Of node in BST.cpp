// ---------------------------- F I R S T   A P P R O A C H ------------------

// TC: O(logn)
// SC:O(1)

int floorOfBST(Node *root,int key){
    int floorVal = -1;
    while(root){
        if(root->val == key){
            floorVal = root->val;
           return floorVal;
        }
        else if(root->val < key){
            floorVal = root->val; // it handles the case of root->val==key automatically,it always recieves the value as much greater as it can
            root = root->right;
          
        }
        else 
          root = root->left;
    }
    return floorVal;
}
