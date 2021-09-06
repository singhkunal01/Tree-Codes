// Problem Link: https://leetcode.com/problems/path-sum/

//using extra space and in linear time
void giveSumToEveryNode(Node *root, vector<int> &res, int sum, int targetSum,bool &isTrueOrnot) {
    if(!root) return ;
    res.push_back(root->val);
    if(!root->left and !root->right) {
        sum = accumulate(res.begin(), res.end(),0);
        if(sum == targetSum) {
            isTrueOrnot = true;
            return;
        }
    }
    giveSumToEveryNode(root ->left, res, sum, targetSum,isTrueOrnot);
    giveSumToEveryNode(root ->right, res, sum, targetSum,isTrueOrnot);
    res.pop_back();
}
 bool hasPathSum(Node *root, int targetSum) {
    vector<int> res; bool isTrueOrnot=false;
 if(!root) return true;
 giveSumToEveryNode(root,res,0,targetSum,isTrueOrnot);
 return isTrueOrnot;
 }

//without using extra space ========================EASY APPROACH=====================

 bool hasPathSum(Node *root, int targetSum) {
if(!root) return false;
//if the node is leaf then we can ensure that the value at leaf Node is equal to the target sum in the end hence if it is then return true;
if(!root->left and !root->right) return root->val == targetSum;
//now what we can do is we directly subtract values of every node from targetSum and in the end at leaf node if it is equal to the value of leaf node then definitely it is true else false
return hasPathSum(root->left,targetSum - root->val) or hasPathSum(root->right,targetSum - root->val);
 }
