// all traversals in one code TC:O(3*N) and SC:O(4*N)

void allTraversals(Node *root)
{
    if(root ==  NULL) return;
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    while(!st.empty()) {
        auto ite = st.top();
        st.pop();
        if(ite.second == 1) {
            pre.push_back(ite.first->val);
            ite.second++;
            st.push(ite);
            if(ite.first->left != NULL)
                st.push({ite.first->left, 1});
        }
        else if(ite.second == 2) {
            in.push_back(ite.first->val);
            ite.second++;
            st.push(ite);
            if(ite.first->right != NULL)
                st.push({ite.first->right, 1});
        }
        else
            post.push_back(ite.first->val);
    }
    for(auto &x : pre) cout << x << " -> ";
    cout<<newl;
    for(auto &x : in) cout << x << " -> ";
    cout<<newl;
    for(auto &x : post) cout << x << " -> ";
    cout<<newl;
}

// DATE: Aug 25,2021
