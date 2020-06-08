Ichigo is receiving special training from Kisuke Urahara to beat Aizen. This time, Kisuke took (P * Q * R) identical cubes and made them into a big box of dimensions P x Q x R. Moreover, it happened quite by chance that P, Q, R were all pairwise coprime, that is, gcd(P, Q) = gcd(Q, R) = gcd(R, P) = 1 where gcd(X, Y) is the greatest integer dividing both X and Y. He then asked Ichigo to cut the box into two pieces with a single slice. Ichigo used a Getsuga Tenshou in his hollow form on the box and sliced it into two parts completely.

His slice was such that for a corner vertex X of the box, if A, B, C are the vertices of the box adjacent to X, then Ichigo's slice was a plane passing through A, B, C as given in the picture below. Now Kisuke is wondering what is the number of cubes that were cut into two parts. Since the answer can be huge, output it modulo (109 + 7).

cube
Input Format:

Line 1: T
T - Number of test cases.
Lines 2 to T+1: P Q R
P, Q, R - the dimensions of the box

Output Format:

For each test case, print a single integer in a new line that is the number of cubes that were cut by Ichigo modulo (109 + 7).

Constraints:

1 <= T <= 1000
1 <= P, Q, R <= 1012
P, Q, R are pairwise coprime

Sample Input:

3
1 1 1
2 1 3
5 3 2
Sample Output:

1
5
15
Explanation:

In the first test case, we have a single cube. And when Ichigo slices it, that single cube is sliced. So, the answer is 1.

In the second test case, we have a (2 x 1 x 3) cuboid. Then, when Ichigo takes an arbitrary vertex X and slice the cuboid as explained, then the cube which contains the vertex diagonally(body diagonal) opposite X in the cuboid is not cut, every other cube is cut. So, 5 cubes are cut.
