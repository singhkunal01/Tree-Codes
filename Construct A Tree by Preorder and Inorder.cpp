Node *constructATree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &trackOfNodes)
{
    if(preStart > preEnd or inStart > inEnd) return NULL;
    Node *root = new Node(preorder[preStart]);
    int inRoot = trackOfNodes[root->val];
    int numberOfNodesLeft = inRoot - inStart;
    root->left = constructATree(preorder, preStart + 1, preStart + numberOfNodesLeft, inorder, inStart, inRoot - 1, trackOfNodes);
    root->right = constructATree(preorder, preStart + numberOfNodesLeft+1, preEnd, inorder, inRoot + 1, inEnd, trackOfNodes);
    return root;
}
Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(size(inorder) != size(preorder)) return NULL;
    map<int, int> trackOfNodes;
    for(int i = 0; i < size(inorder); i++) trackOfNodes[inorder[i]] = i;
    Node *root = constructATree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, trackOfNodes);
    return root;
}

TC: O(NlogN) //logn for maps
SC: O(N) //+ O(N) auxiliary space
