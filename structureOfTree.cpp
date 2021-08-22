//structure of a ListNode

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    //constructor
    Node(int val) {
        this->val = val;
        left = right = NULL;
    } 
      Node(){}
};