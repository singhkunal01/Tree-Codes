//PROBLEM LINK : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

vector<vector<int>> verticalOrderTraversal(Node *root){
  vector<vector<int>> ans;
  if(!root) return ans;
  queue<pair<Node*,pair<int,int>>> ds;
  map<int,map<int,multiset<int>>> bucket;
  ds.push({root,{0,0}});
while(!ds.empty())
{
    auto qu = ds.front();
    ds.pop();
    Node *temp = qu.first;
    int vertical = qu.second.first, level = qu.second.second;
    bucket[vertical][level].insert(temp->val);
    if(temp->left) ds.push({temp->left, {vertical - 1, level + 1}});
    if(temp->right) ds.push({temp->right, {vertical + 1, level + 1}});
}
  for(auto &x:bucket){
    vector<int> res;
    for(auto &y:x.second){
      res.insert(res.end(),y.second.begin(),y.second.end());
    }
    ans.push_back(res);
  }
  return ans;
 }

// TC: O(N) + O(logN)== O(logN) for insertion of multiset (ignore it)
// SC: O(N) + O(3N)



// WITHOUT USING COMPLICATED MAP IN MAP JUST USE LIST INSTEAD OF THAT..
//at gfg: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
    //   vector<vector<int>> ans;
    vector<int> res;
  if(!root) return res;
  queue<pair<Node*,int>> ds;
  map<int,list<int>> bucket;
  ds.push({root,0});
while(!ds.empty())
{
    auto qu = ds.front();
    ds.pop();
    Node *temp = qu.first;
    int vertical = qu.second;
    bucket[vertical].push_back(temp->val);
    if(temp->left) ds.push({temp->left, vertical - 1});
    if(temp->right) ds.push({temp->right, vertical + 1});
}
  for(auto &x:bucket){
      list<int> temp = x.second;
    for(auto &y:temp){
      res.push_back(y);
    }
  }
  return res;
    }
};
