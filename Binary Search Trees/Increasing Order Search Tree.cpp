//first approach using extra space 
//TC: O(N)
//SC: O(N)
class Solution {
public:
void helper(Node *root, vector<int> &inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root->val);
    helper(root->right, inorder);
}
Node *increasingBST(Node *root) {
    vector<int> res;
    helper(root, res);
    Node *newNode = new Node(-1), *curr = newNode;
    for(auto &node : res) {
        newNode->right = new Node(node);
        newNode = newNode->right;
    }
    return curr->right;
}
};


// Without using extra space, this approach is somewhat similar to FLATTEN OF A LINKED LIST
// TC:O(N)
// SC: O(H) height of a tree

class Solution {
public:

Node *curr = NULL;
void helper(Node *root) {
    if(root == NULL) return;
    helper(root->left);
  //these 3 steps are little bit similar to the approach of flatten into a linked list
    root -> left = NULL;
    curr->right = root;
    curr = root;
    helper(root->right);
}
Node *increasingBST(Node *root) {
    Node *newNode = new Node(-1);
    curr = newNode;
    helper(root);
    return newNode->right;
}
};

