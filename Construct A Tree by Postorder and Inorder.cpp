Node *constructATree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &trackOfNodes)
{
    if(postStart > postEnd or inStart > inEnd) return NULL;
    Node *root = new Node(postorder[postEnd]);
    int inRoot = trackOfNodes[root->val];
    int numberOfNodesLeft = inRoot - inStart;
    root->left = constructATree(postorder, postStart, postStart + numberOfNodesLeft - 1, inorder, inStart, inRoot - 1, trackOfNodes);
    root->right = constructATree(postorder, postStart + numberOfNodesLeft, postEnd - 1, inorder, inRoot + 1, inEnd, trackOfNodes);
    return root;
}
Node *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    if(size(inorder) != size(postorder)) return NULL;
    map<int, int> trackOfNodes;
    for(int i = 0; i < size(inorder); i++) trackOfNodes[inorder[i]] = i;
    Node *root = constructATree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, trackOfNodes);
    return root;
}

//time and space complexity
TC: O(NlogN)
SC: O(N)
