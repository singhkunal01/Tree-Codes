// TC: O(N)
// SC: O(N) //it might be very large the when the tree is full binary tree


vector<int> leftViewOfATree(Node *root){
  vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<Node*,int>> bucket;
    map<int,int> mp;
    bucket.push({root,0});
    while(!bucket.empty()){
      auto newNode = bucket.front();
      bucket.pop();
      Node *myNode = newNode.first; 
      int level = newNode.second;
      if(mp.find(level)==mp.end()) mp[level]=myNode->val;
      if(myNode->left) bucket.push({myNode->left,level+1});
      if(myNode->right) bucket.push({myNode->right,level+1});
}
for(auto &node:mp)
  ans.push_back(node.second);
return ans;
}
