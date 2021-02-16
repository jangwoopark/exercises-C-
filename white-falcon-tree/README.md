White Falcon has a tree with  nodes. Each node contains a linear function. Let's denote by  the linear function contained in the node .

Let's denote the path from node  to node  like this: , where  and , and  and  are connected.

White Falcon also has  queries. They are in the following format:

    . Assign  as the function of all the nodes on the path from  to , i.e.,  is changed to  where  is the path from  to .

   . Calculate  modulo 

Input Format

The first line contains , the number of nodes. The following  lines each contain two integers  and  that describe the function .

Following  lines contain edges of the tree.

The next line contains , the number of queries. Each subsequent line contains one of the queries described above.

Output Format

For every query of the second kind, print one line containing an integer, the answer for that query.

Constraints
 (Number of nodes)
 (Number of queries)

Sample Input

2
1 1
1 2
1 2
2
1 2 2 1 1
2 1 2 1
Sample Output

3
Explanation
