It has been a prosperous year for King Charles and he is rapidly expanding his empire. In fact, he recently invaded his neighboring country and set up a new kingdom! This kingdom has many cities connected by one-way roads. To ensure higher connectivity, two cities are sometimes directly linked by more than one road.

In the new kingdom, King Charles has made one of the cities his financial capital and another city his warfare capital. He wants a better connectivity between these two capitals. The connectivity of a pair of cities,  and , is defined as the number of different paths from city  to city . A path may use a road more than once if possible. Two paths are considered different if they do not use the same sequence of roads the same number of times.

There are  cities numbered  to  in the new kingdom and  one-way roads. City  is the financial capital and city  is the warfare capital. Determine the number of different paths between cities  and . Since the number may be large, print the result modulo  or .

Note: Two roads may connect the same cities, but they are still considered distinct for path connections.

For example, there are  cities connected by  roads as shown in the following graph:

image

There are two direct paths and one cyclic path. Direct paths are  and  and 4 \rightarrow 53 \leftrightarrow 44 \rightarrow 3$ did not exist, there would be only the two direct paths.

Function Description

Complete the countPaths function in the editor below. It should print your result, modulo  if there are limited paths or INFINITE PATHS if they are unlimited. There is no expected return value.

countPaths has the following parameters:
- n: the integer number of cities
- edges: a 2D integer array where  is the source city and  is the destination city for the directed road 

Input Format

The first line contains two integers  and .
Each of the following  lines contains two space-separated integers that represent source and destination cities for a directed connection.

Constraints

Output Format

Print the number of different paths from city  to city  modulo . If there are infinitely many different paths, print INFINITE PATHS.

Sample Input

Sample Input 0

5 5  
1 2  
2 4  
2 3  
3 4  
4 5
Sample Output 0

2
Explanation 0

image

There are two possible paths from city  to city :


Sample Input 1

5 5  
1 2  
4 2  
2 3  
3 4  
4 5
Sample Output 1

INFINITE PATHS 
Explanation 1

image

The cycle in the graph can be traversed an infinite number of times on the way to city .
