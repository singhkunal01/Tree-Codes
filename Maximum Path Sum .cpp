int maxHeight(Node *root, int &maxOfTheMax) {
    if(root == NULL) return 0;
    // these two cannot handle the case for values having value < 0;
    /* int lh = maxHeight(root->left,maxOfTheMax);
     int rh = maxHeight(root->right,maxOfTheMax);*/
  
    /*  if there is a node having value which is negative then always return 0 and ignore that path
        so for handling that case instead of two above lines we can add these two lines -*/
    int lh = max( 0, maxHeight(root->left, maxOfTheMax));
    int rh =  max( 0, maxHeight(root->right, maxOfTheMax));
    maxOfTheMax = max(maxOfTheMax, root->val + lh + rh);  //backtracking step ( KING OF THE PROBLEM )
    return root->val + max(lh , rh);
}

int maximumPathSum(Node *root) {
    /*
            -10
          /      \
         9         20
                  /   \
                15      7
    Here MaxSum : 42 via path (15 20 7) considering the path (longest) => -10 20 15 because it returns maxSum as while.
    */
    int maxAns = INT_MIN;
    maxHeight(root, maxAns);
    return maxAns;
}
