vector<vector<int>> bfs(Node *root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> bucket;
    bucket.push(root);
    while(!bucket.empty()){
    int sz = bucket.size();
    vector<int> everyLevel;
    for(int i=0; i<sz;i++){
      Node *eachNode = bucket.front();
      bucket.pop();
      if(eachNode->left!=NULL) bucket.push(eachNode->left);
      if(eachNode->right!=NULL) bucket.push(eachNode->right);
      everyLevel.push_back(eachNode->val);
   }
   ans.push_back(everyLevel);
}
return ans;
}
