// PROBLEM LINK :  https://leetcode.com/problems/same-tree/

 bool isSameTree(TreeNode* root, TreeNode* root2) {
          if(!root or !root2) return root == root2; //if the roots are null they always return true because root->val == NULL and root2->val == NULL which is equal
    /*to check whether the both trees are identical or not we have to check only one things i.e., root -> val at left and right simulataneously
    in both of the trees if at any point it returns false hence no need to traverse further THAT's IT .*/
    bool isTrue = (root->val == root2->val);
    bool isTrue2 = isSameTree(root->left, root2->left); //CHECK THE LEFT OF BOTH TREES SIMULTANEOUSLY
    bool isTrue3 = isSameTree(root->right, root2->right); //CHECK THE RIGHT OF BOTH TREES SIMULTANEOUSLY
    return (isTrue and isTrue2 and isTrue3);
    }
