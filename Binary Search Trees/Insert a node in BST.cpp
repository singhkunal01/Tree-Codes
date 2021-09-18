//This will always attach the node in leaf of the tree it is simple bcz this will not contains duplicate

// -----------------------------------------  M Y    O W N    A P P R O A C H -------------------------


 Node *insertIntoBST(Node *root, int insertVal) {
     if(!root) return new Node(insertVal);
     Node *prev = NULL;
     Node *curr = root;
     while(curr) {
         if(curr->val < insertVal  ) {
             prev = curr;
/* PREV always keep track of prev node bcz at any instant root becomes null at that time it contains prev address and 
that node is our insertion point where we have to insert the node,GIVEN BELOW at line 22 and 23*/
             curr = curr->right;
         }
         else if(curr->val > insertVal ) {
             prev = curr;
             curr = curr->left;
         }
     }
     if(prev->val < insertVal  ) prev->right = new Node(insertVal);
     if(prev->val > insertVal ) prev->left = new Node(insertVal);
     // preorder(root);
     return root;
 }

// -----------------------------------------  A N O T H E R   S I M I L A R   A P P R O A C H -------------------------


 Node *insertIntoBST(Node *root, int insertVal) {
     if(!root) return new Node(insertVal);
     Node *curr = root;
     while(true) {
         if(curr->val <= insertVal  ) {
            if (curr->right) 
              curr = curr->right;
         else {
            curr->right = new Node(insertVal);
            break;
         }
     }
      else {
            if (curr->left) 
              curr = curr->left;
         else {
            curr->left = new Node(insertVal);
            break;
         }
     }
 }
     return root;
 }

//TC: O(logn)
//SC:O(1)
