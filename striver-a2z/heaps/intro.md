# Heap

A complete Binary tree that satisfy heap property.

### Complete Binary Tree
A complete binary tree is a special type of binary tree where all the levels of the tree are filled completely except the lowest level nodes which are filled from as left as possible.

### Max Heap 
Value of parent node is always greater than the value of its child nodes. 


### Min Heap 
Value of parent node is always smaller than the value of its child nodes.


## Array representation
![max heap](../assets/images/maxHeap.png)

array - `[null, 17, 15, 10, 6, 10, 7]`

If parent Node is at position `i`
then left child is at position `2i`
then right child is at position `2i+1`