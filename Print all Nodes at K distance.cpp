void findParent(TreeNode*root, unordered_map<TreeNode*, TreeNode*> &parents, TreeNode*target) {
    queue<TreeNode*> ds({root});
    while(!ds.empty()) {
        TreeNode* temp = ds.front(); ds.pop();
        if(temp->left){
            parents[temp->left]=temp;
            ds.push(temp->left);
        }
           if(temp->right){
            parents[temp->right]=temp;
            ds.push(temp->right);
        }
    }
}
        vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> parentsCheck;
    findParent(root, parentsCheck, target);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> ds({target});
    visited[target] = true;
    int currLevel = 0;
    while(!ds.empty()) {
        if(currLevel++ == k) break;
        int len = size(ds);
        for(int i = 0 ; i < len; i++) {
            TreeNode *nodeLevels = ds.front();
            ds.pop();
            if(nodeLevels->left and !visited[nodeLevels->left]) {
                ds.push(nodeLevels->left);
                visited[nodeLevels->left] = true;
            }
            if(nodeLevels->right and !visited[nodeLevels->right]) {
                ds.push(nodeLevels->right);
                visited[nodeLevels->right] = true;
            }
            if(parentsCheck[nodeLevels] and !visited[parentsCheck[nodeLevels]]) {
                ds.push(parentsCheck[nodeLevels]);
                visited[parentsCheck[nodeLevels]] = true;
            }
        }
    }
    vector<int> res;
    while(!ds.empty()){
        TreeNode* nodesLeft = ds.front();
        ds.pop();
        res.push_back(nodesLeft->val);
    }
    return res;
    }
