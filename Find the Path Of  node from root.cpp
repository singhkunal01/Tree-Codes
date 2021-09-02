// TC: O(N)
// SC: O(Height of Tree)

// to find the path from a root to any of the node ...
bool givePath(Node *root,int tillThisNode,vector<int> &res){
  if(!root) 
    return false;
  
  res.push_back(root->val);
  
  if(root->val==tillThisNode) 
    return true; //if the value we want to find is FOUND till here then no need to search further and hence return true;
  
  if(givePath(root->left,tillThisNode,res) or givePath(root->right,tillThisNode,res)) 
    return true; //if value is not FOUND directly then go left and right and search there if it is found at any of the node then return true ;
  
  res.pop_back(); /* else start moving back and pop the values you pushed unwantedly 
  and this is also called backtracking (IN STRIVER BHAIYA'S LANGUAGE : PEN TODHA HAI TO JODNA BHI TO PADHEGA NA :-) */
  return false;
}

vector<int> findPath(Node *root , int findNode){
  vector<int> ans;
  
  if(!root) 
    return ans;
  givePath(root,findNode,ans);
  return ans;
}
