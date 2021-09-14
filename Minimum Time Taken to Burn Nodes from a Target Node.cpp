//This is when the node value is given instead of node's address , so here we have to first find the address of that node after that start applying logic. 
Node* findParent(Node*root, unordered_map<Node*, Node*> &parents,int targetNode) {
    queue<Node*> ds({root});
    Node *res;
    while(!ds.empty()) {
        Node* temp = ds.front(); ds.pop();
        if(temp->val == targetNode) res=temp;
        if(temp->left){ // if the particular node has left then it moves towards left and point its root as its parent node
            parents[temp->left]=temp;
            ds.push(temp->left); //continue move towards left ...
        }
           if(temp->right){  // if the particular node has right then it moves towards right and point its root as its parent node
            parents[temp->right]=temp;
            ds.push(temp->right); //continue move towards right ...
        }
    }
    return res;
}
int minTimeToBurnAllNodesfromAParticularNode(unordered_map<Node *, Node *> &parentsCheck, Node *target) {
    unordered_map<Node *, bool> visited;
    queue<Node *> ds({target});
    visited[target] = true;
    int TimeTaken = 0;
    while(!ds.empty()) {
        int len = size(ds);
        int isSomethingBurn = false; //if something get burned by these nodes only then it will be true and timeTaken will increased otherwise it will be false
        for(int i = 0 ; i < len; i++) {
            Node *targetNode = ds.front();
            ds.pop();
            if(targetNode->left and !visited[targetNode->left]) {
                isSomethingBurn = true;
                ds.push(targetNode->left);
                visited[targetNode->left] = true;
            }
            if(targetNode->right and !visited[targetNode->right]) {
                isSomethingBurn = true;
                ds.push(targetNode->right);
                visited[targetNode->right] = true;
            }
            if(parentsCheck[targetNode] and !visited[parentsCheck[targetNode]]) {
                isSomethingBurn = true;
                ds.push(parentsCheck[targetNode]);
                visited[parentsCheck[targetNode]] = true;
            }
        }
        if(isSomethingBurn) TimeTaken++;
    }
return TimeTaken;
}



//This is when the actual node address is given so no need to find the address of that node just start burning

void findParent(Node*root, unordered_map<Node*, Node*> &parents) {
    queue<Node*> ds({root});
    while(!ds.empty()) {
        Node* temp = ds.front(); ds.pop();
        if(temp->left){ // if the particular node has left then it moves towards left and point its root as its parent node
            parents[temp->left]=temp;
            ds.push(temp->left); //continue move towards left ...
        }
           if(temp->right){  // if the particular node has right then it moves towards right and point its root as its parent node
            parents[temp->right]=temp;
            ds.push(temp->right); //continue move towards right ...
        }
    }
}
int minTimeToBurnAllNodesfromAParticularNode(Node *root, Node *target) {
    unordered_map<Node *, Node *> parentsCheck; //to keep track the nodes and their parents
    findParent(root, parentsCheck);
    unordered_map<Node *, bool> visited;
    queue<Node *> ds({target});
    visited[target] = true;
    int TimeTaken = 0;
    while(!ds.empty()) {
        int len = size(ds);
        int isSomethingBurn = false; //if something get burned by these nodes only then it will be true and timeTaken will increased otherwise it will be false
        for(int i = 0 ; i < len; i++) {
            Node *targetNode = ds.front();
            ds.pop();
            if(targetNode->left and !visited[targetNode->left]) {
                isSomethingBurn = true;
                ds.push(targetNode->left);
                visited[targetNode->left] = true;
            }
            if(targetNode->right and !visited[targetNode->right]) {
                isSomethingBurn = true;
                ds.push(targetNode->right);
                visited[targetNode->right] = true;
            }
            if(parentsCheck[targetNode] and !visited[parentsCheck[targetNode]]) {
                isSomethingBurn = true;
                ds.push(parentsCheck[targetNode]);
                visited[parentsCheck[targetNode]] = true;
            }
        }
        if(isSomethingBurn) TimeTaken++;
    }
return TimeTaken;
}
