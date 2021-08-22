/* ====================== DEPTH FIRST SEARCH TRAVESAL =====================*/
// inorder traversal 
//started on Aug 20,2021
void inorder(Node *root){
    if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->val<<" -> ";
  inorder(root->right);
  if(root->left== NULL or root->right == NULL) cout<<"Null   ";
}

// preorder traversal
void preorder(Node *root){
    if(root==NULL)
    return;
  cout<<root->val<<" -> ";
  preorder(root->left);
  preorder(root->right);
  if(root->left== NULL or root->right == NULL) cout<<"Null   ";
}

// postorder traversal
void postorder(Node *root){
    if(root==NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->val<<" -> ";
  if(root->left== NULL or root->right == NULL) cout<<"Null   ";
}
