/*Top view of binary tree
           1
         /    \
        2        3
      /  \     /    \
    4     5   8       7
        /      \     /  \
       10       12  22    23
Top View of above binary tree is : 4 2 1 3 7 23
*/ 
// Code :
vector<int> topViewOfBinaryTree(Node *root , vector<int>&result){
  if(!root) return result;
  queue<pair<Node *, int>> ds;
  map<int, int> bucket;
  ds.push({root, 0});
  while(!ds.empty()) {
      auto valuesOfQueue = ds.front();
      ds.pop();
      Node *tempNode = valuesOfQueue.first;
      int vertical = valuesOfQueue.second;
      /*but we have to notice one thing here that if the key i.e., vertical value is don't exist only when we have to insert these values into map otherwise no need to insert them
      simply if we can say then the conclusion is map contains only distinct(unique) keys i.e., verticals*/
      if(bucket.find(vertical) != bucket.end()) bucket[vertical] = tempNode->val;
      if(tempNode->left) ds.push({tempNode->left, vertical - 1});
      if(tempNode->right) ds.push({tempNode->right, vertical + 1});
  }
  for(auto &val : bucket)
      result.push_back(val.second);
return result;
}

//Pre requisite - Must now the concept of Vertical Traversal of Binary Tree.
