/* OPTIMISED ONE 
TC: O(N)
SC : O(N) */

int heightOfTree(Node *root, int &maximum) {
    if(root == NULL) return 0;
    int leftHeight = heightOfTree(root->left, maximum);
    int rightHeight = heightOfTree(root->right, maximum);
    maximum = max(maximum,leftHeight+rightHeight);
    return max(leftHeight, rightHeight) + 1;
}
int diameterOfaTree(Node *root) {
    int diameter = INT_MIN;
    heightOfTree(root, diameter);
    return diameter;
}


/* BRUTE FORCE
TC: O(N^2)
SC : O(N) */

 
