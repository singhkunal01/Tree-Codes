// TC: O(N)
// SC: O(N) auxiliary space

Node *lowestCommonAncestor(Node *root, Node *p, Node *q) {
    if(!root or root == p or root == q) return root;
    Node *ans1 =  lowestCommonAncestor(root->left, p, q);
    Node *ans2 = lowestCommonAncestor(root->right, p, q);
    if(!ans1) return ans2;
    else if(!ans2) return ans1;
    else return root;
}
/*
let the tree whose LCA we want to find is :
            1
         /      \
        2         3
      /   \      /  \
     4     5     8    9
         /    \
       6       7 
       
  here , lowestCommonAncestor(root,4,7) = 2;
        lowestCommonAncestor(root,7,9) = 1;
        and so on...!!
*/
void solve() {
Node *root = makeTree();
Node *ans =  lowestCommonAncestor(root,root->left->left,root->left->right->right); //for 4 and 7
cout << ans->val;
}
