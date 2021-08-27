// ======== MOST IMPORTANT USED IN MANY PROBLEMS =============


class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
     int leftHeight =  maxDepth(root->left);
     int rightHeight = maxDepth(root->right);
    return 1 + maxDepth(leftHeight , rightHeight);
    }
};

// TC: O(N)
// SC: O(N) auxiliary stack space by recursion
