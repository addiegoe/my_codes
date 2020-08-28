# bst.py
# ===================================================
# Implement a binary search tree that can store any
# arbitrary object in the tree.
# Author: Emily Addiego
# Due Date: 5/21/20
# Sources:
# traversal: https://www.tutorialspoint.com/python_data_structure/python_tree_traversal_algorithms.htm
# ===================================================


class Student:
    def __init__(self, number, name):
        self.grade = number  # this will serve as the object's key
        self.name = name

    def __lt__(self, kq):
        return self.grade < kq.grade

    def __gt__(self, kq):
        return self.grade > kq.grade

    def __eq__(self, kq):
        return self.grade == kq.grade

    def __str__(self):
        if self.grade is not None:
            return str(self.grade)



class TreeNode:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val  # when this is a primitive, this serves as the node's key


class BST:
    def __init__(self, start_tree=None) -> None:
        """ Initialize empty tree """
        self.root = None

        # populate tree with initial nodes (if provided)
        if start_tree is not None:
            for value in start_tree:
                self.add(value)

    def __str__(self):
        """
        Traverses the tree using "in-order" traversal
        and returns content of tree nodes as a text string
        """
        values = [str(_) for _ in self.in_order_traversal()]
        return "TREE in order { " + ", ".join(values) + " }"

    def add(self, val):
        """
        Creates and adds a new node to the BSTree.
        If the BSTree is empty, the new node should added as the root.

        Args:
            val: Item to be stored in the new node
        """
        parent = None
        node = self.root
    # traverse tree, tracking current node and its parent
        while node is not None:
            parent = node
            if val < node.val:
                node = node.left
            else:
                node = node.right
    # if parent is none, node is root
        if parent is None:
            self.root = TreeNode(val)
    # otherwise, insert after parent
        else:
            if val < parent.val:
                parent.left = TreeNode(val)
            else:
                parent.right = TreeNode(val)


    def in_order_traversal(self, cur_node=None, visited=None) -> []:
            """
            Perform in-order traversal of the tree and return a list of visited nodes
            """
            if visited is None:
                # first call to the function -> create container to store list of visited nodes
                # and initiate recursive calls starting with the root node
                visited = []
                self.in_order_traversal(self.root, visited)

            # not a first call to the function
            # base case - reached the end of current subtree -> backtrack
            if cur_node is None:
                return visited

            # recursive case -> sequence of steps for in-order traversal:
            # visit left subtree, store current node value, visit right subtree
            self.in_order_traversal(cur_node.left, visited)
            visited.append(cur_node.val)
            self.in_order_traversal(cur_node.right, visited)
            return visited

    def pre_order_traversal(self, cur_node=None, visited=None) -> []:
        """
        Call helper function to traverse the tree

        Returns:
            A list of nodes in the specified ordering
        """
        #call pre_order function to traverse tree
        if cur_node is None:
            visited = self.pre_order(self.root)
        else:
            visited = self.pre_order(cur_node)
        return visited


    def pre_order(self, cur_node):
        """
        Helper function to perform pre-order traversal of the tree and return a list of visited nodes

        Returns:
            A list of nodes in the specified ordering
        """
        tree = []
        # add nodes to list recursively in preorder position
        if cur_node:
            tree.append(cur_node.val)
            tree = tree + self.pre_order(cur_node.left)
            tree = tree + self.pre_order(cur_node.right)
        return tree



    def post_order_traversal(self, cur_node=None, visited=None) -> []:
        """
        Call helper function to perform post-order traversal of the tree and return a list of visited nodes

        Returns:
            A list of nodes in the specified ordering
        """
        # call helper function to traverse tree
        if cur_node is None:
            visited = self.post_order(self.root)
        else:
            visited = self.post_order(cur_node)
        return visited


    def post_order(self, cur_node):
        """
        Helper function to perform post-order traversal of the tree and return a list of visited nodes

        Returns:
                A list of nodes in the specified ordering
        """
        # add nodes to list recursively in postorder position
        tree = []
        if cur_node:
            tree = self.post_order(cur_node.left)
            tree = tree + self.post_order(cur_node.right)
            tree.append(cur_node.val)
        return tree


    def contains(self, kq):
        """
        Searches BSTree to determine if the query key (kq) is in the BSTree.

        Args:
            kq: query key

        Returns:
            True if kq is in the tree, otherwise False
        """
        node = self.root
        # traverse tree looking for key value
        while node is not None:
            if node.val == kq:
                return True
            elif kq < node.val:
                node = node.left
            else:
                node = node.right
        # return false if value wasn't found
        return False


    def left_child(self, node):
        """
        Returns the left-most child in a subtree.

        Args:
            node: the root node of the subtree

        Returns:
            The left-most node of the given subtree
        """
        curr_node = node
        # traverse to the left until leftmost child is reached
        while curr_node.left:
            curr_node = curr_node.left
        return curr_node


    def remove(self, kq):
        """
        Removes node with key k, if the node exists in the BSTree.

        Args:
            node: root of Binary Search Tree
            kq: key of node to remove

        Returns:
            True if k is in the tree and successfully removed, otherwise False
        """
        # if tree is empty or node DNE, return False
        if self.root is None:
            return False
        elif self.contains(kq) is False:
            return False
        # traverse tree to find node
        else:
            curr_node = self.root
            parent = None
            while curr_node.val != kq:
                parent = curr_node
                if kq < curr_node.val:
                    curr_node = curr_node.left
                else:
                    curr_node = curr_node.right
            # case 1: node has no children
            if curr_node.left is None and curr_node.right is None:
            # control for removal of root node
                if parent is not None:
                    if kq < parent.val:
                        parent.left = None
                    else:
                        parent.right = None
                    curr_node = None
                else:
                    self.root = None
            # case 2: node has only left children
            elif curr_node.left and curr_node.right is None:
                if parent is not None:
                    parent.left = curr_node.left
                    curr_node = None
                else:
                    self.root = curr_node.left
                    self.root.left = None
                    curr_node = None
            # case 3: find in-order successor
            else:
            # successor parent and successor pointers
                s_parent = curr_node
                s_node = curr_node.right
            # traverse left subtree if it exists
                if s_node.left:
                    while s_node.left is not None:
                        s_parent = s_node
                        s_node = s_node.left
                s_node.left = curr_node.left
                if s_node is not curr_node.right:
                    s_parent.left = s_node.right
                    s_node.right = curr_node.right
            # control for removal of root node
                if parent is not None:
                    if s_node.val < parent.val:
                        parent.left = s_node
                    else:
                        parent.right = s_node
                else:
                    self.root = s_node
                curr_node = None
            return True


    def get_first(self):
        """
        Gets the val of the root node in the BSTree.

        Returns:
            val of the root node, return None if BSTree is empty
        """
        if self.root is None:
            return None
        else:
            return self.root.val


    def remove_first(self):
        """
        Removes the val of the root node in the BSTree.

        Returns:
            True if the root was removed, otherwise False
        """
        # use remove function on root node
        if self.root is not None:
            self.remove(self.root.val)



