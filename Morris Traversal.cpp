//================== M O R R I S   T R A V E R S A L   F O R   T H E   I N O R D E R   ==============================

vector<int>  morrisTraversalInorder(Node *root) {
//using linear time and constant space using threaded binary tree
    vector<int> ans;
    Node *currNode = root;
    while(currNode != nullptr) {
        if(currNode->left == NULL) {
            ans.push_back(currNode->val);
            currNode = currNode->right;
        }
        /*if the current node is not null then simply track the address of first left node of
        root node and then traverse the left subtree till then u havenot get the rightmost node in that last subtree */
        else {
            Node *prev = currNode->left;
        //move the prev node till then u do not get the rightmost node in the left subtree
            while(prev->right and prev->right != currNode) {
                prev = prev->right; //to find the rightmost node
            }
        //now there are two conditions if the node founded is NULL or !NULL
            if(prev->right == NULL) {
        //make the thread from that rightmost node to the next root;
                prev->right = currNode;
                currNode = currNode->left;
            }
            else {
                prev->right == NULL; /*cut the thread if prev ->right != NULL means that node is previously connected with the node
                so first the move that side and cut the thread and then move further means move right because u previosly traversed the left node(shown above); */
                ans.push_back(currNode->val);  //in inorder we first move left which we already did in previous code now time to take the node value then after move right.
                currNode = currNode->right;
            }
        }
    }
return ans;
}

//================== M O R R I S   T R A V E R S A L   F O R   T H E   P R E O R D E R   ==============================


vector<int>  morrisTraversalPreorder(Node *root) {
//using linear time and constant space using threaded binary tree
    vector<int> ans;
    Node *currNode = root;
    while(currNode != nullptr) {
        if(currNode->left == NULL) {
            ans.push_back(currNode->val);
            currNode = currNode->right;
        }
        /*if the current node is not null then simply track the address of first left node of
        root node and then traverse the left subtree till then u havenot get the rightmost node in that last subtree */
        else {
            Node *prev = currNode->left;
        //move the prev node till then u do not get the rightmost node in the left subtree
            while(prev->right and prev->right != currNode) {
                prev = prev->right; //to find the rightmost node
            }
        //now there are two conditions if the node founded is NULL or !NULL
            if(prev->right == NULL) {
        //make the thread from that rightmost node to the next root;
                prev->right = currNode;
                ans.push_back(currNode->val); //in preorder we first take the node value then after move left and right.
                currNode = currNode->left;
            }
            else {
                prev->right == NULL; /*cut the thread if prev ->right != NULL means that node is previously connected with the node
                so first the move that side and cut the thread and then move further means move right because u previosly traversed the left node(shown above); */
                currNode = currNode->right;
            }
        }
    }
return ans;
}



/* 
For both the traversals (preorder and inorder)
TC: O(N)
SC: O(1) 
*/
