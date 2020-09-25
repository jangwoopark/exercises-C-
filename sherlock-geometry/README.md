Watson gives a circle and a triangle in a 2-dimensional plane to Sherlock. Sherlock has to tell if they intersect/touch each other.
The circle is centered at  and has radius .

Input Format
The first line contains , the number of test cases.
Each test case consists of ,  and  in one line.
The next three lines each contains  denoting the vertices of the triangle.

Output Format
For each test case, print YES if the triangle touches or intersects the circle; otherwise, print NO.

Constraints




Note: There will be no degenerate triangles (i.e. triangles with area 0)

Sample Input

2
0 0 10
10 0
15 0
15 5
0 0 10
0 0
5 0
5 5
Sample Output

YES
NO
Explanation
image image
In the first case, the triangle is touching the circle. In the second case, it neither touches nor intersects the circle.
