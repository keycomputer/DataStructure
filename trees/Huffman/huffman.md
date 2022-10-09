developed by David Huffman.
Technique of compressing data to reduce its size without losing any of the details.

Huffman Coding-
 

Huffman Coding is a famous Greedy Algorithm.
It is used for the lossless compression of data.
It uses variable length encoding.
It assigns variable length code to all the characters.
The code length of a character depends on how frequently it occurs in the given text.
The character which occurs most frequently gets the smallest code.
The character which occurs least frequently gets the largest code.
It is also known as Huffman Encoding.

Prefix Rule-
 

Huffman Coding implements a rule known as a prefix rule.
This is to prevent the ambiguities while decoding.
It ensures that the code assigned to any character is not a prefix of the code assigned to any other character.

The steps involved in the construction of Huffman Tree are as follows-

 

Step-01:
 

Create a leaf node for each character of the text.
Leaf node of a character contains the occurring frequency of that character.
 

Step-02:
 

Arrange all the nodes in increasing order of their frequency value.
 

Step-03:
 

Considering the first two nodes having minimum frequency,

Create a new internal node.
The frequency of this new node is the sum of frequency of those two nodes.
Make the first node as a left child and the other node as a right child of the newly created node.
 

Step-04:
 

Keep repeating Step-02 and Step-03 until all the nodes form a single tree.
The tree finally obtained is the desired Huffman Tree.
 

Time Complexity-
 

The time complexity analysis of Huffman Coding is as follows-

extractMin( ) is called 2 x (n-1) times if there are n nodes.
As extractMin( ) calls minHeapify( ), it takes O(logn) time.
 

Thus, Overall time complexity of Huffman Coding becomes O(nlogn).

Here, n is the number of unique characters in the given text.

Problem-
 

A file contains the following characters with the frequencies as shown. If Huffman Coding is used for data compression, determine-

Huffman Code for each character
Average code length
Length of Huffman encoded message (in bits)
 

Characters	Frequencies
a	10
e	15
i	12
o	3
u	4
s	13
t	1