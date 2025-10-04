Input Format Instructions:

The program expects the user to input the number of nodes and then input each node's structure
in the format: Parent -> LeftChild -> RightChild

- If a node does not have a left or right child, use '-' (dash) as a placeholder.
- Example input:
    3
    A B C
    B D -
    C - E

This represents:
        A
       / \
      B   C
     /     \
    D       E

The program will then compute the number of nodes at even levels (0, 2, 4, ...).
