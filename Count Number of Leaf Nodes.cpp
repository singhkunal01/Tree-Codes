int countNumberOfLeaves(Node *root){
if(root==NULL) return 0; //if means either left node is null or right node is null so return 0;
else if (root->left == NULL and root->right ==NULL) return 1; //when both the left and right nodes are null which means that node is a leaf node so return 1;
int lh = countNumberOfLeaves(root->left);
int rh = countNumberOfLeaves(root->right);
return lh+rh;
}
