bool isLeafNode(TreeNode *root){
return !root->left and !root->right;
} // to check whether the node is leaf or not

void givePaths(TreeNode *root,string store, vector<string> &res){
if(!root) return;
if(isLeafNode(root)) {
    res.push_back(store + to_string(root->val));  //when we get the leaf node we can add 1 path (string) into the vector of string
}
givePaths(root->left,store + to_string(root->val)+"->", res);
givePaths(root->right,store + to_string(root->val)+"->", res);
}

    vector<string> binaryTreePaths(TreeNode* root) {
          vector<string> ans;
 givePaths(root,"",ans);
 return ans;
    }


..//in vector form

bool isLeafNode(Node *root){
    return (!root->left and !root->right);
}
void givePaths(Node *root, vector<int> &store, vector<vector<int>> &res) {
    if(!root) return;
        store.push_back(root->val);
    if(isLeafNode(root)) {
          res.push_back(store);//when we get the leaf node we can add 1 path (string) into the vector of string
    }
    givePaths(root->left, store, res);
    givePaths(root->right, store, res);
    store.pop_back();//this is the main step this is used to backtrack the entire traversal helps to remove unwanted values;
}

vector<vector<int>> binaryTreePaths(Node *root) {
    vector<int> ans;
    vector<vector<int>>res;
    givePaths(root,ans, res);
    return res;
}
