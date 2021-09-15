
string serializeTheTree(Node *root)
{
//using bfs traversal
    string st = "";
    if(!root) return st;
    queue<Node *> ds({root});
    while(!ds.empty())
    {
        Node *currNode = ds.front();
        ds.pop();
        if(!currNode) st += "#,";
        else st += to_string(currNode->val) + ',';
        if(currNode)
        {
            ds.push(currNode->left);
            ds.push(currNode->right);
        }
    }
    return st;
}
Node *deserializeTheTree(string &data)
{
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node *> ds({root});
    while(!ds.empty())
    {
        Node *curr = ds.front();
        ds.pop();
        getline(s, str, ',');
        if(str == "#") curr->left == NULL;
        else
        {
            Node *leftNode = new Node(stoi(str));
            curr->left = leftNode;
            ds.push(leftNode);
        }
        getline(s, str, ',');
        if(str == "#") curr->right == NULL;
        else
        {
            Node *rightNode = new Node(stoi(str));
            curr->right = rightNode;
            ds.push(rightNode);
        }
    }
    return root;
}

// TC: O(N)
// SC: O(N)
