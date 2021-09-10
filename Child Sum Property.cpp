void childSumProperty(Node *root){
    if(!root) return ;
    int child = 0;
    if(root->left) child+=root->left->val;//if there exist a value at left then add it to the child
    if(root->right) child+=root->right->val;//if there exist a value at right then add it to the child
    if(child>=root->val) root->val= child; //if the child value is greater than the root->val then simply replace the root's value by the child value 
    else { //if the value of child is less  than the root->val then -
        if(root->left) root->left->val= root->val;
        else if(root->right) root->right->val= root->val;
    }
    childSumProperty(root->left);//call for the left
    childSumProperty(root->right);//call for the right
    int totalSum = 0;
    if(root->left) totalSum+=root->left->val; //while going back sum up the childrens then send it to their parent 
    if(root->right) totalSum+=root->right->val;
    if(root->left or root->right) root->val=totalSum;
}

// TC: O(N)
// sC: O(N)
