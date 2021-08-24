//iterative solution using 1 stack : TC : O(2N) and SC: O(N)
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    if(root ==  NULL) return res;
    stack<TreeNode *> st;
    TreeNode *currentValue = root;
    while(currentValue != NULL or !st.empty()) {
        if(currentValue != NULL) {
            st.push(currentValue);
            currentValue = currentValue->left;
        }
        else {
            TreeNode *temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                while(!st.empty() and temp == st.top()->right ) {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                }
            }
            else 
                currentValue = temp;
        }
    }
    return res;
}