# word_count.py
# ===================================================
# Implement a word counter that counts the number of
# occurrences of all the words in a file. The word
# counter will return the top X words, as indicated
# by the user.
# Author: Emily Addiego
# Due Date: 6/9/20
# ===================================================

import re
from hash_map import HashMap

"""
This is the regular expression used to capture words. It could probably be endlessly
tweaked to catch more words, but this provides a standard we can test against, so don't
modify it for your assignment submission.
"""
rgx = re.compile("(\w[\w']*\w|\w)")

def hash_function_2(key):
    """
    This is a hash function that can be used for the hashmap.
    """

    hash = 0
    index = 0
    for i in key:
        hash = hash + (index + 1) * ord(i)
        index = index + 1
    return hash

def top_words(source, number):
    """
    Takes a plain text file and counts the number of occurrences of case insensitive words.
    Returns the top `number` of words in a list of tuples of the form (word, count).

    Args:
        source: the file name containing the text
        number: the number of top results to return (e.g. 5 would return the 5 most common words)
    Returns:
        A list of tuples of the form (word, count), sorted by most common word. (e.g. [("a", 23), ("the", 20), ("it", 10)])
    """

    keys = set()

    ht = HashMap(2500,hash_function_2)

    # This block of code will read a file one word as a time and
    # put the word in `w`. It should be left as starter code.
    with open(source) as f:
        for line in f:
            words = rgx.findall(line)
            for w in words:
    # set up index for hash map
                key = w.lower()
                hash = ht._hash_function(key)
                hash_index = hash % ht.capacity
                cur_bucket = ht._buckets[hash_index]
                new_node = cur_bucket.head
    # if key already exists in hash map, find and increment value
                if ht.contains_key(key):
                    while new_node is not None:
                        if new_node.key == key:
                            new_node.value = new_node.value + 1
                        new_node = new_node.next
    # else, add key to hashmap with value of 1
                else:
                    cur_bucket.add_front(key, 1)
    # make empty list
    list = []
    # add all buckets to list as tuples
    for i in range(ht.capacity):
        bucket = ht._buckets[i]
        if bucket.head is not None:
            new_node = bucket.head
            while new_node is not None:
                list.append((new_node.key, new_node.value))
                new_node = new_node.next
    # Sort list in reverse by key value (word count)
    # Source: https://www.geeksforgeeks.org/python-program-to-sort-a-list-of-tuples-by-second-item/
    list.sort(key = lambda x: x[1], reverse=True)
    # Return list from 0 to user number
    return(list[0:number])




print(top_words("alice.txt",10))  # COMMENT THIS OUT WHEN SUBMITTING TO GRADESCOPE