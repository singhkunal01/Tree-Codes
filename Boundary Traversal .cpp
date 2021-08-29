 //TRAVESAL OF BOUNDARY ANTICLOCK WISE i.e., FROM LEFT TO RIGHT



//to check whether the node is leaf or not
 bool isLeafNode(Node *root){
  return (!root->left && !root->right);
 }



//to find the left boundary excluding the root node and leaf Nodes
 void leftBoundary(Node *root,vector<int>& boundary){
  Node *curr = root->left;
  while(curr){
    if(!isLeafNode(curr)) boundary.push_back(curr->val);
    if(curr->left) curr = curr->left;
    else curr = curr->right;
  }
 }


//to find the right boundary excluding the root node and leaf Nodes
 void rightBoundary(Node *root,vector<int>& boundary){
  Node *curr = root->right;
  vector<int> reversedRightBoundary;
  while(curr){
    if(!isLeafNode(curr)) reversedRightBoundary.push_back(curr->val);
    if(curr->right) curr = curr->right;
    else curr = curr->left;
  }
  for(int i= reversedRightBoundary.size()-1;i>=0;i--)
    boundary.push_back(reversedRightBoundary[i]);
 }




//to find the bottom boundary i.e., leaf nodes
 void bottomBoundaryOrLeafNodes(Node *root,vector<int>& boundary){
if(isLeafNode(root)) {
  boundary.push_back(root->val);
  return ;
 }
 if(root->left) bottomBoundaryOrLeafNodes(root->left,boundary);
 if(root->right) bottomBoundaryOrLeafNodes(root->right,boundary);
 }
vector<int> printBoundaryOfTree(Node *root){
  vector<int> finalBoundary;
  if(root==NULL) return finalBoundary;
  if(!isLeafNode(root)) finalBoundary.push_back(root->val);
  leftBoundary(root,finalBoundary);
  bottomBoundaryOrLeafNodes(root,finalBoundary);
  rightBoundary(root,finalBoundary);
  return finalBoundary;
}


// TC: O(3N) ~= O(N)
// SC : o(N)
