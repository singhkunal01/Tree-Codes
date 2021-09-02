bool isLeafNode(TreeNode *root){
return !root->left and !root->right;
} // to check whether the node is leaf or not

void givePaths(TreeNode *root,string store, vector<string> &res){
if(!root) return;
if(isLeafNode(root)) {
    res.push_back(store + to_string(root->val));  //when we get the leaf node we can add 1 path (string) intto the vector of string
}
givePaths(root->left,store + to_string(root->val)+"->", res);
givePaths(root->right,store + to_string(root->val)+"->", res);
}

    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string> ans;
 givePaths(root,"",ans);
 return ans;
    }
