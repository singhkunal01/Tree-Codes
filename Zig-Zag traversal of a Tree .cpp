/* TC : o(N)
SC : o(N)  */

// In this problem a small change can effect the execution time

// 1. BY USING EVEN ODD TRACK i.e., IF THE COUNTER(LEVEL NUMBER ) IS ODD THEN REVERSE THEM OTHER WISE INSERT IT AS THEY ARE (IN SIMILAR ORDER)
 vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
     vector<vector<int>> ans;
     if(root == NULL) return ans;
     queue<TreeNode *> bucket;
     bucket.push(root);
 //    bool flag = false;
     int checkEvenOrOdd = 0;
     while(!bucket.empty()) {
         int sz = bucket.size();
         vector<int> everyLevel;
         for(int i = 0; i < sz; i++) {
             TreeNode *eachNode = bucket.front();
             bucket.pop();
             if(eachNode->left != NULL) bucket.push(eachNode->left);
             if(eachNode->right != NULL) bucket.push(eachNode->right);
             everyLevel.push_back(eachNode->val);
         }
         if(checkEvenOrOdd & 1)  reverse(everyLevel.begin(), everyLevel.end());
         ans.push_back(everyLevel);
         checkEvenOrOdd++;
 //         flag = !flag;
     }
     return ans;
 }

/* 2. BY USING FLAG (BOOLEAN) WE CAN SWITCH IT ACCORIDING TO THE LEVEL i.e., IF THE LEVEL IS ODD THEN FLAG WILL BE TRUE AND REVERSE THE VECTOR OTHERWISE FLAG == FALSE 
AND INSERT IT IN THE SAME MANNER..

THIS CAN BE DONE VIA A SIMPLE CHECK =============  flag = !flag */

 vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
     vector<vector<int>> ans;
     if(root == NULL) return ans;
     queue<TreeNode *> bucket;
     bucket.push(root);
    bool flag = false;
     while(!bucket.empty()) {
         int sz = bucket.size();
         vector<int> everyLevel;
         for(int i = 0; i < sz; i++) {
             TreeNode *eachNode = bucket.front();
             bucket.pop();
             if(eachNode->left != NULL) bucket.push(eachNode->left);
             if(eachNode->right != NULL) bucket.push(eachNode->right);
             everyLevel.push_back(eachNode->val);
         }
         if(flag)  reverse(everyLevel.begin(), everyLevel.end());
         ans.push_back(everyLevel);
         flag = !flag;
     }
     return ans;
 }

// 3. WITHOUT USING REVERSE FUNCTION WE CAN DO IT USING MANUAL REVERSE WHILE TRAVERSING WE CAN INSERT IT BY THE INDEXING i.e., LEFT TO RIGHT OR RIGHT TO LEFT


 vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
     vector<vector<int>> ans;
     if(root == NULL) return ans;
     queue<TreeNode *> bucket;
     bucket.push(root);
    bool flag = false;
     while(!bucket.empty()) {
         int sz = bucket.size();
         vector<int> everyLevel(sz);
         for(int i = 0; i < sz; i++) {
             TreeNode *eachNode = bucket.front();
             bucket.pop();
             int idx = (flag == false) ? i:(size - 1 - i ); 
// THIS ABOVE LINE (75) IS THE MAIN LOGIC WHICH MEANS IF THE FLAG IS FALSE THEN DO NOT MAKE ANY CHANGE IN THE FINAL VECTOR AND INSERT IT FROM LEFT TO RIGHT OTHERWISE INSERT IT FROM RIGHT TO LEFT IN REVERSE ORDER i.e., size - 1 - i ;
             everyLevel[idx]=eachNode -> val;
             if(eachNode->left != NULL) bucket.push(eachNode->left);
             if(eachNode->right != NULL) bucket.push(eachNode->right);
         }
         ans.push_back(everyLevel);
         flag = !flag;  //to switching the flag on and off;
     }
     return ans;
 }
