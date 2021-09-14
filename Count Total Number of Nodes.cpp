int nodesInLeft(Node *root){
    int leftNodes=0;
    while(root){
        leftNodes++;
        root = root->left;
    }
    return leftNodes;
}

int nodesInRight(Node *root){
    int rightNodes=0;
    while(root){
        rightNodes++;
        root = root->right;
    }
    return rightNodes;
}

int countTotalNodes(Node *root){
if(!root) return 0;
int leftNodes = nodesInLeft(root); //from nodesInLeft we got the height of left subtree.
int rightNodes = nodesInRight(root);//from nodesInRight we got the height of right subtree.
// an important check for full binary tree if the tree is full then we know that the height of tree will be: 2^(number of nodes) - 1;
if(leftNodes == rightNodes) return (1<<leftNodes)-1; // tree can be full only and only when the leftHeight of each subtree is equal to the rightNodes of each subtree
return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

TC:O(logn)^2 
SC:O(N) //auxiliary
