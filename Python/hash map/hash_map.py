# hash_map.py
# ===================================================
# Implement a hash map with chaining
# Author: Emily Addiego
# Due Date: 6/9/20
# ===================================================

class SLNode:
    def __init__(self, key, value):
        self.next = None
        self.key = key
        self.value = value

    def __str__(self):
        return '(' + str(self.key) + ', ' + str(self.value) + ')'


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def add_front(self, key, value):
        """Create a new node and inserts it at the front of the linked list
        Args:
            key: the key for the new node
            value: the value for the new node"""
        new_node = SLNode(key, value)
        new_node.next = self.head
        self.head = new_node
        self.size = self.size + 1

    def remove(self, key):
        """Removes node from linked list
        Args:
            key: key of the node to remove """
        if self.head is None:
            return False
        if self.head.key == key:
            self.head = self.head.next
            self.size = self.size - 1
            return True
        cur = self.head.next
        prev = self.head
        while cur is not None:
            if cur.key == key:
                prev.next = cur.next
                self.size = self.size - 1
                return True
            prev = cur
            cur = cur.next
        return False

    def contains(self, key):
        """Searches linked list for a node with a given key
        Args:
        	key: key of node
        Return:
        	node with matching key, otherwise None"""
        if self.head is not None:
            cur = self.head
            while cur is not None:
                if cur.key == key:
                    return cur
                cur = cur.next
        return None

    def __str__(self):
        out = '['
        if self.head != None:
            cur = self.head
            out = out + str(self.head)
            cur = cur.next
            while cur != None:
                out = out + ' -> ' + str(cur)
                cur = cur.next
        out = out + ']'
        return out


def hash_function_1(key):
    hash = 0
    for i in key:
        hash = hash + ord(i)
    return hash


def hash_function_2(key):
    hash = 0
    index = 0
    for i in key:
        hash = hash + (index + 1) * ord(i)
        index = index + 1
    return hash


class HashMap:
    """
    Creates a new hash map with the specified number of buckets.
    Args:
        capacity: the total number of buckets to be created in the hash table
        function: the hash function to use for hashing values
    """

    def __init__(self, capacity, function):
        self._buckets = []
        for i in range(capacity):
            self._buckets.append(LinkedList())
        self.capacity = capacity
        self._hash_function = function
        self.size = 0


    def clear(self):
        """
        Empties out the hash table deleting all links in the hash table.
        """
        # FIXME: Write this function
        # create new empty buckets and append linkedlist
        self._buckets = []
        for i in range(self.capacity):
            self._buckets.append(LinkedList())

    def get(self, key):
        """
        Returns the value with the given key.
        Args:
            key: the value of the key to look for
        Return:
            The value associated to the key. None if the link isn't found.
        """
        # FIXME: Write this function
        # return none if hash map is empty
        if self.size == 0:
            return None
        # traverse until key is found or end is reached
        else:
            hash = self._hash_function(key)
            hash_index = hash % self.capacity
            cur_bucket = self._buckets[hash_index]
            new_node = cur_bucket.head
        # return value if found, if not, move on to next node
            while new_node is not None:
                if new_node.key == key:
                    return new_node.value
                new_node = new_node.next
            return None


    def resize_table(self, capacity):
        """
        Resizes the hash table to have a number of buckets equal to the given
        capacity. All links need to be rehashed in this function after resizing
        Args:
            capacity: the new number of buckets.
        """
        # FIXME: Write this function
        # make a new set of buckets with new capacity
        new_map = []
        for i in range(capacity):
            new_map.append(LinkedList())
        # traverse old hash map
        for i in range(self.capacity):
            if self._buckets[i].head is not None:
                cur_bucket = self._buckets[i]
                cur_node = cur_bucket.head
        # rehash keys of occupied buckets to new capacity and add to new hashmap
                while cur_node is not None:
                    new_hash = self._hash_function(cur_node.key)
                    new_index = new_hash % capacity
                    new_bucket = new_map[new_index]
                    new_bucket.add_front(cur_node.key, cur_node.value)
                    cur_node = cur_node.next
        # reassign buckets and capacity
        self._buckets = new_map
        self.capacity = capacity



    def put(self, key, value):
        """
        Updates the given key-value pair in the hash table. If a link with the given
        key already exists, this will just update the value and skip traversing. Otherwise,
        it will create a new link with the given key and value and add it to the table
        bucket's linked list.

        Args:
            key: they key to use to has the entry
            value: the value associated with the entry
        """
        # FIXME: Write this function
    # send key through hash function and get index
        hash = self._hash_function(key)
        hash_index = hash % self.capacity
    # find bucket at index
        cur_bucket = self._buckets[hash_index]
    # see if bucket contains key
        if cur_bucket.contains(key):
            new_node = cur_bucket.head
            while new_node is not None:
                if new_node.key == key:
                    new_node.value = value
                    break
                new_node = new_node.next
    # add value to front of list and add to size
        else:
            cur_bucket.add_front(key, value)
            self.size = self.size + 1


    def remove(self, key):
        """
        Removes and frees the link with the given key from the table. If no such link
        exists, this does nothing. Remember to search the entire linked list at the
        bucket.
        Args:
            key: they key to search for and remove along with its value
        """
        # FIXME: Write this function
        # find index key should be at
        hash = self._hash_function(key)
        hash_index = hash % self.capacity
        cur_bucket = self._buckets[hash_index]
        if cur_bucket.head is not None:
            new_node = cur_bucket.head
        # if head node contains key, unlink head node
            if new_node.key == key:
                if new_node.next is not None:
                    cur_bucket.head = new_node.next
                else:
                    cur_bucket.head = None
        # if there are more nodes, traverse and look for key
            else:
                while new_node.next is not None:
                    prev_node = new_node
                    new_node = new_node.next
                    if new_node.key == key:
                        if new_node.next is not None:
                            prev_node.next = new_node.next
                        else:
                            prev_node.next = None
        else:
            return



    def contains_key(self, key):
        """
        Searches to see if a key exists within the hash table

        Returns:
            True if the key is found False otherwise

        """
        # FIXME: Write this function
        # find index for key
        hash = self._hash_function(key)
        hash_index = hash % self.capacity
        # search bucket at index
        cur_bucket = self._buckets[hash_index]
        if cur_bucket.contains(key):
            return True
        else:
            return False

    def empty_buckets(self):
        """
        Returns:
            The number of empty buckets in the table
        """
        # FIXME: Write this function
        empties = 0
        # if head is none, increment empty counter
        for i in range (self.capacity):
            cur_bucket = self._buckets[i]
            if cur_bucket.head is None:
                empties = empties + 1
        # return number of empty buckets
        return empties


    def table_load(self):
        """
        Returns:
            the ratio of (number of links) / (number of buckets) in the table as a float.

        """
        # FIXME: Write this function
        # create counter for links
        links = 0
        # if there are links at an index, increment links counter
        for i in range(self.capacity):
            cur_bucket = self._buckets[i]
            node = cur_bucket.head
            while node is not None:
        # if next node is not none, there is a link
                links = links + 1
                node = node.next
        # return table load in float form
        return float(links / self.capacity)


    def __str__(self):
        """
        Prints all the links in each of the buckets in the table.
        """

        out = ""
        index = 0
        for bucket in self._buckets:
            out = out + str(index) + ': ' + str(bucket) + '\n'
            index = index + 1
        return out

