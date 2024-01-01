
class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key

global count
count = 0

# a def return find the number of nodes in the tree
def count_nodes(node):
    return count_nodes(node.left) + count_nodes(node.right) + 1 if node else 0

def printPreorder(root):
	if root:
		# First print the data of node
		print(root.val, end=" ")

		global count
		if root.left is None and root.right is None:
			count += 1

		else:
			if root.left is not None and root.right is not None:
				if root.left.val is root.val and root.right.val is root.val:
					count += 1
			elif root.left is None:
				if root.right.val is root.val:
					count += 1
			elif root.right is None:
				if root.left.val is root.val:
					count += 1

		# Then recur on left child
		printPreorder(root.left)

		# Finally recur on right child
		printPreorder(root.right)


root = Node(0)
root.left = Node(1)
root.right = Node(0)
root.right.left = Node(1)
root.right.right = Node(0)
root.right.left.left = Node(1)
root.right.left.right = Node(1)

# Function call
print("Preorder traversal of binary tree is")
printPreorder(root)
print("Count:", count)
result = count_nodes(root)
print("dugum sayısı:", result)
