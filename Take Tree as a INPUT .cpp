//JUST ADD THIS CONSTRUCTOR INTO YOUR FILE AND YOU ARE READY TO TAKE TREE AS A INPUT FOR BETTER UNDESTANDING CHECK THE DEMO BELOW...
Node *makeTree()
{
    int val;
    cin >> val;
    Node *root;
    if(val == -1) 
        return NULL;
  root=new Node(val);
  root->left=makeTree();
  root->right=makeTree();
  return root;
}
//Suppose you want to make this tree but take input from input.txt then-

/*  TYPE THIS INTO YOUR INPUT FILE : 1 2 3 -1 -1 -1 4 -1 10 6 -1 -1 -1         ==> (-1 ~= NULL)

              1
             /   \
            2     4
           /        \
          3          10
                    /
                   6
                   
WHICH MEANS YOU ARE MAKING THIS TYPE OF TREE.
here  -1 means you are not inserting the node anymore hence return null.

*/
