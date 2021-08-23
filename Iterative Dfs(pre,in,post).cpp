//iterative preorder traversal
void iterativePreorder(Node *root){
  if(root==NULL) return;
stack<Node*> st;
st.push(root);
while(!st.empty()){
  root = st.top();
  st.pop();
  cout<<root->val<<" -> ";
  if(root->right!=NULL) st.push(root->right);
  if(root->left!=NULL) st.push(root->left);
}
}

// iterative inorder traversal
void iterativeInorder(Node *root){
stack<Node*> st;
Node *temp = root;
while(true){
  if(temp!=NULL) {
      st.push(temp);
      temp=temp->left;
    }
    else{
      if(st.empty()==1) 
        break;
      temp=st.top();
      st.pop();
      cout<<temp->val<<" -> ";
      temp=temp->right;
    }
}
}

// iterative postorder traversal using 2 stacks
void iterativePostorderBy2Stacks(Node *root){
vector<int> ans;
if(root==NULL)return ;
stack<Node*> st1,st2;
st1.push(root);
while(!st1.empty()){
Node *temp = st1.top();
st1.pop();
st2.push(temp);
if(temp->left!=NULL) st1.push(temp->left);
if(temp->right!=NULL) st1.push(temp->right);
}
while(!st2.empty()){
  ans.push_back(st2.top()->val);
  st2.pop();
}
for(auto &x:ans) cout << x<<" -> ";
}

// iterative postorder traversal using vector and stack
void iterativePostorderByVector(Node *root){
stack<Node*> st1;
vector<int> st2;
st1.push(root);
while(!st1.empty()){
Node *temp = st1.top();
st1.pop();
st2.push_back(temp->val);
if(temp->left!=NULL) st1.push(temp->left);
if(temp->right!=NULL) st1.push(temp->right);
}
reverse(st2.begin(),st2.end());
for(auto &x:st2) cout << x<<" -> ";
}