White Falcon was amazed by what she can do with heavy-light decomposition on trees. As a resut, she wants to improve her expertise on heavy-light decomposition. Her teacher gave her an another assignment which requires path updates. As always, White Falcon needs your help with the assignment.

You are given a tree with  nodes and each node's value  is initially .

Let's denote the path from node  to node  like this: , where  and , and  and  are connected.

The problem asks you to operate the following two types of queries on the tree:

"1 u v x" Add  to ,  to ,  to , ...,  to .
"2 u v" print the sum of the nodes' values on the path between  and  at modulo .
Input Format

First line cosists of two integers  and  seperated by a space.
Following  lines contains two integers which denote the undirectional edges of the tree.
Following  lines contains one of the query types described above.

Note: Nodes are numbered by using 0-based indexing.

Constraints


Output Format

For every query of second type print a single integer.

Sample Input

3 2
0 1
1 2
1 0 2 1
2 1 2
Sample Output

5
Explanation

After the first type of query, . Hence the answer of the second query is .
