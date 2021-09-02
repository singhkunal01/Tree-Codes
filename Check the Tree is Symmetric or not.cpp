// TC: O(N)
// SC: O(Height of Tree)

// For better understanding first watch the video of ARE THE TWO TREES ARE SAME OR NOT

    bool helpToFindSymmetricalForTwoNodes(Node *root1,Node *root2){
if(!root1 or !root2) return root1==root2;
return root1->val == root2->val && 
helpToFindSymmetricalForTwoNodes(root1->left,root2->right) && 
helpToFindSymmetricalForTwoNodes(root1->right,root2->left);
}


bool isTreeSymmetrical(Node *root){
  if(!root) return true;
return helpToFindSymmetricalForTwoNodes(root->left,root->right);
}
