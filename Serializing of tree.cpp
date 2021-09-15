//using bfs traversal
    string st = "";
    if(!root) return st;
    queue<TreeNode *> ds({root});
    while(!ds.empty()){
        TreeNode *currNode = ds.front();
        ds.pop();
        if(!currNode) st += "*,";
        else st += to_string(currNode->val) + ',';
        if(currNode){
            ds.push(currNode->left);
            ds.push(currNode->right);
        }
    }
    return st;
}

//using iterative preorder traversal
    string st = "";
    if(!root) return st;
    stack<Node *> ds({root});
    while(!ds.empty()){
        Node *currNode = ds.top();
        ds.pop();
        if(!currNode) st += "*,";
        else st += to_string(currNode->val) + ',';
        if(currNode){
            ds.push(currNode->right);
            ds.push(currNode->left);
        }
    }
