void helperFunc(TreeNode *root,int level,vector<int> &ans){
        if(!root) return;
        if(level== size(ans)) ans.push_back(root->val);
        helperFunc(root->left,level+1,ans);
        helperFunc(root->right,level+1,ans);

}
vector<int> leftSideView(TreeNode* root) {
        vector<int> res;
        helperFunc(root,0,res);
        return res;
    }
// TC: O(N)
// SC: O(N)
// for more explanation i prefer u to see this for once : https://www.youtube.com/watch?v=KV4mRzTjlAk
