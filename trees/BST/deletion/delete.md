There are three possible cases to consider deleting a node from BST:

 
Case 1: Deleting a node with no children: remove the node from the tree.

Deletion from BST – Case 1

Case 2: Deleting a node with two children: call the node to be deleted N. Do not delete N. Instead, choose either its inorder successor node or its inorder predecessor node, R. Copy the value of R to N, then recursively call delete on R until reaching one of the first two cases. If we choose the inorder successor of a node, as the right subtree is not NULL (our present case is a node with 2 children), then its inorder successor is a node with the least value in its right subtree, which will have at a maximum of 1 subtree, so deleting it would fall in one of the first 2 cases.

Deletion from BST – Case 2

Case 3: Deleting a node with one child: remove the node and replace it with its child.

Deletion from BST – Case 3

Broadly speaking, nodes with children are harder to delete. As with all binary trees, a node’s inorder successor is its right subtree’s leftmost child, and a node’s inorder predecessor is the left subtree’s rightmost child. In either case, this node will have zero or one child. Delete it according to one of the two simpler cases above.