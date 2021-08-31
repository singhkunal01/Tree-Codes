
 /*Bottom view of binary tree
           1
         /    \
        2        3
      /  \     /    \
    4     5   8       7
        /      \     /  \
       10       12  22    23
Bottom View of above binary tree is : 4 10 8 22 7 23 
*/ 
// Code :
vector<int> bottomView(Node *root,vector<int> &result){
if(!root) return result;
  queue<pair<Node *, int>> ds;
  map<int, int> bucket;
  ds.push({root, 0});
  while(!ds.empty()) {
      auto valuesOfQueue = ds.front();
      ds.pop();
      Node *tempNode = valuesOfQueue.first;
      int vertical = valuesOfQueue.second;
      bucket[vertical] = tempNode->val;// if the value is inserted previously then upcoming value on the same key or line will overlaps the value 
      if(tempNode->left) ds.push({tempNode->left, vertical - 1});
      if(tempNode->right) ds.push({tempNode->right, vertical + 1});
  }
  for(auto &val : bucket)
      result.push_back(val.second);
return result;
}

//Pre requisite - Must now the concept of Vertical Traversal of Binary Tree.
