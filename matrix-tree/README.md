Sevenkplus has a rooted tree with  vertices. The vertices are labeled from  to .  is the root of the tree. Each vertex  has a weight .
He forms a  matrix  from the tree.  is defined by

where  is the lowest common ancestor of vertex  and vertex .
He wants to calculate the determinant of .
Input Format
First line contains the number of vertices, .
Second line contains  numbers,  separated by a space.
This is followed by  lines. Each line contains two numbers , , denoting that there is an edge between  and .

Output Format
Output one line, the determinant of  modulo .

Constraints

.

Sample Input

3
1 2 3
1 2
1 3
Sample Output

2
Explanation

Then,

.
Hence 

Timelimits
Timelimits for this challenge is given here
