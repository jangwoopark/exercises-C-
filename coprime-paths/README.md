You are given an undirected, connected graph, , with  nodes and  edges where . Each node  is initially assigned a value, , that has at most  prime divisors.

You must answer  queries in the form u v. For each query, find and print the number of  pairs of nodes on the path between  and  such that  and the length of the path between  and  is minimal among all paths from  to .

Input Format

The first line contains two space-separated integers describing the respective values of  and .
The second line contains  space-separated integers describing the respective values of .
Each of the  subsequent lines contains two space-separated integers,  and , describing an edge between nodes  and .
Each of the  subsequent lines contains two space-separated integers,  and , describing a query.

Constraints

Output Format

For each query, print an integer on a new line denoting the number of  pairs of nodes on the path between  and  such that  and the length of the path between  and  is minimal among all paths from  to .

Sample Input 0

6 5
3 2 4 1 6 5
1 2
1 3
2 4
2 5
3 6
4 6
5 6
1 1
1 6
6 1
Sample Output 0

9
6
0
3
3
Explanation 0

The diagram below depicts graph  and the  paths specified by each query, as well as the Pair Values for each path in the form :

image

Recall that, for each queried path, we want to find and print the number of  pairs of nodes such that .
