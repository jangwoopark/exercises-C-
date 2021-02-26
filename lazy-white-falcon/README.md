White Falcon just solved the data structure problem below using heavy-light decomposition. Can you help her find a new solution that doesn't require implementing any fancy techniques?

There are

types of query operations that can be performed on a tree:

    1 u x: Assign 

as the value of node
.
2 u v: Print the sum of the node values in the unique path from node
to node

    .

Given a tree with
nodes where each node's value is initially , execute

queries.

Input Format

The first line contains
space-separated integers, and , respectively.
The subsequent lines each contain space-separated integers describing an undirected edge in the tree.
Each of the

subsequent lines contains a query you must execute.

Constraints

It is guaranteed that the input describes a connected tree with
nodes.
Nodes are enumerated with

    -based indexing.

Output Format

For each type-

query, print its integer result on a new line.

Sample Input

3 3
0 1
1 2
1 0 1
1 1 2
2 0 2

Sample Output

3

Explanation

[Lazy White Falcon Expl.png]

After the first
queries, the value of node and the value of node . The third query requires us to print the sum of the node values in the path from nodes to , which is . Thus, we print on a new line. 
