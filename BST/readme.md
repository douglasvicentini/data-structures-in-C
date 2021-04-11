## Binary Search Tree (BST)

A Binary Search Tree is a type of Binary Tree in which each node located in the left subtree of its parent has a key value less than that of the parent, whereas each node located in the right subtree has a key greater than that of the parent and of its sibling.

In this implementation, the recursive functions use Pre-order traversal mode to traverse the tree.

For example, the following tree

										5
								3				10
							2		4   	7	   	 11
							  		  		  
will be traversed and printed the following way: 5-3-2-4-10-7-11.


