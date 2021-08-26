/* ========= OPTIMISED ONE============*/
// TC : O(N) 
// SC : O(N) // auxiliary space(recursion stack)

/*EXPLANATION: in this problem first we find the height of left subtree and right subtree then
we can simply add the condition which checks whether the tree is balanced or not i.e., if(abs(lh - rh)>1) return -1 here
we are adding one more condition which helps to save us to traversed the whole tree i.e.,
if(lh == -1 or rh == -1) return -1 it means while traversal whenever we get the value -1 that means we can return there 
because if any of the root has BALANCE FACTOR >1 it is not the balanced tree but here we this BALANCE FACTOR >1 equivalents to
~ -1 means false condition. */

int checkHeight(Node *root)
{
    if(root == NULL) return 0;
    int leftSubtreeHeight = checkHeight(root->left);
    int rightSubtreeHeight = checkHeight(root->right);
    if(leftSubtreeHeight == -1 or rightSubtreeHeight == -1) return -1;
    if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1) return -1;
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1; //height of (left+right) subtree + 1(for root)
}
bool isBalanced(Node *root){
    if( checkHeight(root)!=-1) return true;
else return false;
}


/* ========= BRUTE FORCCE ONE============*/
// TC : O(N)*O(N) one for finding the height of a tree + one for checking the whole tree (1 traversal)
//SC: O(N)
int heightOfTree(Node *root){
        if(root == NULL) return 0;
   int leftHeight = heightOfTree(root->left);
   int rightHeight = heightOfTree(root->right);
   return max(leftHeight,rightHeight)+1;
}
bool isBalanced(Node *root){
if(root == NULL) return true;
int leftSubtree = heightOfTree(root->left);
int rightSubtree = heightOfTree(root->right);
if(abs(leftSubtree - rightSubtree)>1) 
    return false;
return true;
if(isBalanced(root->left)==false or isBalanced(root->right)==false) 
    return false;
}
