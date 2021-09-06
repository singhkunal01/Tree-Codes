//Problem Link : https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/;

int maximumWidthofABinaryTree(Node *root){
    queue<pair<Node *, int>> qu;
    int maxWidth = INT_MIN;// this is our final answer
    qu.push({root, 0});//initially mark root as 0
    while(!qu.empty())
    {
        int sizeOfQueue = size(qu), firstIdx, lastIdx, minIdx = qu.front().second;
        for(int i = 0 ; i < sizeOfQueue; i++) //iterate all over the queue whatever in it
        {
            auto content = qu.front();
            qu.pop();
            Node *temp = content.first;
            int idx = content.second - minIdx;//whatever we give the id for current node will be subtracted from minIdx value so that we can index in like a way 0,1,2,3 without overflowing.
           if( i == 0) firstIdx = idx;//leftmost value in a particular level
           if( i == sizeOfQueue - 1) lastIdx = idx; //rightmost value in a particular level
           if(temp->left) qu.push({temp->left, 2 * idx + 1});
            if(temp->right) qu.push({temp->right, 2 * idx + 2});
        }
        maxWidth = max(maxWidth, lastIdx - firstIdx + 1);
    }
    return maxWidth;
}
