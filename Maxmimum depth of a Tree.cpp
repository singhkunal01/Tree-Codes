
class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

// TC: O(N)
// SC: O(N) auxiliary stack space by recursion
